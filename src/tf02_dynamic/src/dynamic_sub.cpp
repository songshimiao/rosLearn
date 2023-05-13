#include "ros/ros.h"
#include "tf2_ros/buffer.h"
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

// 功能
// 将 robot 坐标系中的一个点
// 动态地转换成世界坐标系中的坐标

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 初始化 ros 节点
    ros::init(argc, argv, "dynamic_sub");
    ros::NodeHandle nh;
    // 创建订阅节点
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    ros::Rate rate(1);

    while (ros::ok())
    {
        geometry_msgs::PointStamped ps_laser;
        ps_laser.header.frame_id = "turtle1";
        ps_laser.header.stamp = ros::Time();
        ps_laser.point.x = 1;
        ps_laser.point.y = 1;
        ps_laser.point.z = 0;

        try
        {
            geometry_msgs::PointStamped ps_base;
            ps_base = buffer.transform(ps_laser, "world");
            ROS_INFO("result: (%.2f, %.2f, %.2f)",
                     ps_base.point.x,
                     ps_base.point.y,
                     ps_base.point.z);
        }
        catch (const std::exception &e)
        {
            ROS_INFO("程序异常：%s", e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
