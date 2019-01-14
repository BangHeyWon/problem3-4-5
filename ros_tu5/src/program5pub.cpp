#include <ros/ros.h>
#include <fstream>
#include <iostream>
#include "ros_tu5/tu5_msg.h"
using namespace std;


int main(int argc, char **argv){
    ros::init(argc,argv, "program5pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<ros_tu5::tu5_msg>("hy5",1000);
    ros::Rate loop_rate(10);
    ros_tu5::tu5_msg msg;

    fstream inFile("/home/bangglee/Desktop/number2.txt");

    int a;
    int num = 0;
    while(inFile>>a){
        msg.v.push_back(a);
        ROS_INFO("%d ",msg.v[num]);
        loop_rate.sleep(); 
        num++;
    }
    msg.count = num;

    inFile.close();

    pub.publish(msg);
    return 0;
}
