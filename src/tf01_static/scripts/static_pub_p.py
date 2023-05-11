#! /usr/bin/env python

import rospy
import tf2_ros
from tf import transformations
from geometry_msgs.msg import TransformStamped


if __name__ == '__main__':
    

    rospy.init_node('static_pub_p')
    broadcaster = tf2_ros.StaticTransformBroadcaster()
    ts = TransformStamped()
    
    ts.header.frame_id = 'base_link_p'
    ts.header.seq = 101
    ts.header.stamp = rospy.Time.now()
    
    ts.child_frame_id = 'laser_p'
    
    ts.transform.translation.x = 0.2
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    
    qtn = transformations.quaternion_from_euler(0,0,0)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]

    broadcaster.sendTransform(ts)
    rospy.spin()
    