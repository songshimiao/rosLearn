#include "ros/ros.h"
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg)
{
    ROS_INFO("Received data is : %s", msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ros::init(argc, argv, "receiver");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("house", 10, doMsg);
    ros::spin();
    return 0;
}
