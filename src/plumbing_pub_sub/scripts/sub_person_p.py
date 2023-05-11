#! /usr/bin/env python
# coding: utf-8

import rospy
from plumbing_pub_sub.msg import Person

def doMsg(person):
    rospy.loginfo('接收到的消息: {}, {}, {}'.format(
        person.name,
        person.age,
        person.height))


if __name__ == '__main__':
    rospy.loginfo('receiver--')
    rospy.init_node('sub_person_p')
    sub = rospy.Subscriber('chating', Person, doMsg, queue_size=10)
    rospy.spin()