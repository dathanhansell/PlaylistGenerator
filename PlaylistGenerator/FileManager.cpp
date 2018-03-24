#include "stdafx.h"
#include "FileManager.h"

using namespace std;

FileManager::FileManager()
{
}


FileManager::~FileManager()
{
}

Library FileManager::LoadFromFile(string asFileName) {
	ifstream file;
	Library library;
	file.open(asFileName);
	if (!file.is_open()) {
		cout << "Couldn't Open File " << asFileName << endl;
		return library;
	}
	Song current;
	
	while (file.peek() != EOF)
	{
		char line[128];
		char tit[255];
		file.getline(line, sizeof(line));
		if (line[0] == '#') continue;
		sscanf_s(line, "%s ;%d;%d;%d;%d", tit , 255, &current.speed, &current.volume, &current.energy, &current.preference);
		current.title = tit;
		library.library.push_back(current);
		/*
		cout << current.title << ":" << endl;
		cout << "Speed:" << current.speed << endl;
		cout << "Volume:" << current.volume << endl;
		cout << "Energy:" << current.energy << endl;
		cout << "Preference:" << current.preference << endl << endl;
		*/
	}
	file.close();
	cout << "Loaded File: " << asFileName << " with " << library.library.size() << " songs." << endl;
	return library;
}
