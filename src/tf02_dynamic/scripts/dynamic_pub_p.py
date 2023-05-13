#! /usr/bin/env python
# coding: utf-8

import rospy
import tf2_ros
from geometry_msgs.msg import TransformStamped
from turtlesim.msg import Pose
from tf.transformations import quaternion_from_euler

# 功能：
# -- 需要订阅 robot 的位姿信息
# -- 转换成相对于窗体的坐标关系并发布
# ---- topic : /turtle1/pose
# ---- message : /turtlesim/Pose

def doPose(pose):
    # 创建 TF 广播器
    broadcaster = tf2_ros.TransformBroadcaster()
    # 生成要广播的数据
    ts = TransformStamped();
    
    ts.header.frame_id = 'world_p'
    ts.header.stamp = rospy.Time.now()
    ts.child_frame_id = 'turtle1'
    
    ts.transform.translation.x = pose.x
    ts.transform.translation.y = pose.y
    ts.transform.translation.z = 0.0

    qtn = quaternion_from_euler(0,0,pose.theta)
    
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    
    broadcaster.sendTransform(ts)
    
if __name__ == '__main__':
    
    # 初始化 ros 节点
    rospy.init_node('dynamic_pub_p')
    # 创建订阅对象
    # -- 订阅 robot 的位姿信息
    # -- 坐标转换与发布在回调函数中完成
    sub = rospy.Subscriber('turtle1/pose', Pose, doPose)
    
    rospy.spin()
    