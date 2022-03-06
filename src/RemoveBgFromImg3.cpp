#include "Config.hpp"
#include <opencv2/opencv.hpp>

using namespace cv;

Mat RemoveBgFromImg3(Mat img)
{
	Mat imgOut = Mat(Size(config.width, config.height), CV_8UC3, Scalar(config.newB, config.newG, config.newR));

	Mat imgIn = img.clone();

	int blurKernelSize = 31;

	GaussianBlur(imgIn, imgIn, Size(blurKernelSize, blurKernelSize), 0, 0);
	blur(imgIn, imgIn, Size(blurKernelSize, blurKernelSize), Point(-1, -1));

	cvtColor(imgIn, imgIn, COLOR_BGR2HSV);

	Mat mask = Mat(config.width, config.height, CV_8UC1);

	Scalar lowerGreen(config.minH, config.minS, config.minV);
	Scalar upperGreen(config.maxH, config.maxS, config.maxV);

	int edKernelSize = 3;
	Mat edKernel = Mat(edKernelSize, edKernelSize, CV_8UC1, Scalar(1));

	inRange(imgIn, lowerGreen, upperGreen, mask);
	bitwise_not(mask, mask);

	erode(mask, mask, edKernel, Point(-1, -1), 8, 1, 1);
	dilate(mask, mask, edKernel, Point(-1, -1), 12, 1, 1);
	erode(mask, mask, edKernel, Point(-1, -1), 8, 1, 1);

	img.copyTo(imgOut, mask);

	return imgOut;
}
