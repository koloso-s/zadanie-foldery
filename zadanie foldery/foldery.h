#pragma once
#include <string>

class folder {
	std::string BASE_PATH;
	std::string current_path;
public:
	folder(std::string);
	void openFolder(std::string, std::string);
	void setCurrentPath(std::string);
	std::string getCurrentPath();
	void createFolder(std::string, std::string);
	void removeFolder(std::string, std::string);
	void renameFolder(std::string, std::string, std::string);
	void copy(std::string, std::string);
};