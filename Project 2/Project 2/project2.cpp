/*
*
* @file Project2.cpp
*
* @brief Contains the functions necessary to perform an audit of files on a system.
*
* This file contains the functions necessary to peform an audit of files on a system.
* This is accomplished through eleven different functions, detailed below, and the
* main function ran is runAudit.
* @date 18 - Nov - 2020
* @author Ben Wallen
*/
#include "p2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

/**
*@brief checks to see if a file exists
*@param fileName is the name of the file
* This function is used in the main function to discover if a specific file
* exists or not. Because ofstreams create the file if they don't exist, only an ifstream
* can be used here.
*
*
* @return true on successful run
*/
bool fileExists(string fileName) {
	ifstream streamOne;
	streamOne.open(fileName);
	return !streamOne.fail();
}

/**
*@brief counts the bits in an unsigned integer
*@param intOne is the unsigned variable being counted
* This function is used in the main function to count the amount of
* bits in a specific unsigned integer. This becomes imperative throughout
* the program.
*
* Tests:
* Input: 5	Output: 2
* Input: 7	Output: 3
* Input: 1	Output: 1
*
* @return numberOfBits on successful run
*/
int countBits(unsigned intOne) {
	int numberOfBits = 0;
	unsigned intTwo = intOne;
	for (int i = 0; i < 12; ++i) {
		if (intTwo % 2 != 0) {
			++numberOfBits;
		}
		intTwo = intTwo / 2;
	}
	return numberOfBits;

}
/**
*@brief checks to see if a file is valid
*@param myEnum is the file's enum value used
*@param parityCode is the parity code from the file
* This function is used in the main function to verify
* if a file is valid or not. Because it is a boolean, the function returns
* true (valid) or false (not valid)
*
* Tests:
* Input: NONE, 7 Output: TRUE
* Input: EVEN (1) , 1	Output: TRUE
* Input: EVEN (1), 2	Output: FALSE
*
* @return valid on successful run
*/
bool isValidFile(ParityType myEnum, unsigned parityCode) {
	bool valid = 0;
	int bits = countBits(parityCode);
	if ((bits % 2 != 0) && (myEnum == ODD)) {
		valid = 1;
	}
	else if ((bits % 2 == 0) && (myEnum == EVEN)) {
		valid = 1;
	}
	else if (myEnum == NONE) {
		valid = 1;
	}
	return valid;
}
/**
* @brief takes two integers to create the archival level
* @param accessAmt is the number of acesses to the file
* @param fileSize is the size of the file
* Using the table provided, this function calculates the archival value.
* Access amount determines the base amount generally, but
* if the file > 1000, archivalLevel goes up by one.
*
* Tests:
* Input: 3, 1001 Output: 3
* Input: 33, 71 Output: 0
* Input: 11, 1500 Output: 2
*
* @return archivalLevel on successful run
*/
int getArchivalLevel(int accessAmt, int fileSize) {
	int archivalLevel;
	if ((accessAmt <= 2) && (accessAmt >= 0)) {
		archivalLevel = 3;
	}
	else if ((accessAmt <= 9) && (accessAmt >= 3)) {
		archivalLevel = 2;
	}
	else if ((accessAmt <= 19) && (accessAmt >= 10)) {
		archivalLevel = 1;
	}
	else if (accessAmt >= 20) {
		archivalLevel = 0;
	}

	if (fileSize > 1000) {
		++archivalLevel;
	}
	return archivalLevel;
}
/**
* @brief determines the parity level of the file
* @param fileName is the name of the file
* This function determines the parity level based off the filename
* and returns the appropiate ParityType.
*
* Tests:
* Input: awdawdaev Output: EVEN (1)
* Input: elephantod Output: ODD (0)
* Input: monky Output: NONE (2)
*
* @return x on successful run
*/
ParityType determineParity(string fileName) {
	ParityType x;
	string type = fileName.substr(fileName.size() - 2);
	if (type == "ev") {
		x = EVEN;
	}
	else if (type == "od") {
		x = ODD;
	}
	else {
		x = NONE;
	}
	return x;
}
/**
* @brief converts the enum ParityType to a legible string format
* @param x is the ParityType being converted.
* This function makes the ParityType enums more legible by converting them
* to a string. This becomes more prevalent in later functions.
* Tests:
* Input: 1 Output: Even Parity
* Input: 0 Output: Odd Parity
* Input: 2 Output: No Parity
*
* @return parityType on successful run
*/
string getParityString(ParityType x) {
	string parityType;
	switch (x) {
	case 0:
		parityType = "Odd Parity";
		break;

	case 1:
		parityType = "Even Parity";
		break;

	case 2:
		parityType = "No Parity";
		break;
	}
	return parityType;
}

/**
* @brief returns the amount of valid access dates
* @param inputRead is the input being read from
* This function calculates the valid access dates available, as
* only some dates are allowed. It then returns the number.
* Tests:
* Input: 1990-02-02 Output: 1
* Input: 1964-01-01 1990-02-02 1990-02-02 Output: 2
* Input: 3000-01-01 Output: 0
*
* @return countedDates on successful run
*/
int countAccesses(istream& inputRead) {
	int countedDates = 0;
	string x;
	do {
		if ((x >= "1990-01-01") && (x <= "2020-11-16")) {
			++countedDates;
		}
	} while ((inputRead >> x));


	return countedDates;
}

