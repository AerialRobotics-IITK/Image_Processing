# Aruco_Dectection

[Source for aruco node installation](https://github.com/pal-robotics/aruco_ros) git clone the repository of aruco detection node

In catkin workspace
`catkin_make`

`source devel/setup.sh`

now edit launch file i.e. single.launch file in (catkin_ws/src/aruco_ros-kinetic-devel/aruco_ros/launch) and change the publisher and subscriber in it

`gedit single.launch` file and make changes

#### original file snippet

remap from="/camera_info" to="/stereo/$(arg eye)/camera_info" /

remap from="/image" to="/stereo/$(arg eye)/image_rect_color" /

#### changed snippet

remap from="/camera_info" to="/usb_cam/camera_info" /

remap from="/image" to="/usb_cam/image_raw" /

Now launch the usbcamera

`roslaunch usb_cam usb_cam-test.launch`

Now launch the launch file of aruco node with the MarkerId and markerSize

`roslaunch aruco_ros single.launch markerId:=40 markerSize:=0.1`

`rosrun rqt_image_view rqt_image_view`

select from dropdown /aruco_single/result

now place aruco marker before the camera. 

### Hurrah! its working . :) 
