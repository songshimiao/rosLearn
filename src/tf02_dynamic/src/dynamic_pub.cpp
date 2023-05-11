#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

// 功能：
// -- 需要订阅乌龟的位姿信息
// -- 转换成相对于窗体的坐标关系并发布
// ---- topic : /turtle1/pose
// ---- message : /turtlesim/Pose

// 函数声明
void doPose(const turtlesim::Pose::ConstPtr &pose);

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // 初始化 ros 节点
    ros::init(argc, argv, "dynamic_pub");
    ros::NodeHandle nh;
    // 创建订阅对象
    // -- 订阅乌龟的位姿信息
    // -- 坐标转换与发布在回调函数中完成
    ros::Subscriber sub = nh.subscribe<turtlesim::Pose>("/turtle1/pose", 100, doPose);
    ros::spin();
    return 0;
}

// 回调函数
// -- 坐标转换 & 发布
void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    // 创建坐标变换广播器
    static tf2_ros::TransformBroadcaster broadcaster;
    // 生成要广播的数据
    geometry_msgs::TransformStamped ts;

    // -- header
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    // -- child
    ts.child_frame_id = "turtle1";
    // -- 坐标数据
    ts.transform.translation.x = pose->x;
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0.0;
    tf2::Quaternion qtn;
    qtn.setRPY(0, 0, pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();

    // 广播
    broadcaster.sendTransform(ts);
}
