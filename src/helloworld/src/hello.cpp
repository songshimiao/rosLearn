#include "ros/ros.h"
#include "helloworld/hello.h"

namespace hello_ns
{
    void myHello::run()
    {
        ROS_INFO("run() function is going ...");
    }
}


int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello_head");
    hello_ns::myHello myhello;
    myhello.run();
    return 0;
}
