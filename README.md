# Image_Processing
Computer Vision repository 

Course1: http://www.cse.psu.edu/~rtc12/CSE486/

## What is camera calibration and its need ?

### SOURCES

[Opencv Source](https://docs.opencv.org/3.1.0/dc/dbb/tutorial_py_calibration.html)

[Youtube Lecture](https://www.youtube.com/watch?v=fVJeJMWZcq8)

│fx 0 Cx│

│0 fy Cy│=Camera Matrix

|0.0 0.0 1|

For camera calibrations the camera is kept stationary while the image of chessboard is moved relative to camera .

#### What we mean by Camera Calibration?

For simplicity, we can assume that during the camera calibration , chess board was kept stationary in XY plane, (where Z=0 always) the x,y,z axes being fixed on the board and camera was moved relative to board. 

The image of board in real world can be assumed to be at Z=0. And a point on that on the board has a coordinate point (X,Y,Z).

Now the image of (X,Y,Z) is formed on the camera sensor. Let the pixel on sensor point(x,y,z) whose corresponding real world image be (X,Y,Z).


> fx : the ratio of the lenghts along X axis i.e. dimension of a object on camera sensor along X axis / dimension of real world object on plane Z=0 along X axis.

> fy : the ratio of the lenghts along Y axis i.e. dimension of a object on camera sensor along Y axis / dimension of real world object on plane Z=0 along Y axis

When we have to measure the cordinates of the light ray from an object at plane Z=0 which is falling on sensor at some point (x,y,z) on sensor .By default , the origin of coordinate axes (x,y,z) is at center of the sensor. But , for ease to measure the coordinates on camera sensor we need to measure the cx and cy not from the center of the sensor but from the leftmost and topmost position for clarity and easiness to manage data in matrix .So we need to shift the origin from center to topmost left the adjustmunts to be made are cx and cy in (x,y).

> cx : distance to be added in x coordinate of image's pixel for shifting the origin along x axis.

> cy : distance to be added in y coordinate of image's pixel for shifting the origin along y axis.
 
         
  |x| : │fx 0 Cx│ |X|
  
  |y| = │0 fy Cy│ |Y|
  
  |z| : |0.0 0.0  1 | |Z|
         
rightmost matrix |X,Y,Z| is matrix which represent a point in the real world

Using linear transformation we get a respective locations of real world point on the camera sensor where they are supposed to be. But as we can see that if there is some sort of misalignment between the camera feed and the mathematically determined position , then we can determine another matrix known as calibration matrix which applies a linear transformation on the camera feed and thus correcting our distortions in the feed.

#### Complete Camera Model

  |x| : │fx 0 Cx│ | f 0 0 0| |R t| |X|
  
  |y| = │0 fy Cy│ | 0 f 0 0| |0 1| |Y|
  
  |z| : |0 0  1 | | 0 0 1 0|       |Z|
  
the middle matrix is the matrix to turn point in the Real world into homogenous form.

The left is the camera matrix which linearly transforms the image formed on camera sensor and makes it free from any defects (radial or linear).

In the third matrix `R` is the rotation matrix.And t is the whereabouts the camera in the world.

We need to calculate this matrix by giving as much information as possible and finding the values of (fx,fy,cx,cy) 




#### Camera Calibration , The installation process?

## Installing and Calibrating camrea to get Camera Matrix

### Source

[source](http://wiki.ros.org/camera_calibration/Tutorials/MonocularCalibration)


### Installation
Find the packages video_stream_opencv and cv_camera-master . It contains the required packages paste in source of catkin workspace. 

Put those packages in the catkin workspace source and then catkin_make it and source the setup.sh file in devel folder.

Run the command in terminal

`sudo apt-get install ros-kinetic-image-pipeline`

`roscore`

goto catkin workspace 

`source ./devel/setup.sh`

`rosrun video_stream_opencv video_stream _video_stream_provider:="/dev/video0" `

`rosdep install camera_calibration`

Make sure that your monocular camera is publishing images over ROS. Let's list the topics to check that the images are published:

$ rostopic list

This will show you all the topics published, check to see that there is an image_raw topic. The default topics provided by most ROS camera drivers are:

    /camera
    /camera/image_raw

run this command to open the calibration window

`rosrun camera_calibration cameracalibrator.py --size 8x6(no of intersections in chessboard) --square 0.108(length of each block in meters) image:=/camera (the topic on which raw image is being published) camera`

#   WITH THE USB CAMERA

To add usb camera

`roscore`

`install usb_cam package`

`roscd usb_cam/launch`

`sudo vim usb_cam-test.launch`

Now change the name in launch file from dev/video0 to dev/video1 or something else

`roslaunch usb_cam usb_cam-test.launch` opens the camera

now the raw image is being published on usb_cam/image_raw

`rosrun camera_calibration cameracalibrator.py --size 8x6 --square 0.024 image:=/usb_cam/image_raw camera:=/usb_cam`

Now calibrate

> the calibrated data is stored under home/[user]/.ros/camera info/head camera.yaml

Few errors that could effect calibrations -'size',uneven chessboard try to avoid them

To view the product ID , vendor ID and other information of usbcam

`cd etc/udev/rules.d`



## Aruco detection

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

remap from="/image" to="/usb_cam/image_raw" /

### Launching nodes

Now launch the usbcamera

`roslaunch usb_cam usb_cam-test.launch`

Now launch the launch file of aruco node with the MarkerId and markerSize

`roslaunch aruco_ros single.launch markerId:=40 markerSize:=0.1`

`rosrun rqt_image_view rqt_image_view`

select from dropdown /aruco_single/result

now place aruco marker before the camera. 

### Hurrah! its working . :) 


