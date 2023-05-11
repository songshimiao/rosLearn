#! /usr/bin/env python

# Client
import rospy
from service_communication.srv import Sum, SumRequest
import sys
# import logging
# logging.basicConfig()

if __name__ == '__main__':
    
    if len(sys.argv) != 3:
        rospy.logerr('The number of num must be two!')
        sys.exit(1)
        
    rospy.init_node('client_p')
    client = rospy.ServiceProxy('sum', Sum)
    client.wait_for_service()
    req = SumRequest()
    req.num1 = int(sys.argv[1])
    req.num2 = int(sys.argv[2])
    
    response = client.call(req)
    rospy.loginfo('Response success, the result is : sum = %d', response.sum)