# -*- coding: utf-8 -*-
"""
Created on Thu Apr  2 18:07:44 2020

@author: mfocchi
"""
import os
import psutil
#from pinocchio.visualize import GepettoVisualizer
from custom_robot_wrapper import RobotWrapper
import numpy as np
import matplotlib.pyplot as plt
import sys

# Print options 
np.set_printoptions(precision = 3, linewidth = 200, suppress = True)
np.set_printoptions(threshold=np.inf)
sys.dont_write_bytecode = True

from urdf_parser_py.urdf import URDF
#make plot interactive
plt.ion()
plt.close() 

REF_SPHERE_RADIUS = 0.03
EE_SPHERE_COLOR  = (1, 0.5, 0, 0.5)
EE_REF_SPHERE_COLOR  = (1, 0, 0, 0.5)

def importDisplayModel(DISPLAY, DISPLAY_FLOOR):
    
    
    # Import the model
    ERROR_MSG = 'You should set the environment variable UR5_MODEL_DIR to something like "$DEVEL_DIR/install/share"\n';
    path      = os.environ.get('UR5_MODEL_DIR', ERROR_MSG)
    urdf      = path + "/ur_description/urdf/ur5_modified.urdf";
    srdf      = path + '/ur5_description/srdf/ur5_modified.srdf'
    robot = RobotWrapper.BuildFromURDF(urdf, [path,srdf ])
                
  
    if DISPLAY:
        import commands
        import gepetto
        from time import sleep
                                
#        for proc in psutil.process_iter():
#                                        
#         
#         # check whether the process name matches
#        # print(proc.name())
#    
#            if (proc.name() == 'gepetto-gui'):
#                print('killing ', proc.name())
#                proc.kill()         
 
        
        l = commands.getstatusoutput("ps aux |grep 'gepetto-gui'|grep -v 'grep'|wc -l")
        if int(l[1]) == 0:
            os.system('gepetto-gui &')
        sleep(1)
        gepetto.corbaserver.Client()
        robot.initViewer(loadModel=True)
        gui = robot.viewer.gui
        gui.addSphere('world/ee', 0.05, EE_SPHERE_COLOR)
        if(DISPLAY_FLOOR):
            gui.createSceneWithFloor('world')
            gui.setLightingMode('world/floor', 'ON')
        robot.displayCollisions(False)
        robot.displayVisuals(True)
                                                                            
    #get urdf from ros just in case you need
    #robot_urdf_ros = URDF.from_parameter_server() 
                                                                                                                                                                                                                                                                                                                
    
    return robot                    

