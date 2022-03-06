#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "SetConfig.hpp"
#include "RemoveBgFromVid.hpp"
#include "RemoveBgInDir.hpp"
#include "InitDevMode.hpp"

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
		InitDevMode();
	}

	return 0;
}
