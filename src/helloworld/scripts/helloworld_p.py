#! /usr/bin/env python

import rospy

if __name__ == '__main__':
    rospy.init_node('Hello')
    rospy.loginfo("hello world ! by python")