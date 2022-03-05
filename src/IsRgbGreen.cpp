#include "Rgb.hpp"
#include "Hsv.hpp"
#include "Config.hpp"
#include "Rgb2Hsv.hpp"
#include "IsRgbGreen.hpp"

bool IsRgbGreen(Rgb rgb)
{
	bool isRgbGreen;

	Hsv hsv = Rgb2Hsv(rgb);

	isRgbGreen = (
		hsv.h >= config.minH &&
		hsv.h <= config.maxH &&
		hsv.s >= config.minS &&
		hsv.s <= config.maxS &&
		hsv.v >= config.minV &&
		hsv.v <= config.maxV
	);

	return isRgbGreen;
}
