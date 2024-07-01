/*
* Robert Dickens
* 6/23/2024
* CS 210
* Project Three
*/

// Create data file
// Menu





#include "Grocer.h"
#include <iostream>
using namespace std;

int main() {
	Grocer storeData;
	bool repeat = true;
	int options;

	cout << "Corner Grocer Item Tracker" << endl;
	cout << "----------------------------------------" << endl;

	while (repeat) {
		cout << "1. Search frequency of a single item." << endl;
		cout << "2. List frequencies of all items." << endl;
		cout << "3. Print Histogram of item frequencies." << endl;
		cout << "4. Exit Program." << endl;
		cout << "----------------------------------------" << endl;
		cout << "Input choice: ";
		cin >> options;
		if (options == 1) { //Op1: Input item, Print Word Frequency
			storeData.PrintSingleFrequency();
		}
		else if (options == 2) { //Op2: Print Frequency of all items purchased from file
			storeData.PrintAllFrequencies();
		}
		else if (options == 3) { //Op3: Print same frequency as histogram
			storeData.PrintAllFrequenciesHistogram();
		}
		else if (options == 4) { //Op4: Exit Program
			repeat = false;
		}
		else {
			cout << "Input invalid. Please try again." << endl;
		}
		cout << endl;
	}

	return -1;
}