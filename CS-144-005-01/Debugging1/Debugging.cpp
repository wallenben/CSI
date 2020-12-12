#include <iostream>
#include <iomanip>
using namespace std;



/* tests
 *  Input: 0, 0, 1, 1 -> slope: 1
 *  Input: 0, 0, 1, -1 -> slope: -1
 *  Input: 0, 0, 1, 0 -> slope: 0
 *  Input: 0, 0, 0, 1 -> slope: 0
 *
 */

int main()
{
	int x1;
	int x2;
	int y1;
	int y2;
	int rise;
	int run;
	double slope;

	cout << "Enter the first point as x y: ";
	cin >> x1 >> y1;

	cout << "Enter the second point as x y: ";
	cin >> x2 >> y2;

	rise = y2 - y1;
	run = x2 - x1;

	slope = static_cast<double>(rise) / run; //TODO fix this: division by zero

	cout << setprecision(2) << right;
	cout << "The slope of the line between (" 
		<< x1 << ", " << y1 
		<< ") and (" << x2 << ", " << y2 
		<< ") is " << slope << "\n\n";
	
	return 0;
}
