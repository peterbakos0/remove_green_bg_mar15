#include <sys/resource.h>
#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "SetConfig.hpp"
#include "ImgBgRemover.hpp"
#include "RemoveBgFromImg2.hpp"
#include "RemoveBgFromImg3.hpp"
#include "RemoveBgFromVid.hpp"

using namespace cv;

Config config;

int main()
{
	SetConfig();

	//RemoveBgFromVid(config.inVidPath, config.outVidPath);

	Mat frame = imread("../../imgs/whatever.png");

	/*rlimit re;
	getrlimit(RLIMIT_STACK, &re);

	re.rlim_cur = re.rlim_max;

	setrlimit(RLIMIT_STACK, &re);*/

	//RemoveBgFromImg2(&frame);

	//ImgBgRemover* remover = new ImgBgRemover();
	//remover->RemoveBgFromImg(frame);

	//imshow("frame", remover->imgOut);

	Mat outframe = RemoveBgFromImg3(frame);


	imshow("frame", outframe);
	waitKey(0);

	return 0;
}
