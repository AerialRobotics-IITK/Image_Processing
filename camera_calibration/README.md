# SOURCE

[Opencv Source](https://docs.opencv.org/3.1.0/dc/dbb/tutorial_py_calibration.html)

[Youtube Lecture](https://www.youtube.com/watch?v=fVJeJMWZcq8)

│fx 0 Cx│

│0 fy Cy│=Camera Matrix

|0  0  1|

For camera calibrations the camera is kept stationary while the image of chessboard is moved relative to camera .

For simplicity, we can say chess board was kept stationary at XY plane, (where Z=0 always) the axis being fixed on the board and camera was moved relative to board. 

The image of board in real world can be assumed to be at Z=0. And a point on that plane has a coordinate point (X,Y,Z).

Now a image is formed on the camera sensor. Let the pixel on sensor point(x,y,z) whose corresponding real world image be (X,Y,Z).

fx : the ratio of the lenghts along X axis i.e. dimension of a object on camera sensor along X axis / dimension of real world object on plane Z=0 along X axis.

fy : the ratio of the lenghts along Y axis i.e. dimension of a object on camera sensor along Y axis / dimension of real world object on plane Z=0 along Y axis

When we have to measure the cordinates of the light ray from an object at plane Z=0 which is falling on sensor at some point (x,y,z) on sensor .Since currently we have the origin at center of the sensor. But , we need to measure the cx and cy not from the center of the sensor but from the leftmost top position for clarity and easiness to manage data in matrix .So we need to shift  the origin from center to topmost left the adjustmunts to be made are cx and cy in (x,y).

cx : distance to be added in x coordinate of image's pixel for shifting the origin along x axis.

cy : distance to be added in y coordinate of image's pixel for shifting the origin along y axis.
 
         
  |x| : │fx 0 Cx│ |X|
  
  |y| = │0 fy Cy│ |Y|
  
  |z| : |0 0  1 | |Z|
         
rightmost matrix |X,Y,Z| is matrix which represent a point in the real world


## Complete Camera Model

  |x| : │fx 0 Cx│ | f 0 0 0| |R t| |X|
  
  |y| = │0 fy Cy│ | 0 f 0 0| |0 1| |Y|
  
  |z| : |0 0  1 | | 0 0 1 0|       |Z|
  
the middle matrix is the matrix to turn point in the Real world into homogenous form.

> The left is the camera matrix which linearly transforms the image formed on camera sensor and makes it free from any defects (radial or linear).

In the third matrix `R` is the rotation matrix.And t is the whereabouts the camera in the world.

We need to calculate this matrix by giving as much information as possible and finding the values of (fx,fy,cx,cy) 
