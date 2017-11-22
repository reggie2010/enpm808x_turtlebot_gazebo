#ifndef WALKERBOT_H
#define WALKERBOT_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "std_msgs/String.h"
#include <memory>

class WalkerBot {
public:
  WalkerBot();
  ~WalkerBot();
  void nodePub(const std::string nodeName);
  void nodeSub(const std::string topic);
  void pubMsg(geometry_msgs::Twist msg);
  bool getObstacle();
  void setObstacle(bool value);
  void isObstacle(const sensor_msgs::LaserScan::ConstPtr& msg);
  void setBotVel(double xLinear, double zAngular);
  geometry_msgs::Twist getBotVel();
  static void chatterCallback(const std_msgs::String::ConstPtr& msg);


private:
  ros::NodeHandle node;
  ros::Publisher pub;
  ros::Subscriber sub;
  bool obstacle = false;
  geometry_msgs::Twist botVel;
};

#endif