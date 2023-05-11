#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "set_update_param");

    std::vector<std::string> students;
    students.push_back("zhangsan");
    students.push_back("lisi");
    students.push_back("wangwu");
    students.push_back("sundanaodai");

    std::map<std::string, std::string> friends;
    friends["guo"] = "huang";
    friends["yuan"] = "xiao";

    ros::NodeHandle nh;
    nh.setParam("param_vector", students);
    nh.setParam("param_map", friends);

    return 0;
}
