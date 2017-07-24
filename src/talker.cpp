#include "ros/ros.h"
#include <sstream>
#include "performance_tests/SuperAwesome.h"


int main(int argc, char *argv[])
{
  //initialize node: talker
  ros::init(argc, argv, "talker");
  // Node handler
  ros::NodeHandle node;
  // publishing custom message of type: "SuperAwesome". topic: chatter
  ros::Publisher chatter_pub = node.advertise<performance_tests::SuperAwesome>("chatter", 1);
  // loop rate, which will be read from file parameters.yaml
  int rate ;
  node.param("rate", rate, 10);

  ROS_INFO("loop_rate = %d", rate);

  ros::Rate loop_rate(rate);

  int count = 0;
  while (ros::ok())
  {

  	performance_tests::SuperAwesome msg;

    std::stringstream ss;

    ss << "Blue ocean robotics is awesome" << count;
    /*
    ss << "It is our vision to be the lead partner \n"
    		"in creating and commercializing robots for end-users, \n"
    		 "and robotic communities – worldwide. It inspires us. \n"
    		 "It motivates us – to be at the forefront of the robot \n"
    		 "technological development as we create robots that improve \n"
    		 "quality-of-life, working environments and productivity" << count;

    */

  	msg.super_awesome_string = ss.str();
    // publish messgae
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}