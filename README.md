# enpm808x_turtlebot_gazebo
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)

## Overview
```
Impliments walker functionality for turtlebot using gazebo
```

## Dependencies
#### Ubuntu 16.04.3 LTS
[Ubuntu](https://www.ubuntu.com/download/desktop "Ubuntu Installation")

#### ROS Version
[Kinetic](http://wiki.ros.org/kinetic/Installation "ROS Installation")

#### Gazebo 7.8
[Gazebo](http://gazebosim.org/tutorials?tut=ros_overview "Gazebo Overview")

## Creating Catkin Workspace
```
Create catkin workspace
$ mkdir -p ~/catkin_workspce/src
$ cd ~/catkin_workspace
$ catkin_make

---Source your catkin workspace---
$ source devel/setup.bash
```

## Adding Package to Workspace
```
$ cd ~/catkin_workspace/src
$ git clone --recursive https://github.com/reggie2010/enpm808x_turtlebot_gazebo.git

$ cd ..
$ catkin_make
```

## Run Robot in Gazebo
### In seperate terminals
```
$ roscore //starts master node

$ roslaunch turtlebot_gazebo turtlebot_world.launch 

$ . ~/catkin_ws/devel/setup.bash
$ rosrun enpm808x_turtlebot_gazebo rebot mybot // Argument sets name of node
```