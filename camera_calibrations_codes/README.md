[source](http://wiki.ros.org/camera_calibration/Tutorials/MonocularCalibration)

Find the packages video_stream_opencv and cv_camera-master . It contains the required packages paste in source of catkin workspace. catkin_make it and source it.

Run the command in terminal

sudo apt-get install ros-kinetic-image-pipeline

run roscore

goto catkin workspace source ./devel/setup.sh

rosrun video_stream_opencv video_stream_video_stream_provider:="/dev/video0"

rosdep install camera_calibration

Make sure that your monocular camera is publishing images over ROS. Let's list the topics to check that the images are published:

$ rostopic list

This will show you all the topics published, check to see that there is an image_raw topic. The default topics provided by most ROS camera drivers are:

    /camera
    /camera/image_raw

run this command

rosrun camera_calibration cameracalibrator.py --size 8x6(no of intersections in chessboard) --square 0.108(length of each block in meters) image:=/camera (the topic on which raw image is being published) camera:=
