#! /usr/bin/env python

import rospy
import tf2_ros
from tf2_geometry_msgs import tf2_geometry_msgs
from tf2_geometry_msgs import PointStamped

if __name__ == '__main__':
    
    rospy.init_node('static_sub_p')
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)
    
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        point_laser = PointStamped()
        point_laser.header.frame_id = 'laser_p'
        point_laser.header.stamp = rospy.Time.now()
        point_laser.point.x = 2.0
        point_laser.point.y = 3.0
        point_laser.point.z = 5.0
        
        try:
            point_base = buffer.transform(point_laser, 'base_link_p')
            rospy.loginfo(
                'result: (%.2f, %.2f, %.2f)',
                    point_base.point.x,
                    point_base.point.y,
                    point_base.point.z
            )
        except Exception as e:
            rospy.loginfo(e)
            
            
        rate.sleep()
    