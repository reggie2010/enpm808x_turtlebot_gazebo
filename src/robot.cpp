/**
 * @file    robot.cpp
 * @brief   main node for walker robot 
 * @author  Vontrelle Collins
 * @copyright 2017 Vontrelle Collins
 * @license MIT
 */

#include "walkerBot.hpp"


int main(int argc, char **argv) {
  // Makes sure two argument of passed to node
  // Argument defines the name of the node
  if (argc != 2) {
    ROS_INFO("Node needs name input from command line");
    return 1;
  }

  ros::init(argc, argv, argv[1]);
  WalkerBot wb;  // Creates WalkerBot object

  wb.nodePub("cmd_vel_mux/input/navi");  // Publishes cmd_vel_mux topic
  wb.nodeSub("scan");  // Subcribes to scan topic
  ros::Rate loop_rate(10);  // Sets loop rate

  while (ros::ok()) {
    loop_rate.sleep();

    if (!wb.getObstacle()) {
      wb.setBotVel(0.3, 0.0);
    } else {
      wb.setBotVel(0.0, 0.5);
      wb.setBotVel(-0.3, 0.0);
    }

    wb.pubMsg(wb.getBotVel());
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
