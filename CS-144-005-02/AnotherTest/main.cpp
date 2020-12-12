/**
	@file main.cpp

	@brief Prints waffles for the user.

	Prints waffles for the user to the screen.

	@author Scott Turner
	@date 2020-09-22
*/


#include <iostream>

using namespace std;


/** Conversion value for inches to centimeters   */
const double IN_2_CM = 2.54;

/**
	@brief Prints waffles for the user.

	Prints waffles for the user to the screen.

	@return 0 on success, non-0 otherwise
*/
int main() {

	// "Waffles?" he asked.
	// cout << "\t\"Waffles?\" he asked before the \nstudent got it right.";

	//cout << endl;

	// variables
	// type name [ = value ]
	double inchesReadIn;
	double cm;

	// input with prompt
	cout << "Enter the number of inches: ";
	cin >> inchesReadIn;

	// processing/calculation
	cm = inchesReadIn * IN_2_CM;
	// output
	cout << inchesReadIn << "in = " << cm << "cm\n";

	return 0;
}




