#include "ros/ros.h"
#include "std_msgs/String.h"
#include "plumbing_pub_sub/Person.h"

void doMsg(
    const plumbing_pub_sub::Person::ConstPtr p)
{
    ROS_INFO(
        "接收到的消息: %s, %d, %.2f",
        p->name.c_str(),
        p->age,
        p->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ROS_INFO("Receiver--");
    ros::init(argc, argv, "sub_person");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<plumbing_pub_sub::Person>(
        "chat", 10, doMsg);
    ros::spin();
    return 0;
}
