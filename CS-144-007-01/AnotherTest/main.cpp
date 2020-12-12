/**
	@file main.cpp

	@brief Prints a sarcastic message.

	Prints a sarcatic message to the screen.

	@author Scott Turner
	@date 2020-09-21
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


//conversion value
/** Conversion value for inches to centimeters  */
const double INCHES_2_CM = 2.54;



/**	
	@brief Prints a sarcastic message.

	Prints a sarcatic message to the screen.

	@return 0 if successful, non-0 otherwise
*/
int main() {

	// What a "wonderful" day!
	//cout << "What a \n\t\"wonderful\" \nday!";

	//cout << endl;

	//variables
	// type name [= value]
	//inches
	double inchReadIn;
	//cm
	double cm;

	//input
	cout << "Enter the number of inches: ";
	cin >> inchReadIn;
	//calculations/processing
	cm = inchReadIn * INCHES_2_CM;
	//output
	cout << inchReadIn << "in = " << cm << "cm\n";

	return 0;
}
