#pragma once
#ifndef CS210PROJECTTHREE_CS210PROJECTTHREE_GROCER_H
#define CS210PROJECTTHREE_CS210PROJECTTHREE_GROCER_H

#include <iostream>
#include <map>

class Grocer {
	public:
		Grocer();
		void PrintSingleFrequency();
		void PrintAllFrequencies();
		void PrintAllFrequenciesHistogram();
	private:
		std::map<std::string, int> frequencyMap;
		void GenerateMap();
		void GenerateDataFile();
};

#endif