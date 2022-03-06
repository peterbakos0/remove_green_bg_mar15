#include <string>
#include <vector>
#include "GetFilesInDir.hpp"
#include "GetFileStem.hpp"
#include "RemoveBgFromVid.hpp"
#include "RemoveBgInDir.hpp"

using namespace std;

void RemoveBgInDir(string dirPath, string dirOutPath)
{
	vector<string> vidPaths = GetFilesInDir(dirPath);

	for(unsigned i = 0; i < vidPaths.size(); i++)
	{
		string vidPath = vidPaths[i];

		string vidStem = GetFileStem(vidPath);
		string vidOutPath = dirOutPath + "/" + vidStem + "_MOD.mp4";

		RemoveBgFromVid(vidPath, vidOutPath);
	}
}
