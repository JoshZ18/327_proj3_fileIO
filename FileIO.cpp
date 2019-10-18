/*
 * FileReader.cpp
 *
 *  Created on: Oct 8, 2017
 *      Author: keith
 */
#include <iostream>
#include <fstream>
#include <string>
#include "../327_proj3_test/includes/FileIO.h"
#include "../327_proj3_test/includes/constants.h"

using namespace std;

//tries to open filename, and return its contents in contents
//it will strip out only \n's (char return\line feed)
//returns:
//SUCCESS all worked, contents string contains all in the file
//COULD_NOT_OPEN_FILE_TO_READ contents string is cleared
int KP_FileIO::getFileContents(const std::string &filename, std::string &contents)
{
	std::string file = filename;

	ifstream inputFile;
	inputFile.open(file.c_str());

	if (inputFile.is_open()) {
		while (!inputFile.eof()) {
			std::string line;
			getline(inputFile, line);

			int length = line.length();

			//Loops through every line in the file and parses out data
			for (int i = 0; i < length; i++) {
				std::string character = line.substr(i, 1);
				//Separates pieces by data based on ,
				if (character != "\n") {
					contents += character;
				}
			}
		}
		inputFile.close();
		return SUCCESS;
	}

	return COULD_NOT_OPEN_FILE_TO_READ;
}

//tries to open filename, and serialize  myEntryVector contents to it
//returns:
//SUCCESS all worked, filename contains myEntryVector strings
//COULD_NOT_OPEN_FILE_TO_WRITE
int KP_FileIO::writeVectortoFile(const std::string filename, std::vector<std::string> &myEntryVector)
{
	ofstream outputFile;
	std::string file = filename;
	outputFile.open(file.c_str());

	if (outputFile.is_open()) {
		for (int i = 0; i < myEntryVector.size(); i++) {
			outputFile << myEntryVector[i];
		}
		outputFile.close();
		return SUCCESS;
	}

	return COULD_NOT_OPEN_FILE_TO_READ;
}


