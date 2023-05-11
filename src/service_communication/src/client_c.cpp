// Client

#include "ros/ros.h"
#include "service_communication/Sum.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");

    if (argc != 3)
    {
        ROS_ERROR("The number of num must be two!");
        return 1;
    }

    // init node
    ros::init(argc, argv, "Client_c");
    // creat nodehandle
    ros::NodeHandle nh;
    // creat Client object
    ros::ServiceClient client = nh.serviceClient<service_communication::Sum>("sum");
    // waiting for Server starting
    ros::service::waitForService("sum");

    // request data
    service_communication::Sum ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    // send request
    bool flag = client.call(ai);

    // deal with request
    if (flag)
        ROS_INFO("Response success, the result is : sum = %d", ai.response.sum);
    else
    {
        ROS_ERROR("Response failed ...");
        return 1;
    }
    return 0;
}
