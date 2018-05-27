// This program waits for the clear service to be available
// (potentially waiting for turtlesim to start up), and
// clears the screen.
#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "try_togglecam");
  ros::NodeHandle nh;

  // Wait until the clear service is available, which
  // indicates that turtlesim has started up, and has
  // set the background color parameters.
  //ros::service::waitForService("clear");  //this is optional

  // Get turtlesim to pick up the new parameter values.
  ros::ServiceClient clearClient
    = nh.serviceClient<std_srvs::Empty>("/ardrone/togglecam");
  std_srvs::Empty srv;
  clearClient.call(srv);
}