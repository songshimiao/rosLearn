#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        ROS_ERROR("args must be 5");
        return 1;
    }
    ros::init(argc, argv, "turtle_server");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    ros::service::waitForService("spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = atof(argv[1]);
    spawn.request.y = atof(argv[2]);
    spawn.request.theta = atof(argv[3]);
    spawn.request.name = argv[4];
    bool flag = client.call(spawn);

    if(flag)
    {
        ROS_INFO("new turtle's name = %s", spawn.response.name.c_str());

    }
    else
    {
        ROS_INFO("add failed ...");
    }
    
    return 0;
}
