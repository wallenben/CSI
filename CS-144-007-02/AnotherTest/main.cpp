/**
	@file main.cpp

	@brief Prints a message to the user.

	Prints a message to the user on the screen.

	@author Scott Turner
	@date 2020-09-22

*/

#include <iostream>

using namespace std;

/**  Conversion between inches and centimeters. */
const double INCHES_2_CM = 2.54;


/**
	@brief Prints a message to the user.

	Prints a message to the user on the screen.

	@return 0 on success, non-0 otherwise
*/
int main() {

	// "Help I'm trapped in a computer!" said the voice.
	// cout << "\"Help I'm trapped in a computer!\" \n\tsaid the voice.";

	// cout << endl;


	// variables
	// type name [ = value]
	double inchesReadIn;
	double cm;


	// input with prompt
	cout << "Enter the number of inches: ";
	cin >> inchesReadIn;
	// processing/calculations
	cm = inchesReadIn * INCHES_2_CM;
	// output
	cout << inchesReadIn << "in = " << cm << "cm\n";



	return 0;
}