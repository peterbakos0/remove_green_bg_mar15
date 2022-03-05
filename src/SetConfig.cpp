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
		int value = currentEntry->valueint;

		if(key == "width")
		{
			config.width = value;
		}
		else if(key == "height")
		{
			config.height = value;
		}
		else if(key == "fps")
		{
			config.fps = value;
		}
		else if(key == "minH")
		{
			config.minH = value;
		}
		else if(key == "maxH")
		{
			config.maxH = value;
		}
		else if(key == "minS")
		{
			config.minS = value;
		}
		else if(key == "maxS")
		{
			config.maxS = value;
		}
		else if(key == "minV")
		{
			config.minV = value;
		}
		else if(key == "maxV")
		{
			config.maxV = value;
		}
		else if(key == "newR")
		{
			config.newR = value;
		}
		else if(key == "newG")
		{
			config.newG = value;
		}
		else if(key == "newB")
		{
			config.newB = value;
		}
		else if(key == "kokarda")
		{
			config.kokarda = value;
		}
		else if(key == "simplify")
		{
			config.simplify = value;
		}
		else if(key == "blur")
		{
			config.blur = value;
		}

		currentEntry = currentEntry->next;
	}
}
