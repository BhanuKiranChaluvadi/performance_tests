#!/usr/bin/env python

import rospy
from performance_tests.msg import SuperAwesome

def talker():
    pub = rospy.Publisher('chatter', SuperAwesome, queue_size=1)
    # initialize node: pytalker
    rospy.init_node('pytalker', anonymous=True)
    # variable defines loop rate: default value: 10
    loop_rate = 10
    # read parameter from the parameter "rate" from parameters.yaml files
    # and assing ton loop_rate
    loop_rate = rospy.get_param('rate')
    rate = rospy.Rate(loop_rate) # 10hz

    msg = SuperAwesome()
    msg.super_awesome_string = "Blue ocean robotics is awesome"

    while not rospy.is_shutdown():
        # rospy.loginfo(msg)
        pub.publish(msg)
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException: pass