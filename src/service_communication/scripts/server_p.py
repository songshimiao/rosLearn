#! /usr/bin/env python

# Server

import rospy
from service_communication.srv import Sum, SumResponse

def responseRequest(request):
    sum = request.num1 + request.num2
    rospy.loginfo('Received : num1 = {}, num2 = {}'.format(request.num1, request.num2))
    
    responce = SumResponse(sum)
    return responce
    
    
if __name__ == '__main__':
    # init node
    rospy.init_node('Server_p')
    # create Server object
    server = rospy.Service('sum', Sum, responseRequest)
    rospy.loginfo('Server starting ...')
    rospy.spin()