#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <std_msgs/Int32.h>
#include <string>

#define RATE_HZ 2

using namespace std;

ros::Publisher velocity_publisher;

void move(double speed, double distance, bool isForward);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "tortu_node");
	ros::NodeHandle nh;
	ros::Publisher pub = nh.advertise<geometry_msgs::Twist> ("/turtle1/cmd_vel", 10);
	geometry_msgs::Twist msg;
	int instruccion;

	while (ros::ok())
	{
		cout << "Introduce una instrucción:" << endl;
		cin >> instruccion;

		if (instruccion == 2){
			msg.angular.z = -3.14/2;
		}
		else if (instruccion == 4){
			msg.linear.x = 1;
		}
		else if (instruccion == 6){
			msg.linear.x = -1;
		}
		else{
			msg.angular.z = 3.14/2;
		}
		
		pub.publish(msg);

		ROS_INFO_STREAM(".");

		ros::spinOnce();
		//rate.sleep();

		msg.angular.z = 0;
		msg.linear.x = 0;
	}

    return 0;
}