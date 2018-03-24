#pragma once
#include <string>
#include <vector>
class Song
{
public:
	int speed, volume, energy, preference;
	std::string title, notes;
};

class Playlist
{
public:
	std::vector<int> playlist;
};

class Library
{
public:
	std::vector<Song> library;
};
