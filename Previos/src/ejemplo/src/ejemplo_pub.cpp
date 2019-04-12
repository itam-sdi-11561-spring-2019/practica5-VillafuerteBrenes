#include <ros/ros.h>
#include <iostream>
#include <std_msgs/Int32.h>
#include <std_msgs/String.h>
#include <string>

#define RATE_HZ 2

using namespace std;

string mensaje;
void get_msg(const std_msgs::String& msg) {
	mensaje = msg.data;
	ROS_INFO_STREAM(mensaje);
}

int main(int argc, char **argv)
{
	ros::init(argc,argv,"ejemplo_pub_node");
	ros::NodeHandle nh;
	ROS_INFO_STREAM("ejemplo_pub_node initialized");																																							
	ROS_INFO_STREAM(ros::this_node::getName());

	ros::Publisher pub = nh.advertise<std_msgs::Int32> ("/msg_ejemplo", 1);
	ros::Subscriber sub_vel = nh.subscribe("/msg_respuesta", 1000, &get_msg);
	ros::Rate rate(RATE_HZ);

	std_msgs::Int32 msg;
	int num; 
		
	while (ros::ok())
	{
		cout << "Introduce un numero entero:" << endl;
		cin >> num;

		msg.data = num;
		pub.publish(msg);

		ROS_INFO_STREAM(".");

		ros::spinOnce();
		rate.sleep();
	}

    return 0;
}


