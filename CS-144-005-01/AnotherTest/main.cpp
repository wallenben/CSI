/**
@file main.cpp

@brief Prints a useless message to the user.

Prints a useless message to the user because the instructor said so.

@author Scott Turner
@date 2020-09-21

*/
// TODO complete documentation
// TODO @brief
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/** Conversion from inches to centimeters  */
const double IN_2_CM = 2.54;

/**
	@brief Prints a useless message to the user.

	Prints a useless message to the user because the instructor said so.
	
	@return 0 on success and non-0 otherwise
*/
int main() {

	// The instructor repeated asked, "Any output ideas?"
	//cout << "The instructor repeated asked, \n\t\"Any output ideas?\"";

	//cout << "\n\n";

	// variables
	// type name [= value]
	double inchesIveReadIn;
	double cms;

	// input
	cout << "Enter the number of inches: ";
	cin >> inchesIveReadIn;
	// calculate/expression/conversion
	cms = inchesIveReadIn * IN_2_CM;
	// output
	cout << inchesIveReadIn << "in = " << cms << "cm\n";



	return 0;
}