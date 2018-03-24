#include "stdafx.h"
#include "Parser.h"
#include <algorithm>
#include <math.h>
#include <iostream>
//bool sortByEng(const Song &lhs, const Song &rhs, bool reverse = false) { return reverse ? lhs.energy < rhs.energy : lhs.energy > rhs.energy; }
bool sortByPref(const Song &lhs, const Song &rhs) { return lhs.preference < rhs.preference; }
bool sortByEng(const Song &lhs, const Song &rhs) { return lhs.energy < rhs.energy; }
bool sortByVol(const Song &lhs, const Song &rhs) { return lhs.volume < rhs.volume; }
bool sortByTemp(const Song &lhs, const Song &rhs) { return lhs.speed < rhs.speed; }
Library& Parser::EnergySort(Library& in) {
	std::sort(in.library.begin(), in.library.end(), sortByEng);
	for (Song &n : in.library)
		//std::cout << n.title << ": " << n.energy << std::endl;
		return in;
}
Library& Parser::Triangle(Library& in) {
	in = EnergySort(in);
	std::vector<int> first, second;
	for (int x = 1; x < in.library.size(); x += 2) {
		first.push_back(x);
		second.push_back(x - 1);
	}
	if (in.library.size() % 2 != 0) second.push_back(in.library.size() - 1);
	Library copy = in;
	int quotient=0;
	for (int x = 0; x < first.size(); x++) {
		in.library[first[x]] = copy.library[first[x]];
		if (in.library[first[x]].energy != quotient) {
			std::cout << std::endl;
			quotient = in.library[first[x]].energy;
		}
		std::cout << in.library[first[x]].title << ": " << in.library[first[x]].energy << std::endl;
	}
	for (int x = second.size() - 1; x > -1; x--) {
		in.library[second[x]] = copy.library[second[x]];
		if (in.library[second[x]].energy != quotient) {
			std::cout << std::endl;
			quotient = in.library[second[x]].energy;
		}
		std::cout << in.library[second[x]].title << ": " << in.library[second[x]].energy << std::endl;
	}
	return in;
}