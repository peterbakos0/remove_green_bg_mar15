#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "SetConfig.hpp"
#include "RemoveBgFromImg.hpp"
#include "RemoveBgFromVid.hpp"

using namespace cv;

Config config;

int main()
{
	SetConfig();

	RemoveBgFromVid(config.inVidPath, config.outVidPath);

	/*
	Mat frame = imread("../../imgs/whatever.png");

	Mat frameOut = RemoveBgFromImg(frame);

	imshow("frame", frameOut);
	waitKey(0);
	*/

	return 0;
}
