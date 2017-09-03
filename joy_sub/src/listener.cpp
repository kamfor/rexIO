#include "ros/ros.h"
#include <joy_sub/Controll.h>
#include <std_msgs/UInt8MultiArray.h>
#include <stdlib.h>


ros::Publisher pub; 

void Callback(const joy_sub::Controll::ConstPtr& msg)
{
  	std_msgs::UInt8MultiArray array;
	array.data.resize(6);
	array.data[0] = msg->speed_left; 
	array.data[1] = msg->speed_right; 
	array.data[2] = msg->pitch; 
	array.data[3] = msg->roll; 
	array.data[4] = msg->direction_left; 
	array.data[5] = msg->direction_right;
        ROS_INFO("I heard: [%d]", msg->speed_left);
	pub.publish(array); 
}

int main (int argc, char** argv){

	ros::init(argc, argv, "listener");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("joy_sub/controll", 1000,Callback);
	pub = n.advertise<std_msgs::UInt8MultiArray>("joy_sub/euclid_controll", 1);


    ros::spin();

    return 0;
}

