/**
* @file Formula.cpp
*
* @brief Calculates a formula and displays the output
*
* This computes a formula (xy+2/x^2+1) and displays the result. X and Y
* are inputs for the program.
*
* @author Ben Wallen
* @date 2020-10-07
*
*/

#include <iostream>
#include <iomanip>
using namespace std;
/**
*
* @brief Calculates a formula and displays the output
* This computes a formula (xy+2/x^2+1) and displays the result. X and Y
* are inputs for the program.
*
* Input: 3 , 5
* Output: 1.700
*
* Input: 5, 7
* Output: 1.423
*
* Input: 10, 30
* Output: 2.990
*
* Input: 0, 3
* Output: 2.000
*
* @return 0 on success
* */
int main() {
	int x;
	int y;
	cout << "Enter the value of x: ";
	cin >> x;
	cout << "Enter the value of y: ";
	cin >> y;
	double equation = double((x * y) + 2) / ((x * x) + 1);
	cout << "Using x = " << x << " and y = " << y << " ,the result is " << setprecision(4) << showpoint << equation;
	return 0;
}