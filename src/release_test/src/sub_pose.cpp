#include "ros/ros.h"
#include "turtlesim/Pose.h"

/*
    topic /turtle1/pose
    subscribe /turtlesim/Pose
*/

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("turtle1's pose information:axis=(%.2f,%.2f),theta=%.2f,linear=%.2f,angle = %.2f",
             pose->x, pose->y, pose->theta, pose->linear_velocity, pose->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose", 100, doPose);
    ros::spin();
    return 0;
}
