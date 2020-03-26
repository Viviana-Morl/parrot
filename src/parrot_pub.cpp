#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>


int main (int argc, char **argv){
  ros::init(argc, argv, "ros_topic_publisher");
  ros::NodeHandle nh;
  ros::Publisher topic_pub = nh.advertise<std_msgs::String>("/parrot",10);
  ros::Rate rate(10);

  while (ros::ok()) {
  
  std_msgs::String msg;
  std::string st;

  std::cout<<"Insert the string:";
  std::getline(std::cin,st);

  msg.data=st;
  ROS_INFO("%s", msg.data.c_str());

  topic_pub.publish(msg);

  rate.sleep();
  }

return 0;

}
