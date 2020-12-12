#include <iomanip>
#include <iostream>    
#include <cmath>
#include "Header.h"
using namespace std;

double wacky (int& a, double b) {
	double x = b - 1;
	b = x + a;
	int y = a * 2;
	a = static_cast<int>(b);
	cout << y - 2.5;
	return y - 2.5;
}
/**
Write a complete C++ program that will, in a while loop, read two int values from cin (you do not need to prompt the user). You should count the number of times that this loop has run (you will need a separate variable for that).  It should then call your formula function (the first value read in should be the first parameter to formula). Finally, it should print the result from formula using your printResult function (use cout for the output stream and your count for the int parameter). The loop should run until one of the values read in is 0.

Be sure to include:
•	Any preprocessor commands you need
•	A complete main function
•	Any variable declarations

Note: To receive full credit you must use the other functions you’ve written for this exam (where appropriate).  You may assume that they have been declared and defined correctly and that they work correctly.  (Hint: Remember to store or use the results of your functions.)
*/
int main() {
	int x, y;
	int loopTimes = 0;
	double result;
	do {
		loopTimes++;
		cin >> x;
		cin >> y;
		//doesn't mention what second param is -- assuming y
		result = formula(x, y);
		printResult(cout, loopTimes, result);
	} while (x != 0 || y != 0);
}
void printResult(ostream& outputStream, int lineNo, double value) {
	outputStream << fixed << right << setw(8) << lineNo << ":" << fixed << right << setw(8) << setprecision(2)
		<< value;
}

double formula(int x, int y) {
	double v;
	if (y != -5) {
		v = ((3 * x) - 5) / (y + 5);
	}
	else if (y == -5) {
		v = ((3 * x) - 5) / sqrt(2);
	}

	return v;
}


