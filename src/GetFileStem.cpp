#include <string>
#include <filesystem>
#include "GetFileStem.hpp"

using namespace std;
using namespace filesystem;

string GetFileStem(string filePath)
{
	string result = path(filePath).stem();
	return result;
}
