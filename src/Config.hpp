#ifndef CONFIG_HPP
#define CONFIG_HPP

struct Config
{
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
	int kokarda;
	int simplify;
	int blur;
};

extern Config config;

#endif
