#include "FileSystem.h"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <SDL.h>

namespace nc {

	void nc::SetFilePath(const std::string& pathName)
	{
		std::filesystem::current_path(pathName);
	}

	std::string nc::getFilePath()
	{
		return std::filesystem::current_path().string();
	}

	bool ReadFileToString(const std::string& filename, std::string& filestring)
	{
		std::ifstream fileStream(filename, std::ios::in);
		if (!fileStream.is_open())
		{
			SDL_Log("Error: Failed to open file: %s", filename.c_str());
			return false;
		}

		std::stringstream stream;
		stream << fileStream.rdbuf();
		filestring = stream.str();

		fileStream.close();

		return true;
	}

}