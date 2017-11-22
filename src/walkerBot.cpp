#include "walkerBot.hpp"
#include <sstream>


WalkerBot::WalkerBot() {
  botVel.linear.x = 0;
  botVel.angular.z = 0;
}
WalkerBot::~WalkerBot() {
  botVel.linear.x = 0;
  botVel.angular.z = 0;
}

void WalkerBot::nodePub(const std::string nodeName) {
  pub = this->node.advertise<geometry_msgs::Twist>(nodeName, 1000);
}

void WalkerBot::nodeSub(const std::string topic) {
  sub = this->node.subscribe<sensor_msgs::LaserScan>(topic, 10, &WalkerBot::isObstacle, this);
}

void WalkerBot::pubMsg(geometry_msgs::Twist msg) {
  pub.publish(msg);
}

void WalkerBot::chatterCallback(const std_msgs::String::ConstPtr &msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

bool WalkerBot::getObstacle() {
  return obstacle;
}

void WalkerBot::setObstacle(bool value) {
  obstacle = value;
}

void WalkerBot::isObstacle(const sensor_msgs::LaserScan::ConstPtr &msg) {

  // Iterate over scan ranges
  for (auto index : msg->ranges) {
    
    // Check for distance away from an obstacle
    if (index < 1.25) {
      
      obstacle = true;
    }
  }
}

void WalkerBot::setBotVel(double xLinear, double zAngular) {
  botVel.linear.x = xLinear;
  botVel.angular.z = zAngular;
}

geometry_msgs::Twist WalkerBot::getBotVel() {
  return botVel;
}