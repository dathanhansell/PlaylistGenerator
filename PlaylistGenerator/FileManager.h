#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "Playlist.h"
class FileManager
{
public:
	Library LoadFromFile(std::string asFileName);
	FileManager();
	~FileManager();
};