/**
* @brief processes file information and pushes the information to params
* @param inputRead is the input that is being read from
* @param fileName is the file name
* @param size is the size of the file
* @param accessCount is the access count for the file
* @param myEnum is the ParityType enum
* @param parityCode is the parity code being used
*
* This function compiles inputted information and splits the information into different params
* for further functionality. Furthermore, this function also checks to make sure that input streams don't
* fail, verifying the legitimacy of the variables being used.
*
* Tests (In theory -- technically, these are not outputted until printFileInfo prints and formats them):
* Input 1: awd215123.dat.od 1801 2805 1998-03-07
* Output: awd215123.dat, 1801, 4, Odd Parity
* Input 2: e0d.dat.od 1501 1805 1965-07-01
* Output: e0d.dat, 1501, 4, Odd Parity
* Input 3: 1zz.dat.ev 467 1001 2007-01-24 2003-06-22 3000-08-27 2002-02-02
* Output: 1zz.dat, 467, 2, Even Parity
*
* @return 1 on successful run
*/

bool processFileInfo (istream& inputRead, 
    string& fileName, int& size, int& accessCount, ParityType& myEnum, unsigned& parityCode) {
	string lineString;
	string fileNamex;
	int fileSize;
	int fileAccessCount;
	unsigned fileParityCode;
	getline(inputRead, lineString);
	stringstream streamOne(lineString);
	streamOne >> fileNamex;
	streamOne >> fileSize;
	streamOne >> fileParityCode;
	if (streamOne.fail()) {
		return 0;
	}
	else if (!streamOne.fail()) {
		fileName = fileNamex.substr(0, fileNamex.size() - 3);
		size = fileSize;
		accessCount = countAccesses(streamOne);
		myEnum = determineParity(fileNamex);
		parityCode = fileParityCode;
		return 1;
	}
}
/**
* @brief prints processed file informatin to an outputStream
* @param outputStream is the output that is being used
* @param fileName is the file name
* @param fileSize is the size of the file
* @param archivalValue is the archival value calculated from previous functions
* @param fileValid is the validity of the file
* @param fileParity is the enum of the file being used
*
* This funciton, (building off the previous function) compiles and writes the results in a nice
* legible format. This is accomplished from writing to params in the previous function, and the use
* of an outputStream. It also labels if a specific line is valid or not.
*
* Tests:
* Input 1: awd215123.dat.od 1801 2805 1998-03-07
* Output: *awd215123.dat             1801   4 Odd Parity
* Input 2: e0d.dat.od 1501 1805 1965-07-01
* Output: *e0d.dat                   1501   4 Odd Parity
* Input 3: 1zz.dat.ev 467 1001 2007-01-24 2003-06-22 3000-08-27 2002-02-02
* Output: 1zz.dat                    467   2 Even Parity
*/
void printFileInfo (ostream& outputStream, 
    string fileName, int fileSize, int archivalValue, bool fileValid, ParityType fileParity) {
	if (fileValid == 1) {
		outputStream << " ";
	}
	else if (fileValid == 0) {
		outputStream << "*";
	}
	outputStream << left << setw(20) << fileName << right << setw(10) << fileSize <<
		right << setw(4) << archivalValue << " " << getParityString(fileParity) << "\n";
}
/**
*@brief processes the files - reads and writes to both files being used
* @param inputFile is the file being inputted (read) from
* @param outputFile is the file being written to
*
* This function is in charge of actually writing the data mentioned above to specific files. Most of
* the calculations are offloaded to differnet functions, however.
*
*/
void processFiles(string inputFile, string outputFile) {
	ifstream inputStream;
	ofstream outputStream;
	string fileName;
	int size;
	int accessCount;
	ParityType myEnum;
	bool inputCheck = 0;

	unsigned parityCode;

	inputStream.open(inputFile);
	outputStream.open(outputFile);
	if ((!inputStream.fail()) && !outputStream.fail()) {
		outputStream << "File Audit" << endl;
		do {
			inputCheck = processFileInfo(inputStream, fileName, size, accessCount, myEnum, parityCode);
			if (inputCheck == 1) {
				printFileInfo(outputStream, fileName, size,
					getArchivalLevel(accessCount, size), isValidFile(myEnum, parityCode), myEnum);
			}
		} while ((!inputStream.fail()));


	}
	inputStream.close();
	outputStream.close();
}
/**
*@brief main function -- runs all other functions, in charge of inputting the input/output files
* @param inputRead is the input stream used to put in the name of the inputfile
* @param outputWrite is the output stream.
*
* This function is the catalyst for all the other functions in this program -- after the user
* inputs the names for both the input & the output files, this function runs processFiles, which
* essentially runs every other function this program has to offer.
*
*/
void runAudit(istream& inputRead, ostream& outputWrite) {
	string fileName;
	string outputFileName;
	outputWrite << "Enter the input file name: \n";
	inputRead >> fileName;
	if (fileExists(fileName) == true) {
		outputWrite << "Enter the output file name: \n";
		inputRead >> outputFileName;
		if (fileExists(outputFileName) == false) {
			processFiles(fileName, outputFileName);
		}
		else {
			outputWrite << "Error: Output file was found. \n";
		}
	}
	else if (fileExists(fileName) == false) {
		outputWrite << "Input file not found. \n";
	}
}