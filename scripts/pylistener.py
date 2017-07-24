#!/usr/bin/env python
import rospy
from performance_tests.msg import SuperAwesome

# Global variables to keep track of number of messages received
received =0
observed_loopRate = 0
listening_time = 1 # default value

# message received call back
def callback(data):
    global received
    # rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.super_awesome_string)
    received+=1

# time call back to keep track of number of messgaes received by the subscriber
# in a given time set by parameter "listening_time"
def timer_callback(event):
    global received, observed_loopRate, listening_time
    observed_loopRate  = received/listening_time
    print "Obsereved loop rate = %d" %observed_loopRate
    received = 0
    
def listener():

    global listening_time;

    rospy.init_node('pylistener', anonymous=True)

    listening_time = rospy.get_param('listening_time')

    rospy.Timer(rospy.Duration(listening_time), timer_callback)

    rospy.Subscriber("chatter", SuperAwesome, callback, queue_size = 1)

    rospy.spin()

if __name__ == '__main__':
    listener()