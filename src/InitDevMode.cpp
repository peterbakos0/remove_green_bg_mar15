#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "RemoveBgFromImg.hpp"
#include "InitDevMode.hpp"

#define WINDOW_NAME "dev"

using namespace cv;

Mat img;

void UpdateImgOnScreen(int, void*)
{
	Mat imgOut = RemoveBgFromImg(img);
	imshow(WINDOW_NAME, imgOut);
}

void InitDevMode()
{
	img = imread(config.inPath);
	UpdateImgOnScreen(0, 0);

	namedWindow(WINDOW_NAME);

	createTrackbar("minH", WINDOW_NAME, &config.minH, 179, UpdateImgOnScreen);
	createTrackbar("minS", WINDOW_NAME, &config.minS, 255, UpdateImgOnScreen);
	createTrackbar("minV", WINDOW_NAME, &config.minV, 255, UpdateImgOnScreen);

	createTrackbar("maxH", WINDOW_NAME, &config.maxH, 179, UpdateImgOnScreen);
	createTrackbar("maxS", WINDOW_NAME, &config.maxS, 255, UpdateImgOnScreen);
	createTrackbar("maxV", WINDOW_NAME, &config.maxV, 255, UpdateImgOnScreen);

	waitKey(0);
}
