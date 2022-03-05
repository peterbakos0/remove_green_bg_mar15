#include <cmath>
#include <opencv2/opencv.hpp>
#include "Config.hpp"
#include "RemoveBgFromImg2.hpp"

using namespace cv;

void Flood(Mat* img, int x, int y);

void RemoveBgFromImg2(Mat* img)
{
	Flood(img, 0, 0);
}

void Flood(Mat* img, int x, int y)
{
	Vec3b me = img->at<Vec3b>(y, x);

	if(me[2] == 0 && me[1] == 255 && me[0] == 0)
	{
		return;
	}

	img->at<Vec3b>(y, x) = {0, 255, 0};

	for(int i = 0; i < 4; i++)
	{
		int x2;
		int y2;

		if(i == 0) // left
		{
			if(x <= 0)
			{
				continue;
			}

			x2 = x - 1;
			y2 = y;
		}
		else if(i == 1) // right
		{
			if(x >= config.width - 1)
			{
				continue;
			}

			x2 = x + 1;
			y2 = y;
		}
		else if(i == 2) // top
		{
			if(y <= 0)
			{
				continue;
			}

			x2 = x;
			y2 = y - 1;
		}
		else if(i == 3) // bottom
		{
			if(y >= config.height - 1)
			{
				continue;
			}

			x2 = x;
			y2 = y + 1;
		}

		Vec3b next = img->at<Vec3b>(y2, x2);

		int diff = abs(me[2] - next[2]) + abs(me[1] - next[1]) + abs(me[0] - next[0]);

		if(diff <= 10)
		{
			Flood(img, x2, y2);
		}
	}
}
