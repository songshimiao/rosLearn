#! /usr/bin/env python
# coding:utf-8

import rospy
from plumbing_pub_sub.msg import Person

if __name__ == '__main__':
    rospy.loginfo('Publisher--')
    rospy.init_node('pub_person_p')
    pub = rospy.Publisher('chating', Person, queue_size=10)
    person = Person()
    person.name = '李四'
    person.age = 1
    person.height = 1.65
    rate = rospy.Rate(1)
    rospy.sleep(2)
    while not rospy.is_shutdown():
        pub.publish(person)
        rospy.loginfo('发送的数据: {}, {}, {}'.format(person.name,
                                                 person.age,
                                                 person.height))
        person.age += 1
        rate.sleep()