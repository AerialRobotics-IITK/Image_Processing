#SOURCE

[Opencv Source](https://docs.opencv.org/3.1.0/dc/dbb/tutorial_py_calibration.html)

┌       ┐
│fx 0 Cx│
│0 fy Cy│=Camera Matrix
|0 0  1 |
└       ┘

For camera calibrations the camera is kept stationary while the image is moved relative to camera.

For simplicity, we can say chess board was kept stationary at XY plane, (so Z=0 always) and camera was moved accordingly. 

The image in real world can be assumed to be at Z=0. And a point on that plane has a coordinate point (X,Y,Z).

fx : the ratio of the lenghts along X axis i.e. dimension on camera sensor / dimension of real world object on plane Z=0. 

fy : the ratio of the lenghts along Y axis i.e. dimension on camera sensor / dimension of real world object on plane Z=0.

When we have to measure the cordinates of the light ray from an object at plane Z=0 which is falling on sensor at some point (x,y,z) . Now , we need to measure the cx and cy not from the center of the sensor but from the leftmost top position .So we need to shift  the origin from center to topmost left.

cx : distance to be added in x axis for shifting the origin along x axis.

cy : distance to be added in y axis for shifting the origin along y axis.
 
        ┌       ┐ 
  |x|   │fx 0 Cx│ |X|
  |y| = │0 fy Cy│ |Y|
  |z|   |0 0  1 | |Z|
        └       ┘ 
rightmost matrix is matrix which represent a point in the real world


##Complete Camera Model

\begin{bmatrix}x\\y\\z\end{bmatrix}=\begin{bmatrix}fx & 0 & cx\\0 & fy & cy\\0 & 0 & 1 \end{bmatrix}	\begin{bmatrix}f & 0 & 0 & 0\\0 & f & 0 & 0\\0 & 0 & 1 & 0 \end{bmatrix}	\begin{bmatrix} R & t \\0 & 1 \end{bmatrix}-1	\begin{bmatrix}X\\Y\\Z \end{bmatrix}

 
        ┌       ┐ 
  |x|   │fx 0 Cx│ | f 0 0 0| |R t| |X|
  |y| = │0 fy Cy│ | 0 f 0 0| |0 1| |Y|
  |z|   |0 0  1 | | 0 0 1 0|       |Z|
        └       ┘ 

the middle matrix is the point in the worlld turned into homogenous form.

The left is the homogenous point in pixels i.e. scaling the real world image according to the size.

In the third matrix `R` is the rotation matrix.And t is the where is the camera in the world.
