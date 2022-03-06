#include <string>
#include <ctime>
#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "RemoveBgFromImg.hpp"
#include "RemoveBgFromVid.hpp"

using namespace std;
using namespace cv;

void RemoveBgFromVid(string vidPath, string vidOutPath)
{
	cout << vidPath << " => " << vidOutPath << endl;

	VideoCapture vid(vidPath);
	VideoWriter vidOut(vidOutPath, VideoWriter::fourcc('m','p','4','v'), config.fps, Size(config.width, config.height));

	int doneFrameCount = 0;
	int totalFrameCount = vid.get(CAP_PROP_FRAME_COUNT);

	Mat frame;

	while(true)
	{
		cout << "\rProgress: " << floor((float) doneFrameCount / (float) totalFrameCount * 100.0) << "%" << flush;

		vid >> frame;

		if(frame.empty())
		{
			break;
		}

		Mat frameOut = RemoveBgFromImg(frame);

		vidOut.write(frameOut);

		doneFrameCount++;
	}

	vid.release();
	vidOut.release();

	cout << endl << "Merging audio" << endl;

	string tmpAudVidOutPath = "/tmp/" + to_string(time(0)) + "_TMPAUDVID.mp4";

	string mergeAudCmd = "ffmpeg -loglevel quiet -i " + vidOutPath + " -i " + vidPath + " -c copy -map 0:v:0 -map 1:a:0 " + tmpAudVidOutPath;
	system(mergeAudCmd.c_str());

	string cleanUpCmd = "rm " + vidOutPath + " && mv " + tmpAudVidOutPath + " " + vidOutPath;
	system(cleanUpCmd.c_str());

	cout << "DONE!" << endl;
}
