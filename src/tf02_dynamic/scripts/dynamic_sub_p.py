#! /usr/bin/env python
# coding: utf-8

import rospy
import tf2_ros
from tf2_geometry_msgs import PointStamped

if __name__ == '__main__':

    # 初始化 ros 节点
    rospy.init_node('dynamic_sub_p')
    # 创建 TF 订阅对象
    buffer = tf2_ros.Buffer()
    listener = tf2_ros.TransformListener(buffer)
    
    rate = rospy.Rate(1)
    
    while not rospy.is_shutdown():
        ps_laser = PointStamped()
        ps_laser.header.frame_id = 'turtle1'
        ps_laser.header.stamp = rospy.Time()
        ps_laser.point.x = 1.0
        ps_laser.point.y = 1.0
        ps_laser.point.z = 0.0
        
        try:
            ps_base = buffer.transform(ps_laser, 'world_p')
            rospy.loginfo('转换结果：(%.2f, %.2f, %.2f)', ps_base.point.x, ps_base.point.y, ps_base.point.z)
        except Exception as e:
            rospy.logerr('程序异常：{}'.format(e))
            
    rate.sleep()

