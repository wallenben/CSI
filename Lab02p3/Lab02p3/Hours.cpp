/**
* @file Hours.cpp
*
* @brief Calculates how many hours are in a given amount of seconds.
*
* This computes how many hours are in a user specified
* amount of seconds. After the user inputs the amount
* of seconds, The program will display the inputted seconds
* and the equivalent amount of hours, in a decimal form.
*
* @author Ben Wallen
* @date 2020-09-30
*
*/
#include <iostream>
using namespace std;

/** @brief Calculates how many hours are in a given amount of seconds.
*
* This computes how many hours are in a user specified
* amount of seconds. After the user inputs the amount
* of seconds, The program will display the inputted seconds
* and the equivalent amount of hours, in a decimal form.
*
*
* @return 0 is sucessful, non-0 on error
*
*
* Input:
* Seconds: 30
* Expected: 0.00833333 hours
*
*
* Input:
* Seconds: 3601
* Expected: 1.00028 hours
*
*
* Input:
* Seconds: 42000
* Expected: 11.667 hours
*
*
*
*/
int main() {
	int seconds;
	double hours = 0.0;
	const int MAX_SEC = 3600;
	cout << "Input the number of seconds: ";
	cin >> seconds;
	hours = ((double)seconds / MAX_SEC);
	cout << endl << "Number of seconds: " << seconds << endl << "Number of hours: " << hours;
	return 0;
}
