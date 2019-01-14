#include <ros/ros.h> 
#include <cstdlib>
#include<vector>
#include"ros_tu3/tu3_msg.h"
using namespace std;

int main(int argc, char **argv){
    ros::init(argc,argv, "program3pub");
    ros::NodeHandle nh;
    ros::Publisher first = nh.advertise<ros_tu3::tu3_msg>("hyewon",1000);
    ros::Publisher second = nh.advertise<ros_tu3::tu3_msg>("bang",1000);
    ros::Rate loop_rate(10);
    ros_tu3::tu3_msg msg1;
    ros_tu3::tu3_msg msg2;
  
    srand(time(NULL));
    u_int16_t num;

    int count = 0;
    while(ros::ok())
    {
        msg1.stamp = ros::Time::now();
        num = rand()%20+1;
        msg1.numb = num;
        msg1.name = 1;

        msg2.stamp = ros::Time::now();
        num = rand()%20+1;
        msg2.numb = num;
        msg2.name = 2;
        count=0;
      
    
    first.publish(msg1);
    second.publish(msg2);
    loop_rate.sleep();
    count++;
    }    
    return 0;

}