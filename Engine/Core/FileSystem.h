#pragma once
#include <string>

namespace nc {
	void SetFilePath(const std::string& pathName);
	bool ReadFileToString(const std::string& filename, std::string& filestring);
	std::string getFilePath();
}