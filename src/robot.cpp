#include "walkerBot.hpp"


int main(int argc, char **argv) {
  if (argc != 2) {
    ROS_INFO("Node needs name input from command line");
    return 1;
  }

  ros::init(argc, argv, argv[1]);
  WalkerBot wb;

  wb.nodePub("cmd_vel_mux/input/navi");
  wb.nodeSub("scan");
  ros::Rate loop_rate(10);

  while(ros::ok()) {
    
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