#include "Grocer.h"
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

//constructor
Grocer::Grocer() {
	GenerateMap(); //create map of input data
	GenerateDataFile(); //generate data file
};

//simple method to assist with graphical formatting
string FormatString(std::string init_string, int count) {
	string newString = "";
	for (int i = 0; i < count - init_string.size(); i++) {
		newString += " ";
	}
	newString += init_string;
	return newString;
}

//create a map object from the input file to more easily read data
void Grocer::GenerateMap(){
	ifstream inFS; //file stream
	std::string itemFromFile; //temp variable to hold data

	inFS.open("CS210_Project_Three_Input_File.txt");

	frequencyMap.clear(); //wipe map to avoid overwrites

	while (!inFS.eof()) { //check if end-of-file
		inFS >> itemFromFile; //read item from file

		if (frequencyMap.count(itemFromFile)) { //if the item has an entry in the map
			frequencyMap.at(itemFromFile)++; //increment the value
		}
		else { //if the item does not have an entry in the map
			frequencyMap.emplace(itemFromFile, 1); //add new entry
		}
	}
	inFS.close();
}

//print frequency of single item
void Grocer::PrintSingleFrequency() {
	std::string item;
	cout << "Enter a product name: ";
	cin >> item;
	if (frequencyMap.count(item)) {
		cout << frequencyMap.at(item) << endl;;
	}
	else {
		cout << "0" << endl;
	}
}

//print frequency information
void Grocer::PrintAllFrequencies() {
	//graphical formating
	cout << "******************************|*******" << endl;
	cout << "                         Item | Count " << endl;
	cout << "******************************|*******" << endl;

	//iterate through the map
	for (std::map<std::string, int>::iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { //code adapted from https://cplusplus.com/reference/map/map/begin
		//print each key (item) and value (frequency)
		cout << FormatString(it->first, 29) << " | " << it->second << endl;
	}

	cout << "******************************|*******" << endl;
}

//print frequency information as histogram
void Grocer::PrintAllFrequenciesHistogram() {
	//graphical formating
	cout << "******************************|********************" << endl;
	cout << "                         Item | Count " << endl;
	cout << "******************************|********************" << endl;

	//iterate through the map
	for (std::map<std::string, int>::iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { //code adapted from https://cplusplus.com/reference/map/map/begin
		//print each key (item)
		cout << FormatString(it->first, 29) << " | ";
		//print characters per the value of the map (frequency)
		for (int i = 0; i < it->second; i++) {
			cout << "#";
		}
		cout << endl;
	}

	cout << "******************************|********************" << endl;
}

//create frequency.dat file
void Grocer::GenerateDataFile() {
	ofstream outFS; //output file stream

	//open file
	outFS.open("frequency.dat");
	if (!outFS.is_open()) {
		cout << "ERROR. frequency.dat FILE WRITE FAILED";
		return;
	}

	//iterate through the map
	for (std::map<std::string, int>::iterator it = frequencyMap.begin(); it != frequencyMap.end(); ++it) { //code adapted from https://cplusplus.com/reference/map/map/begin
		//print each key (item) and value (frequency) to the file
		outFS << it->first << " " << it->second << endl;
	}

	outFS.close();
}