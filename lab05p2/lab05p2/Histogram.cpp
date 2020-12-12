/*
*
* @file Histogram.cpp
*
* @brief Takes a user-inputted file translates the integers to symbols in an
* output file.
*
* This programs computes a user-inputted file contaninig integers,
* reads the integers, and outputs the integers (along with a matching
* amount of stars) into a user-specified output file.
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
* @brief Takes a user-inputted file translates the integers to symbols in an
* output file.
*
* This programs computes a user-inputted file contaninig integers,
* reads the integers, and outputs the integers (along with a matching
* amount of stars) into a user-specified output file.

* @return 0 on non-error
*/
int main() {
	string fileInput;
	string fileOutput;
	ifstream inFS;
	ifstream inFS2;
	ofstream ofFS;
	int num;
	cout << "Enter the input file name : ";
	cin >> fileInput;
	cout << endl;
	cout << "Enter the output file name: ";
	cout << endl;
	cin >> fileOutput;
	inFS.open(fileInput);
	inFS2.open(fileOutput);
	if (!inFS.fail() || !inFS2.fail()) {
		ofFS.open(fileOutput);
		while (inFS >> num) {
			ofFS << right << setw(5) << num << ": ";
			for (int i = 0; i < num; ++i) {
				ofFS << "*";
			}
			ofFS << "\n";
		}
		inFS.close();
		ofFS.close();
		cout << "success" << "\n";
	}
	else if (!inFS.is_open()) {
		cout << "error input" << endl;
	}
	else if (!ofFS.is_open()) {
		cout << "error output" << endl;
	}
	return 0;
}