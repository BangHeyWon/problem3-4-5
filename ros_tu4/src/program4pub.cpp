#include <ros/ros.h>
#include <fstream>
#include <iostream>
#include "ros_tu4/tu4_msg.h"
using namespace std;


int main(int argc, char **argv){
    ros::init(argc,argv, "program4pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<ros_tu4::tu4_msg>("hyewon",1000);
    ros::Rate loop_rate(10);
    ros_tu4::tu4_msg msg;

    fstream inFile("/home/bangglee/Desktop/number.txt");

    /*while(!inFile.eof()){
        inFile.getline(inputString,100);
        cout<<inputString<<endl;
    }*/
    int a;
    int num = 0;
    while(inFile>>a){
        msg.v.push_back(a);
      //  ROS_INFO("%d ",msg.v[num]);
        loop_rate.sleep(); 
        num++;
    }
    msg.count = num;
    for(int i=0;i<msg.count;i++)
    {
        ROS_INFO("%d ",msg.v[i]);
        loop_rate.sleep();
    }
    ROS_INFO("total = %d",msg.count);

    inFile.close();

    pub.publish(msg);
    return 0;
}
