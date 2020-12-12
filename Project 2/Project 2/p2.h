#ifndef P2_H_2020_11_18
#define P2_H_2020_11_18
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

/**Different types of possible Parities */
enum  ParityType { ODD, EVEN, NONE };
bool fileExists(string fileName);
int countBits(unsigned intOne);
bool isValidFile(ParityType myEnum, unsigned parityCode);
int getArchivalLevel(int accessAmt, int fileSize);
ParityType determineParity(string fileName);
string getParityString(ParityType x);
int countAccesses(istream& inputRead);
bool processFileInfo(istream& inputRead, string& fileName, int& size, int& accessCount, ParityType& myEnum,
	unsigned& parityCode);
void printFileInfo(ostream& outputStream, string fileName, int fileSize, int archivalValue, bool fileValid
	, ParityType fileParity);
void processFiles(string inputFile, string outputFile);
void runAudit(istream& inputRead, ostream& outputWrite);
#endif // P2_H_2020_11_18