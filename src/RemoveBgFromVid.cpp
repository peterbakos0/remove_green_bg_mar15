#include <string>
#include <cmath>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "ImgBgRemover.hpp"
#include "RemoveBgFromVid.hpp"

using namespace std;
using namespace cv;

void RemoveBgFromVid(string vidPath, string vidOutPath)
{
	VideoCapture vid(vidPath);
	VideoWriter vidOut(vidOutPath, VideoWriter::fourcc('m','p','4','v'), config.fps, Size(config.width, config.height));

	int doneFrameCount = 0;
	int totalFrameCount = vid.get(CAP_PROP_FRAME_COUNT);

	Mat frame;
	ImgBgRemover* remover = new ImgBgRemover();

	while(true)
	{
		cout << "\rProcessing video " << vidPath << ": " << floor((float) doneFrameCount / (float) totalFrameCount * 100.0) << "%" << flush;

		vid >> frame;

		if(frame.empty())
		{
			break;
		}

		remover->RemoveBgFromImg(frame);

		vidOut.write(remover->imgOut);

		doneFrameCount++;
	}

	vid.release();
	vidOut.release();

	cout << endl << "Modified video was successfully saved as " << vidOutPath << endl;
}
