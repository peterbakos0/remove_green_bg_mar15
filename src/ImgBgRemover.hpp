#ifndef REMOVEBGFROMIMG_HPP
#define REMOVEBGFROMIMG_HPP

#include <vector>
#include <opencv2/opencv.hpp>

class ImgBgRemover
{
public:
	ImgBgRemover();

	cv::Mat imgOut;

	void RemoveBgFromImg(cv::Mat img);
private:
	int** pixStatuses;
	bool arePixStatusesReset;
	cv::Mat img;

	bool CheckPix(int x, int y);
	bool CheckPixBasic(int x, int y);
	void MakeSurePixStatusesAreReset();
};

#endif
