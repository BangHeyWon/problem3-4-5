#include <ros/ros.h>
#include <math.h>
#include <cstdlib>
#include"ros_tu3/tu3_msg.h"


int sum = NULL;


void subCallback(const ros_tu3::tu3_msgConstPtr& msg){
   /* if(sum != NULL){
        sum += msg->numb;
    }
    else{
        sum = msg->numb;
    }*/
    if(msg->name==1){
    ROS_INFO("receive first = %d",msg->numb);
    sum = msg->numb;
    }
    else{
    ROS_INFO("receive second = %d",msg->numb);
    sum += msg->numb;
    ROS_INFO_STREAM("first+second = "<< sum);// cout 
    }
    
}

int main(int argc, char*argv[])
{
    ros::init(argc,argv, "ros_tu3_sub");
    ros::NodeHandle nh;
    ros::Subscriber sub1 = nh.subscribe<ros_tu3::tu3_msg>("hyewon",1000,subCallback);
    ros::Subscriber sub2 = nh.subscribe<ros_tu3::tu3_msg>("bang", 1000, subCallback);
    ros::spin();
}