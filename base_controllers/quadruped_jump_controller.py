from __future__ import print_function

import copy
import os

import rospy as ros
import sys
import time
import threading

import numpy as np
import pinocchio as pin
# utility functions
from  scipy.linalg import block_diag
from base_controllers.utils.pidManager import PidManager
from base_controllers.base_controller import BaseController
from base_controllers.utils.math_tools import *
from base_controllers.utils.optimTools import quadprog_solve_qp

from base_controllers.components.inverse_kinematics.inv_kinematics_quadruped import InverseKinematics
from base_controllers.components.leg_odometry.leg_odometry import LegOdometry
from termcolor import colored

import base_controllers.params as conf

from scipy.io import savemat

#gazebo messages
from gazebo_ros import gazebo_interface

from gazebo_msgs.msg import ContactsState
from sensor_msgs.msg import JointState
from nav_msgs.msg import Odometry
from geometry_msgs.msg import Vector3
from sensor_msgs.msg import Imu
from ros_impedance_controller.msg import EffortPid

from base_controllers.components.imu_utils import IMU_utils

import datetime

from base_controllers.quadruped_controller import Controller

class QuadrupedJumpController(Controller):
    def __init__(self, robot_name="hyq", launch_file=None):
        super(QuadrupedJumpController, self).__init__(robot_name, launch_file)


    #####################
    # OVERRIDEN METHODS #
    #####################
    # initVars
    # logData
    # startupProcedure


    def computeHeuristicSolutionBezierLinear(self, com_0, com_lo, comd_lo, T_th):
        self.bezier_weights_lin = np.zeros([3, 4])
        comd_0 = np.zeros(3)
        self.bezier_weights_lin = np.zeros([3, 4])
        self.bezier_weights_lin[:, 0] = com_0
        self.bezier_weights_lin[:, 1] = (comd_0*(T_th/3.)) + com_0
        self.bezier_weights_lin[:, 2] = com_lo - (comd_lo*(T_th/3.))
        self.bezier_weights_lin[:, 3] = com_lo

    def computeHeuristicSolutionBezierAngular(self, eul_0, eul_lo, euld_lo, T_th):
        self.bezier_weights_ang = np.zeros([3, 4])
        euld_0 = np.zeros(3)
        self.bezier_weights_ang = np.zeros([3, 4])
        self.bezier_weights_ang[:, 0] = eul_0
        self.bezier_weights_ang[:, 1] = (euld_0*(T_th/3.)) + eul_0
        self.bezier_weights_ang[:, 2] = eul_lo - (euld_lo*(T_th/3.))
        self.bezier_weights_ang[:, 3] = eul_lo


    def evalBezier(self, t_, T_th):
        com = np.array(self.Bezier3(self.bezier_weights_lin,t_,T_th))
        comd = np.array(self.Bezier2(self.bezier_weights_lin,t_,T_th))
        eul = np.array(self.Bezier3(self.bezier_weights_ang,t_,T_th))
        euld = np.array(self.Bezier2(self.bezier_weights_ang,t_,T_th))
        Jb = p.computeJcb(p.W_contacts, com)

        #map base twist into feet relative vel (wrt com/base)
        omega_b = self.math_utils.Tomega(eul).dot(euld)
        W_baseTwist = np.hstack((comd, omega_b))
        W_feetRelVelDes = -Jb.dot(W_baseTwist)
        w_R_b_des = self.math_utils.eul2Rot(eul)

        qd_des = np.zeros(12)
        q_des = np.zeros(12)
        fbjoints = pin.neutral(self.robot.model)
        w_J = self.u.listOfArrays(4, np.zeros((3, 3)))
        #integrate relative Velocity
        for leg in range(self.robot.nee):
            self.W_feetRelPosDes[leg] += W_feetRelVelDes[3 * leg:3 * (leg+1)]*self.dt
            #now we can do Ik
            q_des[3 * leg:3 * (leg+1)], isFeasible = self.IK.ik_leg(w_R_b_des.T.dot(self.W_feetRelPosDes[leg]),
                                                   self.leg_names[leg],
                                                   self.legConfig[self.leg_names[leg]][0],
                                                   self.legConfig[self.leg_names[leg]][1])
            #for joint velocity we need to recompute the Jacobian (in the world frame) for the computed joint position q_des
            # you need to fill in also the floating base part
            quat_des = pin.Quaternion(w_R_b_des)
            fbjoints[:3] = com
            fbjoints[3:7] = np.array([quat_des.w, quat_des.x, quat_des.y, quat_des.z])
            fbjoints[7:] = q_des
            w_J[leg] = self.robot.frameJacobian(fbjoints,  self.robot.model.getFrameId(self.ee_frames[leg]),
                                     update=True,  ref_frame=pin.ReferenceFrame.LOCAL_WORLD_ALIGNED)[:3, 6 + leg * 3:6 + leg * 3 + 3]

            #TODO double check this has some issues
            #qd_des[3 * leg:3 *(leg+1)] = np.linalg.pinv(w_J[leg]).dot(W_feetRelVelDes[3 * leg:3 *(leg+1)])


            #TODO raise front legs and compute Jb for a subset of lefs
        # print(W_feetRelVelDes)
        # print(self.W_feetRelPosDes)
        return q_des, qd_des #com, comd, comdd

    def plotTrajectoryBezier(self):
        # plot com intermediate positions
        for blob in range(len(self.intermediate_com_position)):
            self.ros_pub.add_marker(self.intermediate_com_position[blob], color=[
                blob * 1. / self.number_of_blobs, blob * 1. / self.number_of_blobs, blob * 1. / self.number_of_blobs],
                                 radius=0.05)

    def computeTrajectoryBezier(self, T_th):
        self.number_of_blobs = 30
        t = np.linspace(0, T_th, self.number_of_blobs)
        self.intermediate_com_position = []
        for blob in range(self.number_of_blobs):
            self.intermediate_com_position.append(
                self.Bezier3(self.bezier_weights_lin, t[blob], T_th))

    def bernstein_pol(self,k,n,x):
        v = (np.math.factorial(n)/(np.math.factorial(k)*(np.math.factorial(n-k))))*np.power(x,k)*np.power(1-x,n-k)
        return v

    def Bezier3(self,w,t_ex,t_th):
        t = t_ex/t_th
        return  w[:,0]*self.bernstein_pol(0,3,t)+\
                w[:,1]*self.bernstein_pol(1,3,t)+\
                w[:,2]*self.bernstein_pol(2,3,t)+\
                w[:,3]*self.bernstein_pol(3,3,t)

    def Bezier2(self,w,t_ex,t_th):
        t = t_ex/t_th
        return ((w[:,1]-w[:,0]))*(3/t_th)*self.bernstein_pol(0,2,t)+\
            ((w[:,2]-w[:,1]))*(3/t_th)*self.bernstein_pol(1,2,t)+\
            ((w[:,3]-w[:,2]))*(3/t_th)*self.bernstein_pol(2,2,t)

    def computeJcb(self, feetW, com):
        Jb = np.zeros([3 * self.robot.nee, 6])  # Newton-Euler matrix
        for leg in range(self.robot.nee):
            start_row = 3 * leg
            end_row = 3 * (leg + 1)
            # ---> linear part
            # identity matrix (I avoid to rewrite zeros)
            Jb[start_row:end_row, :3] = np.identity(3)
            # ---> angular part
            # all in a function
            Jb[start_row:end_row, 3:]= -pin.skew(feetW[leg] - com)
        return Jb

