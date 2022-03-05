#include <opencv2/opencv.hpp>
#include "Rgb.hpp"
#include "Config.hpp"
#include "IsRgbGreen.hpp"
#include "ImgBgRemover.hpp"

using namespace cv;

ImgBgRemover::ImgBgRemover()
{
	pixStatuses = new int*[config.height];

	for(int i = 0; i < config.height; i++)
	{
		pixStatuses[i] = new int[config.width];
	}

	arePixStatusesReset = true;
}

void ImgBgRemover::RemoveBgFromImg(Mat img)
{
	this->img = img.clone();
	imgOut = img.clone();

	MakeSurePixStatusesAreReset();

	for(int i = 0; i < config.height; i++)
	{
		for(int j = 0; j < config.width; j++)
		{
			bool shallPaintGreen = CheckPix(j, i);

			if(!shallPaintGreen)
			{
				bool simplifyOverride;

				for(int k = 0; k < 2; k++)
				{
					simplifyOverride = false;

					for(int l = 1; l <= config.simplify; l++)
					{
						bool isPixGreen;

						if(k == 0)
						{
							isPixGreen = CheckPix(j - l, i);
						}
						else if(k == 1)
						{
							isPixGreen = CheckPix(j + l, i);
						}

						if(isPixGreen)
						{
							simplifyOverride = true;
							break;
						}
					}

					if(!simplifyOverride)
					{
						break;
					}
				}

				shallPaintGreen = simplifyOverride;
			}

			if(shallPaintGreen)
			{
				imgOut.at<Vec3b>(i, j) = Vec3b(config.newB, config.newG, config.newR);
			}
		}
	}

	GaussianBlur(imgOut, imgOut, Size(config.blur, config.blur), 0);

	arePixStatusesReset = false;
}

bool ImgBgRemover::CheckPix(int x, int y)
{
	return (CheckPixBasic(x, y) && (CheckPixBasic(x - config.kokarda, y) || CheckPixBasic(x + config.kokarda, y)));
}

bool ImgBgRemover::CheckPixBasic(int x, int y)
{
	if(x < 0 || x >= config.width || y < 0 || y >= config.height)
	{
		return false;
	}

	int* pixStatus = &pixStatuses[y][x];

	if(*pixStatus == 1)
	{
		return false;
	}
	else if(*pixStatus == 2)
	{
		return true;
	}

	Vec3b pix = img.at<Vec3b>(y, x);

	struct Rgb rgb;

	rgb.r = pix[2];
	rgb.g = pix[1];
	rgb.b = pix[0];

	bool isRgbGreen = IsRgbGreen(rgb);
	*pixStatus = isRgbGreen + 1;

	return isRgbGreen;
}

void ImgBgRemover::MakeSurePixStatusesAreReset()
{
	if(arePixStatusesReset)
	{
		return;
	}

	for(int i = 0; i < config.height; i++)
	{
		for(int j = 0; j < config.width; j++)
		{
			pixStatuses[i][j] = 0;
		}
	}

	arePixStatusesReset = true;
}
