#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <stdio.h>
#include <signal.h>
#include "std_msgs/String.h"
#include <ardrone_autonomy/Navdata.h>
#include "std_msgs/Empty.h"
#include <geometry_msgs/Twist.h>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
  ros::init(argc, argv, "tf_listener", ros::init_options::NoSigintHandler);
  ros::NodeHandle node;

/*  ros::service::waitForService("spawn");
  ros::ServiceClient add_turtle = 
    node.serviceClient<turtlesim::Spawn>("spawn");
  turtlesim::Spawn srv;
  add_turtle.call(srv);

  ros::Publisher turtle_vel = 
    node.advertise<turtlesim::Velocity>("turtle2/command_velocity", 10);*/

  tf::TransformListener listener;
  tf::TransformListener listener2;
  tf::TransformListener listener3;
  tf::TransformListener listener4;
  tf::TransformListener listener5;
  tf::TransformListener listener6;
  tf::TransformListener listener7;
  tf::TransformListener listener8;
  tf::TransformListener listener9;
  tf::TransformListener listener10;
  
 /* ros::Publisher pubTakeoff = n.advertise<std_msgs::Empty>("/ardrone/takeoff", 1);
  ros::Publisher pubLand = n.advertise<std_msgs::Empty>("/ardrone/land", 1);*/
  
  /*ros::Subscriber sub1 = n.subscribe("/ardrone/calibration_response", 1, calibCallback);
  ros::Subscriber sub2 = n.subscribe("/ardrone/humandetection",1, visionCallback);
  ros::Subscriber sub3 = n.subscribe("/ardrone/localization",1, localCallback);
  ros::Subscriber sub4 = n.subscribe("/ardrone/navdata", 1, navdataCallback);*/


    ros::Rate rate(10.0);
  while (node.ok()){
    tf::StampedTransform transform;
    tf::StampedTransform transform2;
    tf::StampedTransform transform3;
    tf::StampedTransform transform4;
    tf::StampedTransform transform5;
    tf::StampedTransform transform6;
    tf::StampedTransform transform7;
    tf::StampedTransform transform8;
    tf::StampedTransform transform9;
    tf::StampedTransform transform10;
    try{
      listener.lookupTransform("/ar_marker_0", "/ar_marker_1",
                               ros::Time(0), transform);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker1 = transform.getOrigin().x();
    cout << "marker1_x: " << msg_xDist_marker1 << "\n";
    double msg_yDist_marker1 = transform.getOrigin().y();
    cout << "marker1_y: " << msg_yDist_marker1 << "\n";
    double msg_zDist_marker1 = transform.getOrigin().z();
    cout << "marker1_z: " << msg_zDist_marker1 << "\n";

    double msg_linear_marker1 = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                   pow(transform.getOrigin().y(), 2));

    try{
      listener2.lookupTransform("/ar_marker_0", "/ar_marker_2",
                               ros::Time(0), transform2);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker2 = transform2.getOrigin().x();
    cout << "marker2_x: " << msg_xDist_marker2 << "\n";
    double msg_yDist_marker2 = transform2.getOrigin().y();
    cout << "marker2_y: " << msg_yDist_marker2 << "\n";
    double msg_zDist_marker2 = transform2.getOrigin().z();
    cout << "marker2_z: " << msg_zDist_marker2 << "\n";

    double msg_linear_marker2 = 0.5 * sqrt(pow(transform2.getOrigin().x(), 2) +
                                   pow(transform2.getOrigin().y(), 2));

    try{
      listener3.lookupTransform("/ar_marker_0", "/ar_marker_3",
                               ros::Time(0), transform3);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker3 = transform3.getOrigin().x();
    cout << "marker3_x: " << msg_xDist_marker3 << "\n";
    double msg_yDist_marker3 = transform3.getOrigin().y();
    cout << "marker3_y: " << msg_yDist_marker3 << "\n";
    double msg_zDist_marker3 = transform3.getOrigin().z();
    cout << "marker3_z: " << msg_zDist_marker3 << "\n";

    double msg_linear_marker3 = 0.5 * sqrt(pow(transform3.getOrigin().x(), 2) +
                                   pow(transform3.getOrigin().y(), 2));

    try{
      listener4.lookupTransform("/ar_marker_0", "/ar_marker_4",
                               ros::Time(0), transform4);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker4 = transform4.getOrigin().x();
    cout << "marker4_x: " << msg_xDist_marker4 << "\n";
    double msg_yDist_marker4 = transform4.getOrigin().y();
    cout << "marker4_y: " << msg_yDist_marker4 << "\n";
    double msg_zDist_marker4 = transform4.getOrigin().z();
    cout << "marker4_z: " << msg_zDist_marker4 << "\n";

    double msg_linear_marker4 = 0.5 * sqrt(pow(transform4.getOrigin().x(), 2) +
                                   pow(transform4.getOrigin().y(), 2));

    try{
      listener5.lookupTransform("/ar_marker_0", "/ar_marker_5",
                               ros::Time(0), transform5);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker5 = transform5.getOrigin().x();
    cout << "marker5_x: " << msg_xDist_marker5 << "\n";
    double msg_yDist_marker5 = transform5.getOrigin().y();
    cout << "marker5_y: " << msg_yDist_marker5 << "\n";
    double msg_zDist_marker5 = transform5.getOrigin().z();
    cout << "marker5_z: " << msg_zDist_marker5 << "\n";

    double msg_linear_marker5 = 0.5 * sqrt(pow(transform5.getOrigin().x(), 2) +
                                   pow(transform5.getOrigin().y(), 2));

    try{
      listener6.lookupTransform("/ar_marker_0", "/ar_marker_6",
                               ros::Time(0), transform6);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker6 = transform6.getOrigin().x();
    cout << "marker6_x: " << msg_xDist_marker6 << "\n";
    double msg_yDist_marker6 = transform6.getOrigin().y();
    cout << "marker6_y: " << msg_yDist_marker6 << "\n";
    double msg_zDist_marker6 = transform6.getOrigin().z();
    cout << "marker6_z: " << msg_zDist_marker6 << "\n";

    double msg_linear_marker6 = 0.5 * sqrt(pow(transform6.getOrigin().x(), 2) +
                                   pow(transform6.getOrigin().y(), 2));

    try{
      listener7.lookupTransform("/ar_marker_0", "/ar_marker_7",
                               ros::Time(0), transform7);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker7 = transform7.getOrigin().x();
    cout << "marker7_x: " << msg_xDist_marker7 << "\n";
    double msg_yDist_marker7 = transform7.getOrigin().y();
    cout << "marker7_y: " << msg_yDist_marker7 << "\n";
    double msg_zDist_marker7 = transform7.getOrigin().z();
    cout << "marker7_z: " << msg_zDist_marker7 << "\n";

    double msg_linear_marker7 = 0.5 * sqrt(pow(transform7.getOrigin().x(), 2) +
                                   pow(transform7.getOrigin().y(), 2));

    try{
      listener8.lookupTransform("/ar_marker_0", "/ar_marker_8",
                               ros::Time(0), transform8);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker8 = transform8.getOrigin().x();
    cout << "marker8_x: " << msg_xDist_marker8 << "\n";
    double msg_yDist_marker8 = transform8.getOrigin().y();
    cout << "marker8_y: " << msg_yDist_marker8 << "\n";
    double msg_zDist_marker8 = transform8.getOrigin().z();
    cout << "marker8_z: " << msg_zDist_marker8 << "\n";

    double msg_linear_marker8 = 0.5 * sqrt(pow(transform8.getOrigin().x(), 2) +
                                           pow(transform8.getOrigin().y(), 2));

    try{
      listener9.lookupTransform("/ar_marker_0", "/ar_marker_9",
                               ros::Time(0), transform9);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker9 = transform9.getOrigin().x();
    cout << "marker9_x: " << msg_xDist_marker9 << "\n";
    double msg_yDist_marker9 = transform9.getOrigin().y();
    cout << "marker9_y: " << msg_yDist_marker9 << "\n";
    double msg_zDist_marker9 = transform9.getOrigin().z();
    cout << "marker9_z: " << msg_zDist_marker9 << "\n";

    double msg_linear_marker9 = 0.5 * sqrt(pow(transform9.getOrigin().x(), 2) +
                                   pow(transform9.getOrigin().y(), 2));

    try{
      listener10.lookupTransform("/ar_marker_0", "/ar_marker_10",
                               ros::Time(0), transform10);
    }
    catch (tf::TransformException ex){
      ROS_ERROR("%s",ex.what());
      ros::Duration(1.0).sleep();
    }

    double msg_xDist_marker10 = transform10.getOrigin().x();
    cout << "marker10_x: " << msg_xDist_marker10 << "\n";
    double msg_yDist_marker10 = transform10.getOrigin().y();
    cout << "marker10_y: " << msg_yDist_marker10 << "\n";
    double msg_zDist_marker10 = transform10.getOrigin().z();
    cout << "marker10_z: " << msg_zDist_marker10 << "\n";

    double msg_linear_marker10 = 0.5 * sqrt(pow(transform10.getOrigin().x(), 2) +
                                   pow(transform10.getOrigin().y(), 2));

    //ros::Duration(2.5).sleep();

    /*if(msg_xDist>0.25){
        twist_msg.linear.x = -maxVelX;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "geri" << "\n";
    }
    else if(msg_xDist<-0.25){
        twist_msg.linear.x = maxVelX;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "ileri" << "\n";
    }
    else {
        twist_msg.linear.x = 0;
        pubVelocity.publish(twist_msg_hover);
        cout << "nothing1" << "\n";

    }



    if(msg_yDist>0.25){
        twist_msg.linear.y = -maxVelY;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "sola" << "\n";
    }
    else if(msg_yDist<-0.25){
        twist_msg.linear.y = maxVelY;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "saga" << "\n";
    }
    else {
        twist_msg.linear.y = 0;
        pubVelocity.publish(twist_msg_hover);
        cout << "nothing2" << "\n";
    }


    if(msg_zDist<-1.25){
        twist_msg.linear.z = -maxVelZ;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "asagi" << "\n";
    }
    else if(msg_zDist>0.75){
        twist_msg.linear.z = maxVelZ;
        pubVelocity.publish(twist_msg);
        ros::Duration(2.5).sleep();
        cout << "yukari" << "\n";
    }
    else {
        twist_msg.linear.z = 0;
        pubVelocity.publish(twist_msg_hover);
        cout << "nothing3" << "\n";
    }*/



    /*turtlesim::Velocity vel_msg;
    vel_msg.angular = 4.0 * atan2(transform.getOrigin().y(),
                                transform.getOrigin().x());
    vel_msg.linear = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) +
                                pow(transform.getOrigin().y(), 2));
    turtle_vel.publish(vel_msg);

    rate.sleep();*/
  }
  return 0;
};