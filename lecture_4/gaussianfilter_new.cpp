#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core.hpp"
#include<iostream>
#include<cmath>

using namespace std;
using namespace cv;

cv::Mat getGaussianKernel(int rows, int cols, double sigmax, double sigmay )
    {
        cv::Mat kernel = cv::Mat::zeros(rows, cols, CV_32FC1);

        float meanj = (kernel.rows-1)/2,
              meani = (kernel.cols-1)/2,
              sum = 0,
              temp= 0;

        double sigma=2*sigmay*sigmax;
        for(unsigned j=0;j<kernel.rows;j++)
            for(unsigned i=0;i<kernel.cols;i++)
            {
                temp = exp( ((j)*(j) + (i)*(i))  / (2*sigma*sigma));
                if (temp > 0)
                    kernel.at<float>(j,i) = 1.0/(temp*2*3.14*sigma*sigma);

                sum += kernel.at<float>(j,i);
            }
        if(sum != 0)
            return kernel;
        else return cv::Mat();
    }


int main(int argc,char** argv)
{
    Mat src = imread( "/home/pence/aerialrobotics/cpp_test/lena.jpg" );
    Mat dst;//=Mat::zeros(src.rows,src.cols,CV_32FC1);
    imshow("original",src);
    dst=src.clone();
    vector<Mat> rgb;
    split(src, rgb);

    Mat kernel = getGaussianKernel(5,5,1.5,1);

    for (int y = 5; y < dst.rows - 5; y++) {
    for (int x = 5; x < dst.cols - 5; x++) {
        float sum1 = 0.0;
        float sum2 = 0.0;
        float sum3 = 0.0;
        for (int j = 0; j <= 5;j++) {
            for (int k = 0; k <= 5; k++) {
                sum1 = sum1 + kernel.at<float>(j ,k ) * (rgb[0].at<uchar>(y - j, x - k)+rgb[0].at<uchar>(y+j,x+k));
                sum2 = sum2 + kernel.at<float>(j ,k ) * (rgb[1].at<uchar>(y - j, x - k)+rgb[1].at<uchar>(y+j,x+k));
                sum3 = sum3 + kernel.at<float>(j ,k ) * (rgb[2].at<uchar>(y - j, x - k)+rgb[2].at<uchar>(y+j,x+k));
            }
        }
        // cerr<<dst.at<float>(y,x)<<endl;
        Vec3b sum= dst.at<Vec3b>(y,x);
        sum[0]=sum1;
        sum[1]=sum2;
        sum[2]=sum3;
        dst.at<Vec3b>(y,x)=sum;

    }
    }
    cout<<kernel<<endl;
    imshow("filtered",dst);
    waitKey(0);
}
