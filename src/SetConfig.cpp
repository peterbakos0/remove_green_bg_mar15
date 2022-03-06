#include <string>
#include <cjson/cJSON.h>
#include "Config.hpp"
#include "ReadFile.hpp"
#include "SetConfig.hpp"

using namespace std;

void SetConfig()
{
	string rawConfig = ReadFile("config.json");

	cJSON* parsedConfig = cJSON_Parse(rawConfig.c_str());
	cJSON* currentEntry = parsedConfig->child;

	while(currentEntry != NULL)
	{
		string key = currentEntry->string;

		if(key == "mode")
		{
			config.mode = currentEntry->valuestring;
		}
		else if(key == "inPath")
		{
			config.inPath = currentEntry->valuestring;
		}
		else if(key == "outPath")
		{
			config.outPath = currentEntry->valuestring;
		}
		else if(key == "width")
		{
			config.width = currentEntry->valueint;
		}
		else if(key == "height")
		{
			config.height = currentEntry->valueint;
		}
		else if(key == "fps")
		{
			config.fps = currentEntry->valueint;
		}
		else if(key == "minH")
		{
			config.minH = currentEntry->valueint;
		}
		else if(key == "maxH")
		{
			config.maxH = currentEntry->valueint;
		}
		else if(key == "minS")
		{
			config.minS = currentEntry->valueint;
		}
		else if(key == "maxS")
		{
			config.maxS = currentEntry->valueint;
		}
		else if(key == "minV")
		{
			config.minV = currentEntry->valueint;
		}
		else if(key == "maxV")
		{
			config.maxV = currentEntry->valueint;
		}
		else if(key == "newR")
		{
			config.newR = currentEntry->valueint;
		}
		else if(key == "newG")
		{
			config.newG = currentEntry->valueint;
		}
		else if(key == "newB")
		{
			config.newB = currentEntry->valueint;
		}

		currentEntry = currentEntry->next;
	}
}
