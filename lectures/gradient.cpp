#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
  Mat img,smoothed_plane,gradient_field;
  img= imread("/home/pence/aerialrobotics/images.jpeg", IMREAD_GRAYSCALE);

//img is a gray-scale image
Mat abs_grad_x, abs_grad_y, grad,grad_x,grad_y;
Mat g_img;
int ddepth = CV_16S;
int scale = 1;
int delta = 0;

cvtColor(img,g_img,CV_GRAY2BGR);
int image_height=190;
int image_width=266;

namedWindow("Gradient Vector Field",WINDOW_AUTOSIZE);

smoothed_plane = Mat::zeros(image_height,image_width,CV_8UC1);
gradient_field = Mat::zeros(image_height,image_width,CV_32FC2);

// Smooth the dominant plane by convolution with a Gaussian
GaussianBlur(img,smoothed_plane,Size(51,51),image_height*image_width*0.5);

/// Morphological opening (remove small objects from the foreground)
erode(smoothed_plane, smoothed_plane, getStructuringElement(MORPH_ELLIPSE, Size(40+1,40+1)));
dilate(smoothed_plane, smoothed_plane, getStructuringElement(MORPH_ELLIPSE, Size(40, 40)));
/// Morphological closing (fill small holes in the foreground)
dilate(smoothed_plane, smoothed_plane, getStructuringElement(MORPH_ELLIPSE, Size(40, 40)));
erode(smoothed_plane, smoothed_plane, getStructuringElement(MORPH_ELLIPSE, Size(40, 40)));

imshow("Eroded plane",smoothed_plane);

Scharr(smoothed_plane,grad_x,ddepth,1,0,scale);
Scharr(smoothed_plane,grad_y,ddepth,0,1,scale);

for (int i = 0 ; i < image_height ; i ++){
    for (int j = 0 ; j < image_width ; j ++){
        Scalar xval = grad_x.at<float>(i,j);
        Scalar yval = grad_y.at<float>(i,j);
        gradient_field.at<Point2f>(i,j) = Point2f(xval.val[0],yval.val[0]);
    }
}

for (int i = 0 ; i < image_height ; i += 20){
    for (int j = 0 ; j < image_width ; j+= 20){
        Point2f p(j,i);
        Point2f p2(gradient_field.at<Point2f>(p)+p);
        arrowedLine(g_img,p,p2,Scalar(0,0,255),1.5,8,0,0.1);
    }
}//*/

imshow("Gradient Vector Field", g_img);
waitKey(0);
}
