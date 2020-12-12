/**
* Ben Wallen
* 10/8/2020
*/

#include <iostream>;
#include <cstdlib>;
using namespace std;

int main() {
	int x;
	int y;
	const double NUM_3 = 3.5;
	cout << "Please input x" << endl;
	cin >> x;
	cout << "Please input y" << endl;
	cin >> y;
	cout << abs((pow (x, 3)) - NUM_3) + 2 * y;
}
