#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 初始化 ros 节点
    ros::init(argc, argv, "static_sub");
    ros::NodeHandle nh;
    // 创建订阅对象
    tf2_ros::Buffer buffer; // 缓存器
    tf2_ros::TransformListener listener(buffer);

    ros::Rate rate(10);
    // ros::Duration(2).sleep();
    while (ros::ok())
    {

        // 相对于 laser 坐标系，生成一个坐标点
        geometry_msgs::PointStamped point_laser;
        point_laser.header.frame_id = "laser";
        point_laser.header.stamp = ros::Time::now();
        point_laser.point.x = 2.0;
        point_laser.point.y = 3.0;
        point_laser.point.z = 5.0;
        // 转换坐标点
        try
        {
            geometry_msgs::PointStamped point_base;
            point_base = buffer.transform(point_laser, "base_link");
            ROS_INFO("转换后坐标值：(%.2f, %.2f, %.2f), 参考的坐标系：%s",
                     point_base.point.x, point_base.point.y,
                     point_base.point.z,
                     point_base.header.frame_id.c_str());
        }
        catch (const std::exception &e)
        {
            // std::cerr << e.what() << '\n';
            ROS_INFO("%s", e.what());
        }

        rate.sleep();
        ros::spinOnce();
    }

    return 0;
}
