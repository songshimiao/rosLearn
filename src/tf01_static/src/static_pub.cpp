#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 初始化 ros 节点
    ros::init(argc, argv, "static_pub");
    ros::NodeHandle nh;
    // 创建静态坐标转换广播器
    tf2_ros::StaticTransformBroadcaster broadcaster;
    // 创建坐标信息对象
    geometry_msgs::TransformStamped ts;

    // --- 设置 header 信息
    ts.header.seq = 100;
    ts.header.stamp = ros::Time::now();
    ts.header.frame_id = "base_link";

    // --- 设置子级坐标系
    ts.child_frame_id = "laser";

    // --- 设置子级坐标系相对与父级的偏移量
    ts.transform.translation.x = 0.2;
    ts.transform.translation.y = 0.0;
    ts.transform.translation.z = 0.5;

    // --- 设置四元数 将欧拉角数据转换成四元数
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, 0);

    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // 广播发布坐标信息
    broadcaster.sendTransform(ts);
    ros::spin();

    return 0;
}
