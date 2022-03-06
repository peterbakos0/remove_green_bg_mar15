#include <string>
#include <vector>
#include <filesystem>
#include "GetFilesInDir.hpp"

using namespace std;
using namespace filesystem;

vector<string> GetFilesInDir(string dirPath)
{
	vector <string> result;

	for(const auto &entry : directory_iterator(dirPath))
	{
		result.insert(result.begin(), entry.path());
	}

	return result;
}
