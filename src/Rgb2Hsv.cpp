#include <algorithm>
#include <cmath>
#include "Rgb.hpp"
#include "Hsv.hpp"
#include "Rgb2Hsv.hpp"

using namespace std;

Hsv Rgb2Hsv(Rgb rgb)
{
	Hsv result;

	double rd = rgb.r / 255.0;
	double gd = rgb.g / 255.0;
	double bd = rgb.b / 255.0;

	double cMin = min(rd, min(gd, bd));
	double cMax = max(rd, max(gd, bd));

	double cDiff = cMax - cMin;
 
	if(cMax == cMin)
	{
		result.h = 0;
	}
	else if (cMax == rd)
	{
		result.h = lround(60 * ((gd - bd) / cDiff) + 360) % 360;
	}
	else if (cMax == gd)
	{
		result.h = lround(60 * ((bd - rd) / cDiff) + 120) % 360;
	}
	else if (cMax == bd)
	{
		result.h = lround(60 * ((rd - gd) / cDiff) + 240) % 360;
	}

	if(cMax == 0)
	{
		result.s = 0;
	}
	else
	{
		result.s = (cDiff / cMax) * 100;
	}

	result.v = cMax * 100;

	return result;
}
