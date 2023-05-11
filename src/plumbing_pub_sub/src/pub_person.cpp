#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
#include "plumbing_pub_sub/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    ROS_INFO("Publisher--");
    ros::init(argc, argv, "pub_person");
    ros::NodeHandle nh;
    ros::Publisher pub =
        nh.advertise<plumbing_pub_sub::Person>(
            "chat", 10);
    plumbing_pub_sub::Person person;
    person.name = "张三";
    person.age = 1;
    person.height = 1.73;
    ros::Rate rate(1);
    ros::Duration(2).sleep();

    while (ros::ok())
    {
        pub.publish(person);
        ROS_INFO("发布的消息：%s, %d, %.2f", person.name.c_str(), person.age, person.height);
        person.age += 1;
        rate.sleep();
    }

    return 0;
}
