[source](http://wiki.ros.org/camera_calibration/Tutorials/MonocularCalibration)

Find the packages video_stream_opencv and cv_camera-master . It contains the required packages paste in source of catkin workspace. catkin_make it and source it.

Run the command in terminal

`sudo apt-get install ros-kinetic-image-pipeline`

`roscore`

goto catkin workspace source ./devel/setup.sh

`rosrun video_stream_opencv video_stream_video_stream_provider:="/dev/video0"`

`rosdep install camera_calibration`

Make sure that your monocular camera is publishing images over ROS. Let's list the topics to check that the images are published:

$ rostopic list

This will show you all the topics published, check to see that there is an image_raw topic. The default topics provided by most ROS camera drivers are:

    /camera
    /camera/image_raw

run this command

rosrun camera_calibration cameracalibrator.py --size 8x6(no of intersections in chessboard) --square 0.108(length of each block in meters) image:=/camera (the topic on which raw image is being published) camera

#USB CAMERA ADDITION

To add usb camera

`roscore

install usb_cam package

roscd usb_cam/launch

sudo vim usb_cam-test.launch`

Now change the name from dev/video0 to dev/video1 or something else

`roslaunch usb_cam usb_cam-test.launch` opens the camera

now the raw image is being published on usb_cam/image_raw

`rosrun camera_calibration cameracalibrator.py --size 8x6 --square 0.024 image:=/usb_cam/image_raw camera:=/usb_cam`

Now calibrate

the calibrated data is stored under home/[user]/.ros/camera info/head camera.yaml

Few errors that could effect calibrations -'size',uneven chessboard

To view the product ID , vendor ID and other information

`cd etc/udev/rules.d`
(The UDEV rules are to be added here)

`dmesg`