def plotJoint(name, figure_id, time_log, q_log, q_des_log, qd_log, qd_des_log, qdd_log, qdd_des_log, tau_log):
    if name == 'position':
        plot_var_log = q_log
        plot_var_des_log = q_des_log
    elif name == 'velocity':
        plot_var_log = qd_log
        plot_var_des_log  = qd_des_log
    elif name == 'acceleration':
        plot_var_log = qdd_log
        plot_var_des_log  = qdd_des_log
    elif name == 'torque':
        plot_var_log = tau_log
        plot_var_des_log  = tau_log                                
    else:
       print("wrong choice")                                    

    lw_des=7
    lw_act=4          
                
            #neet to transpose the matrix other wise it cannot be plot with numpy array    
    fig = plt.figure(figure_id)
    fig.suptitle(name, fontsize=20)             
    plt.subplot(3,2,1)
    plt.ylabel("1 - Shoulder Pan")    
    plt.plot(time_log, plot_var_des_log[0,:].T, linestyle='-', lw=lw_des,color = 'red')
    plt.plot(time_log, plot_var_log[0,:].T,linestyle='-', lw=lw_act,color = 'blue')
    plt.grid()
                
    plt.subplot(3,2,2)
    plt.ylabel("2 - Shoulder Lift")
    plt.plot(time_log, plot_var_des_log[1,:].T, linestyle='-', lw=lw_des,color = 'red', label="q_des")
    plt.plot(time_log, plot_var_log[1,:].T,linestyle='-',lw=lw_act, color = 'blue', label="q")
    plt.legend(bbox_to_anchor=(-0.01, 1.115, 1.01, 0.115), loc=3, mode="expand")
    plt.grid()
    
    plt.subplot(3,2,3)
    plt.ylabel("3 - Elbow")    
    plt.plot(time_log, plot_var_des_log[2,:].T,linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, plot_var_log[2,:].T,linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()    
    
    plt.subplot(3,2,4)
    plt.ylabel("4 - Wrist 1")    
    plt.plot(time_log, plot_var_des_log[3,:].T,linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, plot_var_log[3,:].T,linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    
    plt.subplot(3,2,5)
    plt.ylabel("5 - Wrist 2")    
    plt.plot(time_log, plot_var_des_log[4,:].T,linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, plot_var_log[4,:].T,linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    
    plt.subplot(3,2,6)
    plt.ylabel("6 - Wrist 3") 
    plt.plot(time_log, plot_var_des_log[5,:].T,linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, plot_var_log[5,:].T,linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
                

                
def plotEndeff(name, figure_id, time_log, x_log, x_des_log=None, xd_log=None, xd_des_log=None, f_log=None):
    plot_var_des_log = None
    if name == 'position':
        plot_var_log = x_log
        if   (x_des_log is not None):                                
           plot_var_des_log = x_des_log                            
    elif name == 'force':
        plot_var_log = f_log
    elif  name == 'velocity':    
        plot_var_log = xd_log
        if   (xd_des_log is not None):                                
             plot_var_des_log = xd_des_log                                    
    else:
       print("wrong choice")                    
       
    lw_act=4  
    lw_des=7
                    
    fig = plt.figure(figure_id)
    fig.suptitle(name, fontsize=20)                   
    plt.subplot(3,1,1)
    plt.ylabel("end-effector x")
    if   (plot_var_des_log is not None):
         plt.plot(time_log, plot_var_des_log[0,:].T, lw=lw_des, color = 'red')                    
    plt.plot(time_log, plot_var_log[0,:].T, lw=lw_act, color = 'blue')
    plt.grid()
    
    plt.subplot(3,1,2)
    plt.ylabel("end-effector y")    
    if   (plot_var_des_log is not None):
         plt.plot(time_log, plot_var_des_log[1,:].T, lw=lw_des, color = 'red')                    
    plt.plot(time_log, plot_var_log[1,:].T, lw=lw_act, color = 'blue')
    plt.grid()
    
    plt.subplot(3,1,3)
    plt.ylabel("end-effector z")    
    if   (plot_var_des_log is not None):
        plt.plot(time_log, plot_var_des_log[2,:].T, lw=lw_des, color = 'red')                                        
    plt.plot(time_log, plot_var_log[2,:].T, lw=lw_act, color = 'blue')
    plt.grid()
      
    
def plotCoM(name, figure_id, time_log, des_basePoseW, basePoseW, des_baseTwistW, baseTwistW, des_baseAccW, wrenchW):
    plot_var_log = None
    if name == 'position':
        plot_var_log = basePoseW
        plot_var_des_log = des_basePoseW
    elif name == 'velocity':
        plot_var_log = baseTwistW
        plot_var_des_log  = des_baseTwistW
    elif name == 'acceleration':
        plot_var_des_log  = des_baseAccW    
    elif name == 'wrench':
        plot_var_des_log  = wrenchW                                    
    else:
       print("wrong choice")                                    

    lw_des=7
    lw_act=4          
                
    #neet to transpose the matrix other wise it cannot be plot with numpy array    
    fig = plt.figure(figure_id)
    fig.suptitle(name, fontsize=20)             
    plt.subplot(3,2,1)
    plt.ylabel("CoM X")    
    plt.plot(time_log, plot_var_des_log[0,:], linestyle='-', lw=lw_des,color = 'red')
    if   (plot_var_log is not None):                
        plt.plot(time_log, plot_var_log[0,:],linestyle='-', lw=lw_act,color = 'blue')
    plt.grid()
                
    plt.subplot(3,2,3)
    plt.ylabel("CoM Y")
    plt.plot(time_log, plot_var_des_log[1,:], linestyle='-', lw=lw_des,color = 'red', label="q_des")
    if   (plot_var_log is not None):    
        plt.plot(time_log, plot_var_log[1,:],linestyle='-',lw=lw_act, color = 'blue', label="q")
    plt.legend(bbox_to_anchor=(-0.01, 1.115, 1.01, 0.115), loc=3, mode="expand")
    plt.grid()
    
    plt.subplot(3,2,5)
    plt.ylabel("CoM Z")    
    plt.plot(time_log, plot_var_des_log[2,:],linestyle='-',lw=lw_des,color = 'red')
    if   (plot_var_log is not None):    
       plt.plot(time_log, plot_var_log[2,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()    
    
    plt.subplot(3,2,2)
    plt.ylabel("$\phi$", fontsize=10)   
    plt.plot(time_log, plot_var_des_log[3,:],linestyle='-',lw=lw_des,color = 'red')
    if   (plot_var_log is not None):    
        plt.plot(time_log, plot_var_log[3,:].T,linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    
    plt.subplot(3,2,4)
    plt.ylabel("$\theta$", fontsize=10)   
    plt.plot(time_log, plot_var_des_log[4,:],linestyle='-',lw=lw_des,color = 'red')
    if   (plot_var_log is not None):        
        plt.plot(time_log, plot_var_log[4,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    
    plt.subplot(3,2,6)
    plt.ylabel("$\psi$", fontsize=10)
    plt.plot(time_log, plot_var_des_log[5,:],linestyle='-',lw=lw_des,color = 'red')
    if   (plot_var_log is not None):        
        plt.plot(time_log, plot_var_log[5,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
                
         
    
        
def plotGRFs(figure_id, time_log, des_forces, act_forces):
	       
    lw_act=4  
    lw_des=7
    # %% Input plots

    fig = plt.figure(figure_id)
    fig.suptitle("ground reaction forces", fontsize=20)  
    plt.subplot(6,2,1)
    plt.ylabel("$LF_x$", fontsize=10)
    plt.plot(time_log, des_forces[0,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[0,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,3)
    plt.ylabel("$LF_y$", fontsize=10)
    plt.plot(time_log, des_forces[1,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[1,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,5)
    plt.ylabel("$LF_z$", fontsize=10)
    plt.plot(time_log, des_forces[2,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[2,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((0,450))

    #RF
    plt.subplot(6,2,2)
    plt.ylabel("$RF_x$", fontsize=10)
    plt.plot(time_log, des_forces[3,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[3,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,4)
    plt.ylabel("$RF_y$", fontsize=10)
    plt.plot(time_log, des_forces[4,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[4,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,6)
    plt.ylabel("$RF_z$", fontsize=10)
    plt.plot(time_log, des_forces[5,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[5,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((0,450))
				
     #LH
    plt.subplot(6,2,7)
    plt.ylabel("$LH_x$", fontsize=10)
    plt.plot(time_log, des_forces[6,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[6,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,9)
    plt.ylabel("$LH_y$", fontsize=10)
    plt.plot(time_log, des_forces[7,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[7,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
				
    plt.subplot(6,2,11)
    plt.ylabel("$LH_z$", fontsize=10)
    plt.plot(time_log, des_forces[8,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[8,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((0,450))
				
     #RH
    plt.subplot(6,2,8)
    plt.ylabel("$RH_x$", fontsize=10)
    plt.plot(time_log, des_forces[9,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[9,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
				
    plt.subplot(6,2,10)
    plt.ylabel("$RH_y$", fontsize=10)
    plt.plot(time_log, des_forces[10,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[10,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((-100,100))
						
    plt.subplot(6,2,12)
    plt.ylabel("$RH_z$", fontsize=10)
    plt.plot(time_log, des_forces[11,:],linestyle='-',lw=lw_des,color = 'red')
    plt.plot(time_log, act_forces[11,:],linestyle='-',lw=lw_act,color = 'blue')
    plt.grid()
    plt.ylim((0,450))
                                                             