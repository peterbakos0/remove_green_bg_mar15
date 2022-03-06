#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "SetConfig.hpp"
#include "RemoveBgFromImg.hpp"
#include "RemoveBgFromVid.hpp"
#include "RemoveBgInDir.hpp"

using namespace cv;

Config config;

int main()
{
	SetConfig();

	if(config.mode == "dir")
	{
		RemoveBgInDir(config.inPath, config.outPath);
	}
	else if(config.mode == "vid")
	{
		RemoveBgFromVid(config.inPath, config.outPath);
	}
	else if(config.mode == "dev")
	{
		Mat img = imread(config.inPath);

		Mat imgOut = RemoveBgFromImg(img);

		imshow("img", img);
		waitKey(0);
	}

	return 0;
}
