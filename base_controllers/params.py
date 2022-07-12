# -*- coding: utf-8 -*-
"""
Created on Thu Apr 18 09:47:07 2019

@author: student
"""

import numpy as np

robot_params = {}
robot_params['hyq'] = {'dt': 0.004, 'kp': 400, 'kd': 6, 'q_0':  np.array([-0.2, 0.7, -1.4, -0.2, 0.7, -1.4, -0.2, -0.7, 1.4, -0.2, -0.7, 1.4]), 
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'],
                        'spawn_x': 0.0,
                        'spawn_y': 0.0,
                        'spawn_z': 0.8,
                       'buffer_size': 30001}
robot_params['solo'] ={'dt': 0.002, 'kp': 5., 'kd': 0.1, 'q_0':  np.array([0.,  np.pi/4, -np.pi/2, -0.,  np.pi/4, -np.pi/2, 0., -np.pi/4,  np.pi/2, 0., -np.pi/4,  np.pi/2]),
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'],
                       'spawn_x': 0.0,
                       'spawn_y': 0.0,
                       'spawn_z': 0.3,
                        'buffer_size': 1501} # note the frames are all aligned with base for joints = 0
robot_params['solo_fw'] ={'dt': 0.002, 'kp': 5., 'kd': 0.1, 'q_0':  np.array([0.,  np.pi/4, -np.pi/2, -0.,  np.pi/4, -np.pi/2, 0., -np.pi/4,  np.pi/2, 0., -np.pi/4,  np.pi/2]),
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'],
                        'spawn_x': 0.0,
                        'spawn_y': 0.0,
                        'spawn_z': 0.3,
                        'buffer_size': 1501} # note the frames are all aligned with base for joints = 0

robot_params['aliengo'] ={'dt': 0.002, 'kp': 15.0, 'kd': 1.0, 'q_0':  np.array([0.2, 0.7, -1.4, -0.2, 0.7, -1.4, 0.2, 0.7, -1.4, -0.2, 0.7, -1.4]),
                        'ee_frames': ['lf_foot', 'rf_foot', 'lh_foot','rh_foot'],
                          'spawn_x': 0.0,
                          'spawn_y': 0.0,
                          'spawn_z': 1.0,
                          'buffer_size': 30001} # note the frames are all aligned with base for joints = 0
robot_params['ur5'] ={'dt': 0.001, 
                       'kp': np.array([300, 300, 300,30,30,1]), 
                       'kd':  np.array([20,20,20,1, 1,0.01]),
                       #'q_0':  np.array([ 0.3, -1.3, 1.0, -0.7, 0.7, 0.5]), #limits([0,pi],   [0, -pi], [-pi/2,pi/2],)
                       'q_0':  np.array([ 0.5, -1.0, 1.0, -1.7, -1.7, 0.0]), #limits([0,pi],   [0, -pi], [-pi/2,pi/2],)
                       'joint_names': ['shoulder_pan_joint', 'shoulder_lift_joint', 'elbow_joint', 'wrist_1_joint', 'wrist_2_joint', 'wrist_3_joint'],
                       'ee_frame': 'tool0',
                       'control_mode': 'point', # 'trajectory','point'
                       'real_robot': False,
                       'control_type': 'torque', # 'position', 'torque'
                       'spawn_x' : 0.5,
                       'spawn_y' : 0.35,
                       'spawn_z' : 1.8,
                       'buffer_size': 6000} # note the frames are all aligned with base for joints = 0

robot_params['jumpleg'] ={'dt': 0.001,
                       'kp': np.array([100, 100, 100, 10, 10, 10 ]),
                       'kd':  np.array([10,10,10, 0.2,0.2,0.2]),
                       'q_0':  np.array([ 0.0, 0.0, 0.25, -0.24010055475883635,0.7092776153747403,-1.4185292429491714]),
                       'joint_names': ['base_x_joint', 'base_y_joint', 'base_z_joint', 'lf_haa_joint', 'lf_hfe_joint', 'lf_kfe_joint'],
                       'ee_frame': 'lf_foot',
                       'spawn_x' : 0.0,
                       'spawn_y' : 0.0,
                       'spawn_z' : 0.0,
                       'buffer_size': 10000} # note the frames are all aligned with base for joints = 0

robot_params['climbingrobot'] ={'dt': 0.001,
                       'kp': np.array([1000, 1000, 1000,
                                       1000, 1000, 1000,
                                       1000,
                                       0, 0, 0,
                                       5, 5, 5 ]),
                       'kd':  np.array([100 , 100, 100,
                                        10,10,10,
                                        10,
                                        0,0,0,
                                        0.2,0.2,0.2]),
                       'q_0':  np.array([0.0, 0.0, 2.0,
                                         2.0, 2.0, 2.0,
                                         0.,
                                         0., 0., 0,
                                         -0.0,0.0, 0.]),
                       'joint_names': ['anchor_x_joint', 'anchor_y_joint','anchor_z_joint','mountain_wire_pitch', 'mountain_wire_roll', 'mountain_wire_yaw', 'wire_base_prismatic',
                                       'wire_base_pitch', 'wire_base_roll','wire_base_yaw',
                                       'hip_pitch', 'hip_roll','knee'],
                       'ee_frame': 'foot',
                       'spawn_x' : 0.0,
                       'spawn_y' : 0.0,
                       'spawn_z' : 0.0,
                       'buffer_size': 10000} # note the frames are all aligned with base for joints = 0
                         
verbose = False
plotting = False


