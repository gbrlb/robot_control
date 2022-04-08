# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 09:47:07 2019

@author: student
"""

import numpy as np

robot_params = {}
robot_params['hyq'] = {'dt': 0.004, 'kp': 400, 'kd': 6, 'q_0':  np.array([-0.2, 0.7, -1.4, -0.2, 0.7, -1.4, -0.2, -0.7, 1.4, -0.2, -0.7, 1.4]), 
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'], 'buffer_size': 30001}
robot_params['solo'] ={'dt': 0.002, 'kp': 5., 'kd': 0.1, 'q_0':  np.array([0.,  np.pi/4, -np.pi/2, -0.,  np.pi/4, -np.pi/2, 0., -np.pi/4,  np.pi/2, 0., -np.pi/4,  np.pi/2]), 
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'],
                        'buffer_size': 1501} # note the frames are all aligned with base for joints = 0

robot_params['aliengo'] ={'dt': 0.002, 'kp': 25, 'kd': 2, 'q_0':  np.array([-0.2, 0.75, -1.5, -0.2, 0.75, -1.5, -0.2, 0.75, -1.5, -0.2, 0.75, -1.5]),
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'], 'buffer_size': 30001} # note the frames are all aligned with base for joints = 0
robot_params['ur5'] ={'dt': 0.001, 
                       'kp': np.array([300, 300, 300,30,30,1]), 
                       'kd':  np.array([20,20,20,1, 1,0.01]), 
                       'q_0':  np.array([ 0.5, -1.5, 1.0, -0.7, 0.7, 0.5]), #limits([0,pi],   [0, -pi], [-pi/2,pi/2],)
                       'joint_names': ['shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint', 'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint'],
                       'ee_frame': 'tool0',
                       'control_mode': 'point', # 'trajectory','point'
                       'control_type': 'position', # 'position', 'torque'
                       'real_robot': False,
                       'spawn_x' : 0.5,
                       'spawn_y' : 0.35,
                       'spawn_z' : 1.8,
robot_params['jumpleg'] ={'dt': 0.001,
                       'kp': np.array([300, 300, 300, 10, 10, 10 ]),
                       'kd':  np.array([20,20,20, 1,1,1]),
                       'q_0':  np.array([ 0.0, 0.0, 0.3, 0.0, 0.75, -1.5]),
                       'joint_names': ['base_x_joint', 'base_y_joint', 'base_z_joint', 'lf_haa_joint', 'lf_hfe_joint', 'lf_kfe_joint'],
                       'foot_frame': 'lf_foot',
                       'spawn_x' : 0.0,
                       'spawn_y' : 0.0,
                       'spawn_z' : 0.0,
                       'buffer_size': 10000} # note the frames are all aligned with base for joints = 0
                         
verbose = False



