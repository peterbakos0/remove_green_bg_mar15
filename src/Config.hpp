#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>

struct Config
{
	std::string mode;
	std::string inPath;
	std::string outPath;
	int width;
	int height;
	int fps;
	int minH;
	int maxH;
	int minS;
	int maxS;
	int minV;
	int maxV;
	int newR;
	int newG;
	int newB;
};

extern Config config;

#endif
