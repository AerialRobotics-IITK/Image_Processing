# Aruco_Dectection

### Source

[Source for aruco node installation](https://github.com/pal-robotics/aruco_ros) git clone the repository of aruco detection node

[aruco_ros a summary](https://github.com/pal-robotics/aruco_ros)

[launch file creation](https://github.com/AerialRobotics-IITK/Wiki/wiki/launch-files)

In catkin workspace
`catkin_make`

`source devel/setup.sh`


### Changes made in code

now edit launch file i.e. single.launch file in (catkin_ws/src/aruco_ros-kinetic-devel/aruco_ros/launch) and change the publisher and subscriber in it

`gedit single.launch` file and make changes

* camera_info needs your calibration parameters

* image need image from your camera .... probably \usb_cam\image_raw

#### original file snippet

remap from="/camera_info" to="/stereo/$(arg eye)/camera_info" /

remap from="/image" to="/stereo/$(arg eye)/image_rect_color" /

#### changed snippet

remap from="/camera_info" to="/usb_cam/camera_info" /

remap from="/image" to="/usb_cam/image_rect_color" /

### Launching nodes

Now launch the usbcamera

`roslaunch usb_cam usb_cam-test.launch`

`rosrun image_proc image_proc`

Now launch the launch file of aruco node with the MarkerId and markerSize

`roslaunch aruco_ros single.launch markerId:=40 markerSize:=0.1`

`rosrun rqt_image_view rqt_image_view`

select from dropdown /aruco_single/result

now place aruco marker before the camera. 

### Hurrah! its working . :) 
