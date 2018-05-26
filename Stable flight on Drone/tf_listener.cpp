#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <stdio.h>
#include <geometry_msgs/Twist.h>
#include <ar_track_alvar_msgs/AlvarMarkers.h>
#include <ar_track_alvar_msgs/AlvarMarker.h>
//#include <turtlesim/Velocity.h>
//#include <turtlesim/Spawn.h>
using namespace std;
geometry_msgs::Twist twist_msg;
ar_track_alvar_msgs::AlvarMarkers markers;
ar_track_alvar_msgs::AlvarMarker marker0;
ar_track_alvar_msgs::AlvarMarker marker;

void converter_callback(const ar_track_alvar_msgs::AlvarMarkers m){
	markers = m;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "my_tf_listener");

    ros::NodeHandle node;
    double x;
    double y;
    double z;

	twist_msg.linear.x=0.0;
	twist_msg.linear.y=0.0;
	twist_msg.linear.z=0.0;
	twist_msg.angular.x=0.0;
	twist_msg.angular.y=0.0;
	twist_msg.angular.z=0.0;
	bool x_controller = false;
	bool y_controller = false;
	int counter = 0;
	ros::Rate rate(10.0);
	ros::Subscriber sub = node.subscribe("/ar_pose_marker", 100, converter_callback);
	ros::Publisher pubVelocity = node.advertise<geometry_msgs::Twist>("/cmd_vel", 10);


   	while (node.ok()){

   		for(const ar_track_alvar_msgs::AlvarMarker &marker : markers.markers){
			if(marker.id == 0){
				marker0 = marker;
			}
   		}
   		x = marker0.pose.pose.position.x;
   		y = marker0.pose.pose.position.y;
   		z = marker0.pose.pose.position.z;

		counter ++;
		if(counter > 5){
			counter = 0;
			std::cout  << "  Height " << z << " x: " << x << " y: " << y << "\n";
			if(x > 0.01){
				twist_msg.linear.x =  x * 0.01 * 10;
			} else if ( x < -0.01) {
				twist_msg.linear.x =  x * 0.01 * 10;
			} else {
				twist_msg.linear.x = 0;
			}

			if(y > 0.01){
				twist_msg.linear.y =  y * 0.01 * 10;
			} else if ( y < -0.01) {
				twist_msg.linear.y =  y * 0.01 * 10;
			} else {
				twist_msg.linear.y = 0;
			}

			if (z > -0.79){
				twist_msg.linear.z = -0.1;
			} else if ( z < -0.81){
				twist_msg.linear.z = 0.1;
			} else {
				twist_msg.linear.z = 0;
			}

			std::cout << "tswist_msg.linear.x  " << twist_msg.linear.x << " twist_msg.linear.y  " << twist_msg.linear.y <<"\n" ;
			twist_msg.linear.z = 0;
		}
		pubVelocity.publish(twist_msg);
		ros::spinOnce();
		rate.sleep();

   	}
    return 0;
};

