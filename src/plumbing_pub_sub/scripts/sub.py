#! /usr/bin/env python

import rospy
from std_msgs.msg import String

def doMsg(msg):
    rospy.loginfo('Received data is : {}'.format(msg.data))
    
if __name__ == '__main__':
    rospy.init_node('subscriber')
    sub = rospy.Subscriber('house', String, doMsg, queue_size=10)
    rospy.spin()