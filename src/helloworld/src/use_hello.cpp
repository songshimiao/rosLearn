#include "ros/ros.h"
#include "helloworld/hello.h"

int main(int argc, char *argv[])
{
    ros::init(argc, argv, "hello_head_src");
    hello_ns::myHello my;
    my.run();
    return 0;
}
