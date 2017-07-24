#include <ros/ros.h>
#include <ros/time.h>
#include "performance_tests/SuperAwesome.h"

// global vaiables
int received = 0;
int observed_loopRate = 0;
int listening_time = 0;


void chatterCallback(const performance_tests::SuperAwesome::ConstPtr& msg)
{
  //ROS_INFO("I heard: [%s]", msg->super_awesome_string.c_str());
  received+=1;
}

// Timer call back - It is called after "listening_time" parameter in .YAML file
// Keeps track of messages received by subscriber in a given "listening_time"
void timer_callback(const ros::TimerEvent &event){
	
	observed_loopRate  = received/listening_time;
	ROS_INFO("Obsereved loop rate = %d", observed_loopRate);
	received = 0;
}

int main(int argc, char **argv)
{
  //initialize node: listener
  ros::init(argc, argv, "listener");
  // Node handler
  ros::NodeHandle n;
  // Read parameter: "listening_time" from parameters file.
  // Default value assigned is 1 second.
  n.param("listening_time", listening_time, 1);
  // Timer call back
  ros::Timer timer_ = n.createTimer(ros::Duration(listening_time), timer_callback);
  // Subscriber to topic:"chatter" , call back: "chatterCallback"
  ros::Subscriber sub = n.subscribe("chatter", 1, chatterCallback);

  ros::spin();

  return 0;
}