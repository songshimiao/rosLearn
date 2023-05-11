#! /usr/bin/env python

import rospy
from geometry_msgs.msg import Twist

'''
    topic: /turtle1/cmd_vel
    messages: geometry_msgs/Twist
    
'''

if __name__ == '__main__':
    
    rospy.init_node('my_control_p')
    pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
    rate = rospy.Rate(10)
    twist = Twist()
    twist.linear.x = -1.0
    twist.linear.y = 1.0
    twist.linear.z = 1.0
    twist.angular.x = 0.0
    twist.angular.y = 0.0
    twist.angular.z = 0.5
    
    while not rospy.is_shutdown():
        pub.publish(twist)
        rate.sleep()
        

