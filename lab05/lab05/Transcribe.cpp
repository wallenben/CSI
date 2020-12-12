/*
*
* @file Transcribe.cpp
*
* @brief Takes a user-inputted file and formats it in a different outputted file.
*
* This programs computes a new formatted file based off the user-given file.
*This is achieved through the use of loops, ifstreams, and ostreams
* Furthermore, this file also calculates the distance equation 
* after formatting the file.
* @date 3 - Nov - 2020
* @author Ben Wallen
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
/**
*@brief Takes a user-inputted file and formats it in a different outputted file.
*
* This programs computes a new formatted file based off the user-given file. This
* is achieved through the use of loops, ifstreams, and ostreams. Furthermore,
* this file also calculates the distance equation after formatting the file.

* @return 0 on non-error
*/
int main() {
	ifstream inFS;
	ofstream ofFS;
	int x1, y1, x2, y2;
	string fileName;
	string fileCheck;
	string fileName2;
	do {
		while (!inFS.is_open()) {
			cout << "Input the file name: ";
			cin >> fileName;
			inFS.open(fileName);
			if (!inFS.fail()) {
				cout << "Reading file ... ";
				cout << "Done" << endl;
			}
		}
	} while (!inFS.is_open());
	int length = fileName.length();
	length = length - 4;
	fileCheck = fileName.substr(fileName.size() - 4, 4);
	if (fileCheck == (".txt")) {
		fileName2 = fileName.substr(0, length) + ".log";
		ofFS.open(fileName2);
	}
	else if (fileCheck != (".txt")) {
		fileName2 = fileName + ".log";
		ofFS.open(fileName2);
	}
	if (inFS.is_open() && ofFS.is_open()) {
		while (inFS >> x1 >> y1 >> x2 >> y2) {
			double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
			ofFS << "(" << x1 << ", " << y1 << ")" << " : " <<
				"(" << x2 << ", " << y2 << ")" << " -> " << fixed <<
				setprecision(3) << distance << endl;
		}
		inFS.close();
		ofFS.close();
	}
	return 0;
}

