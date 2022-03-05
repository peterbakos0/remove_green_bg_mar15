#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "SetConfig.hpp"
#include "ImgBgRemover.hpp"
#include "RemoveBgFromVid.hpp"

using namespace cv;

Config config;

int main()
{
	SetConfig();

	RemoveBgFromVid(config.inVidPath, config.outVidPath);

	/*Mat frame = imread("../../imgs/frame.png");

	ImgBgRemover* remover = new ImgBgRemover();
	remover->RemoveBgFromImg(frame);

	imshow("frame", remover->imgOut);
	waitKey(0);*/

	return 0;
}
