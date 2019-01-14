#include <ros/ros.h>
#include <math.h>
#include <fstream>
#include <cstdlib>
#include"ros_tu5/tu5_msg.h"
using namespace std;


void subCallback(const ros_tu5::tu5_msgConstPtr& msg){
    fstream File("/home/bangglee/Desktop/number3.txt");
    for(int a = 0; a < msg->count; a++)
    {
        File << (-msg->v[a]) << endl;
    }
    File.close();
    int t;
    int nums=0;
    fstream sFile("/home/bangglee/Desktop/number3.txt");
    while(sFile>>t)
    {
        ROS_INFO("%d ",t);
    }
    sFile.close();
    
}

int main(int argc, char*argv[])
{
    ros::init(argc,argv, "program5sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<ros_tu5::tu5_msg>("hy5",1000,subCallback);
    ros::spin();
}