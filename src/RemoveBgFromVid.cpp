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
	cout << vidPath << " => " << vidOutPath << endl;

	VideoCapture vid(vidPath);
	VideoWriter vidOut(vidOutPath, VideoWriter::fourcc('m','p','4','v'), config.fps, Size(config.width, config.height));

	int doneFrameCount = 0;
	int totalFrameCount = vid.get(CAP_PROP_FRAME_COUNT);

	Mat frame;
	ImgBgRemover* remover = new ImgBgRemover();

	while(true)
	{
		cout << "\rProgress: " << floor((float) doneFrameCount / (float) totalFrameCount * 100.0) << "%" << flush;

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

	cout << endl << "DONE!" << endl;
}
