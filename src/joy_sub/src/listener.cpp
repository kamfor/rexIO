#include "ros/ros.h"
#include <joy_sub/Controll.h>


void Callback(const joy_sub::Controll::ConstPtr& msg)
{
  ROS_INFO("I heard: [%d]", msg->speed_left);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000,Callback);

  ros::spin();

  return 0;
}

