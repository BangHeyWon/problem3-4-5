#include <ros/ros.h> 
#include <std_msgs/Bool.h>
int main(int argc, char *argv[]){
    ros::init(argc,argv, "ros_tutorials_pub");
    ros::NodeHandle nh;
    //이 위까지는 어떤 Ros프로그램에 복붙하기.
    ros::Publisher pub = nh.advertise<std_msgs::Bool>("simple_bool", 10); //publisher를 작성한것.

    ros::Rate loop_rate(10);//100ms
    std_msgs::Bool msg;
    while(ros::ok()){
        msg.data = ~msg.data;
        pub.publish(msg);
        loop_rate.sleep();
    }
}