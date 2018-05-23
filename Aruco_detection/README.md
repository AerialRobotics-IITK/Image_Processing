# Aruco_Dectection

[Source for aruco node installation](https://github.com/pal-robotics/aruco_ros) install aruco detection node

`catkin_make`

`source devel/setup.sh`

now edit launch file i.e. single.launch file (catkin_ws/src/aruco_ros-kinetic-devel/aruco_ros/launch) and change it

open single.launch file and make changes

#### original file snippet

remap from="/camera_info" to="/stereo/$(arg eye)/camera_info" /

remap from="/image" to="/stereo/$(arg eye)/image_rect_color" /

#### changed snippet

remap from="/camera_info" to="/usb_cam/camera_info" /

remap from="/image" to="/usb_cam/image_raw" /

 `roslaunch usb_cam usb_cam-test.launch`

`roslaunch aruco_ros single.launch markerId:=40 markerSize:=0.1`

`rosrun rqt_image_view rqt_image_view`

select from dropdown /aruco_single/result

now place aruco m cameraarker before the
