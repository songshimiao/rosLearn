// Server

#include "ros/ros.h"
#include "service_communication/Sum.h"

bool responseRequest(service_communication::Sum::Request &request,
                     service_communication::Sum::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;

    ROS_INFO("Received : num1 = %d, num2 = %d", num1, num2);

    if (num1 < 0 || num2 < 0)
    {
        ROS_ERROR("wrong number!");
        return false;
    }

    response.sum = num1 + num2;
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    // init the node
    ros::init(argc, argv, "Server_c");
    // create nodehandle
    ros::NodeHandle nh;
    // create Server object
    ros::ServiceServer server = nh.advertiseService("sum", responseRequest);
    ROS_INFO("Server starting ...");
    ros::spin();
    return 0;
}
