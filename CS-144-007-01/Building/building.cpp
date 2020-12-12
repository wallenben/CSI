#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;


int main() {
	// variables
	// pavers
	int pavers;
	// angle
	double angle;
	// height
	double height;
	// distance
	double distance;
	// pavers per meter
	const int PAVERS_PER_METER = 5;
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
	cout << "Is the angle in degrees (d) or radians (r): ";
	cin >> angleType;
	// input paver count
	cout << "Enter the distance: ";
	cin >> pavers;
	cout << "Enter the units\n"
		<< "\t 1. Pavers\n"
		<< "\t 2. Meters\n"
		<< "\t 3. Feet\n"
		<< "\t 4. Yards\n";
	cin >> unitType;

	switch (unitType) {
	case 1:
		// convert pavers
		distance = static_cast<double>(pavers) / PAVERS_PER_METER;
		break;
	//case 2:
		// meters
	//	distance = pavers;
	//	break;
	case 3:
		// feet
		distance = pavers / 3.28;
		break;
	case 4:
		// yards
		distance = pavers / 1.093;
		break;
	//case 2:
	default:
		// ?
		distance = pavers;
		break;
	}

	if (angleType == 'd') {
		angle *= 3.1415 / 180;
	}

	if (angle <= 0 || angle >= 3.1415 / 2) {
		cout << "The angle is invalid.\n";
	}
	else {
		// calc meters from pavers
		//distance = static_cast<double>(pavers) / PAVERS_PER_METER;
		// h = b tan theta
		height = distance * tan(angle);

		// output
		cout << name << "\n";
		cout << fixed << setprecision(2);
		cout << left << setw(20) << "Angle (in radians) " << right << setw(15) << angle << "\n";
		cout << left << setw(20) << "Pavers " << right << setw(15) << pavers << "\n";
		cout << left << setw(20) << "Distance to the Base" << right << setw(15) << distance << "\n";
		cout << left << setw(20) << "Building Height " << right << setw(15) << height << "\n";
		cout << endl;
	}

	return 0;
}





