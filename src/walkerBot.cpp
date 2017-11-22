/**
 * @file    walkerBot.cpp
 * @brief   Defines class methods for walkerBot 
 * @author  Vontrelle Collins
 * @copyright 2017 Vontrelle Collins
 * @license MIT
 */

#include "walkerBot.hpp"
#include <sstream>

// Constructot for WalkerBot initializes the linear and angular values
WalkerBot::WalkerBot() {
  botVel.linear.x = 0;
  botVel.angular.z = 0;
}

// Destructor for WalkerBot class
WalkerBot::~WalkerBot() {
  botVel.linear.x = 0;
  botVel.angular.z = 0;
}

// Method used to publish topics for a robot
void WalkerBot::nodePub(const std::string nodeName) {
  pub = this->node.advertise<geometry_msgs::Twist>(nodeName, 1000);
}

// Method for subscribing to topics
void WalkerBot::nodeSub(const std::string topic) {
  sub = this->node.subscribe<sensor_msgs::LaserScan>(topic, 10,
    &WalkerBot::isObstacle, this);
}

// Method that publishes messages advertised by the robot
void WalkerBot::pubMsg(geometry_msgs::Twist msg) {
  pub.publish(msg);
}

void WalkerBot::chatterCallback(const std_msgs::String::ConstPtr &msg) {
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

// Returns the status of member valuable obstacle
bool WalkerBot::getObstacle() {
  return obstacle;
}

// Set memeber variable obstacle
void WalkerBot::setObstacle(bool value) {
  obstacle = value;
}

// Method for detecting obstacles
void WalkerBot::isObstacle(const sensor_msgs::LaserScan::ConstPtr &msg) {
  // Iterate over scan ranges
  for (auto index : msg->ranges) {
    // Check for distance away from an obstacle
    if (index < 1.25) {
      obstacle = true;
    }
  }
}

// Sets linear and angular velocity values
void WalkerBot::setBotVel(double xLinear, double zAngular) {
  botVel.linear.x = xLinear;
  botVel.angular.z = zAngular;
}

// Gets linear and angular velocity values
geometry_msgs::Twist WalkerBot::getBotVel() {
  return botVel;
}