if __name__ == '__main__':
    p = QuadrupedJumpController('go1')
    world_name = 'fast.world'
    use_gui = True
    try:
        #p.startController(world_name='slow.world')
        p.startController(world_name=world_name,
                          use_ground_truth_pose=True,
                          use_ground_truth_contacts=False,
                          additional_args=['gui:='+str(use_gui),
                                           'go0_conf:=standDown'])
        p.startupProcedure()
        #initial pose
        #linear
        com_lo = np.array([0.2,0.,0.4])
        comd_lo = np.array([1.2, 0.,1.2])
        com_0 = p.basePoseW[:3]
        #angular
        eul_0 = p.basePoseW[3:]
        eul_lo = np.array([0., -0.2, 0.])
        euld_lo = np.array([0., 0.1, 0.])
        p.T_th = 1.0
        p.computeHeuristicSolutionBezierLinear(com_0, com_lo, comd_lo,p.T_th)
        p.computeHeuristicSolutionBezierAngular(eul_0, eul_lo, euld_lo, p.T_th)

        #this is for visualization
        p.computeTrajectoryBezier(p.T_th)
        startTrust  = p.time
        p.trustPhaseFlag = True

        stance_flag = np.array([0,1,2,3])
        #print(p.computeJcb(p.W_contacts, com_0))
        #reset integration of feet
        p.W_feetRelPosDes = np.copy(p.W_contacts - com_0)
        p.setSimSpeed(dt_sim=0.001, max_update_rate=200, iters=1500)
        while not ros.is_shutdown():
            p.updateKinematics()
            if (p.time > startTrust):
                 # compute joint reference
                if (p.trustPhaseFlag):
                    t = p.time - startTrust
                    p.q_des, p.qd_des = p.evalBezier(t, p.T_th)
                    if p.time >= (startTrust + p.T_th):
                        p.trustPhaseFlag = False
                        #we se this here to have enough retraction (important)
                        p.q_des = p.qj_0
                        p.qd_des = np.zeros(12)
                        print("thrust completed!")

            p.plotTrajectoryBezier()
            p.visualizeContacts()
            p.tau_ffwd = p.gravityCompensation()
            p.send_command(p.q_des, p.qd_des, p.tau_ffwd)

    except (ros.ROSInterruptException, ros.service.ServiceException):
        ros.signal_shutdown("killed")
        p.deregister_node()
        
    from base_controllers.utils.common_functions import *

    if conf.plotting:
        plotJoint('position', time_log=p.time_log, q_log=p.q_log, q_des_log=p.q_des_log, sharex=True, sharey=False,
                  start=0, end=-1)
        plotFrame('position', time_log=p.time_log, des_Pose_log=p.comPoseW_des_log, Pose_log=p.comPoseW_log,
                  title='CoM', frame='W', sharex=True, sharey=False, start=0, end=-1)