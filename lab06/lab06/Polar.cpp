/*
*
* @file Polar.cpp
*
* @brief Contains the functions necessary to do the polar coordinate equation.
*
* This programs contains functions necessary to run the polar coordinate equation
* (changing rectangular cooridnates to polar coordinates). These functions are then utilized
* when the function convertRectToPolar is ran.
* @date 10 - Nov - 2020
* @author Ben Wallen
*/

#include "lab6.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream> 
using namespace std;
/**
* @brief Calculates the value "r" for polar coordinates from standard XY coordinates.
* @param x x coordinate
* @param y y coordinate
* This function computes the value "r" for polar coordinates from
* standard XY coordinates. It outputs "r" as a double, which is the
* result of the function.
*
* Tests:
* Input (10,10):
* Expected Output: 14.1421
* Input (5,5):
* Expected Output: 7.07107
* Input (3,3):
* Expected Output: 4.24264
*/
double calculateR(double x, double y) {
	double r = sqrt(pow(x, 2) + pow(y, 2));
	return r;
}
/**
* @brief Calculates degrees based off radians.
* @param angle radian angle being converted
* This function computes the value in degrees for
* a given angle in radians. This is done by using PI
* (a constant) and an inputted angle by the user.
*
* Tests:
* Input (3.5):
* Expected Output: 200.535
* Input (1):
* Expected Output: 57.2958
* Input (2):
* Expected Output: 114.592
*/
double radToDegrees(double angle) {
	double degrees;
	const double CONST_PI = 3.14159265;
	degrees = (180 * angle) / CONST_PI;
	return degrees;
}
/**
* @brief Calculates theta in the polar equation
* @param x x coordinate
* @param y y coordinate
* This function computes the value "theta" for polar coordinates from
* standard XY coordinates. It outputs theta in radians initially,
* but calls to radToDegrees to convert the output into degrees, which
* becomes the result of the function.
*
* Tests:
* Input (2, 4):
* Expected Output: 63.43
* Input (1, 1):
* Expected Output: 45
* Input (1, -3):
* Expected Output: -71.57
*/
double calculateTheta(double x, double y) {
	double theta;
	double z;
	theta = atan2(y, x);
	z = radToDegrees(theta);
	if (z < 0) {
		z = z + 360;
	}
	return z;
}
/**
* @brief Formats points in (x,y) fashion
* @param x x coordinate
* @param y y coordinate
* This function takes two values and formats them into
* a more legible format. This is achieved by using stringstream
* ss, which allows the insertion of int variables into a string.
* This function returns the result in string coordinates.
*
* Tests:
* Input (3, 3):
* Expected Output: "(3.000, 3.000)"
* Input (1.325226, 7):
* Expected Output: "(1.325, 7.000)"
* Input (5, 18):
* Expected Output: "(18.682, 74.476)"
*/

string formatPoint(double x, double y) {
	string coordinates;
	stringstream ss;
	ss << "(" << fixed << setprecision(3) << x << ", " << fixed << setprecision(3) << y << ")";
	coordinates = ss.str();
	return coordinates;
}

/**
* @brief Gets a user-inputted variable after prompting the user.
* @param inputStream input method to input the number
* @param outputStream output method to output the prompt
* @param promptUser specific prompt for the outputStream
* This function prompts the user for a variable, and then
* stores that variable in a double.
*
*/

double getValue(istream& inputStream, ostream& outputStream, string promptUser) {
	double number;
	outputStream << promptUser;
	inputStream >> number;
	return number;
}

/**
* @brief Calculates polar coordinates based off rectangular coordinates.
* @param inputStream input method to input the number
* @param outputStream output method to output the prompt
* This function utilizes all the previous functions to calculate polar
* coordinates based off of rectangular coordinates. Most of the equations
* are processed by alternative functions, so this function is only really
* responsible for properly calling each function into place.
*
* Tests:
* Input (10, 15):
* Expected Output: "(18.028, 56.310)"
* Input (3, 7):
* Expected Output: "(7.616, 66.801)"
* Input (1, -3.2222):
* Expected Output: "(1.000, -3.222)"
*/

void convertRectToPolar(istream& inputStream, ostream& outputStream) {
	double x, y;
	double rec;
	double theta;
	string coordinates;
	x = getValue(inputStream, outputStream, "Input the x value: ");
	y = getValue(inputStream, outputStream, "Input the y value: ");
	if (inputStream.fail()) {
		outputStream << "Error: inputStream has failed.";
	}
	else {
		rec = calculateR(x, y);
		theta = calculateTheta(x, y);
		coordinates = formatPoint(x, y);
		outputStream << coordinates << " -> " << fixed << setprecision(3) << rec
			<< ", " << fixed << setprecision(3) << theta << endl;
	}

}
