#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;


int main() {
	// variables
	// distance (b)
	double distance;
	// pavers
	int pavers;
	// height
	double height;
	// angle
	double angle;
	// pavers per meter
	const int PAVER_PER_METER = 5;
	string name;
	char angleType;
	int unitType;

	cout << "Enter the building name: ";
	//cin >> name;
	cin >> ws;
	getline(cin, name);
	name = name.substr(0, 20);
	// input angle
	cout << "Enter the angle: ";
	cin >> angle;

	cout << "Is angle in degrees (d) or radians (r): ";
	cin >> angleType;

	// input paver count
	cout << "Enter the distance: ";
	cin >> pavers;
	cout << "Enter the units of measurement:\n"
		<< "\t 1. Pavers\n"
		<< "\t 2. Meters\n"
		<< "\t 3. Feet\n"
		<< "\t 4. Yards\n";
	cin >> unitType;

	switch (unitType) {
	case 1:
		// convert pavers
		distance = static_cast<double>(pavers) / PAVER_PER_METER;
		break;
	//case 2:
		// meters
	//	distance = pavers;
	//	break;
	case 3:
		// feet
		distance = pavers / 3.281;
		break;
	case 4:
		// yards
		distance = pavers / 1.093;
		break;
	// case 2:
	default:
		// ? - assume meters
		distance = pavers;
		break;
	}

	// hangle angle type
	if (angleType == 'd') {
		angle = angle * 3.1415 / 180;
	}

	// check angle
	// 0 < x < 10 -> 0 < x && x < 10
	if (angle <= 0 || angle >= 3.1415 / 2) {
		cout << "The angle is invalid.\n";
	}
	else {
		// calc b from pavers
		//distance = static_cast<double>(pavers) / PAVER_PER_METER;
		// calc h = b tan theta
		height = distance * tan(angle);

		// output the 
		cout << fixed << setprecision(2);
		cout << name << "\n";
		cout << left << setw(18) << "Angle (radians)" << right << setw(15) << angle << "\n";
		cout << left << setw(18) << "Pavers" << right << setw(15) << pavers << "\n";
		cout << left << setw(18) << "Distance to Base" << right << setw(15) << distance << "\n";
		cout << left << setw(18) << "Building Height" << right << setw(15) << height << "\n";
		cout << "\n";
	}

	return 0;
}



