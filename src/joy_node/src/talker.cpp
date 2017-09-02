#include <ros/ros.h>
#include <math.h>
#include <joy_sub/Controll.h>
#include <sensor_msgs/Joy.h>


class TeleopNode
{
public:
  TeleopNode();

private:
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);

  ros::NodeHandle nh_;

  int speedLeft, speedRight, pith, roll, directionLeft, directionRight, light;
  ros::Publisher joy_pub_;
  ros::Subscriber joy_sub_;

};


TeleopNode::TeleopNode()
{
  joy_pub_ = nh_.advertise<joy_sub::Controll>("joy_sub/controll", 1);
  joy_sub_ = nh_.subscribe<sensor_msgs::Joy>("joy", 10, &TeleopNode::joyCallback, this);

}

void TeleopNode::joyCallback(const sensor_msgs::Joy::ConstPtr& joy)
{
  joy_sub::Controll controll;
  controll.speed_left = 255*(abs(joy->axes[3]-joy->axes[2])); 
  controll.speed_right = 255*(abs(joy->axes[3]+joy->axes[2])); 
  if(abs(joy->axes[3]) > 0.02){
	if(joy->axes[3]>0){
	  controll.direction_left = controll.direction_right = 1; 
	}
	else{
	  controll.direction_left = controll.direction_right = 0; 
	}	
  }
  else{
	if(joy->axes[2]>0){
	  controll.direction_left = 0;
	  controll.direction_right = 1; 
	}
	else{
	  controll.direction_left = 1;
	  controll.direction_right = 0; 
	}
		
  }
  controll.pitch = (255*joy->axes[0]+255)/2; 
  controll.roll = (255*joy->axes[1]+255)/2; 

  
  joy_pub_.publish(controll);
}


int main(int argc, char** argv)
{
  ros::init(argc, argv, "teleop_joy");
  TeleopNode teleop_node;

  ros::spin();
}
