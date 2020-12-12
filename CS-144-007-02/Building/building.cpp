#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;


int main() {
	// variables
	// pavers
	int pavers;
	// pavers per meter
	const int PAVERS_PER_METER = 5;
	// height
	double height;
	// angle
	double angle;
	// distance
	double distance;
	string buildingName;
	char angleType;
	int unitType;

	cout << "Enter the building name: ";
	// cin >> buildingName;
	cin >> ws;
	getline(cin, buildingName);
	// input angle
	cout << "Enter the angle: ";
	cin >> angle;
	cout << "Is the angle in degrees (d) or radians (r)? ";
	cin >> angleType;
	// input number of pavers
	cout << "Enter the distance: ";
	cin >> pavers;
	cout << "What is the unit? \n"
		<< "\t1. Pavers\n"
		<< "\t2. Meters\n"
		<< "\t3. Feet\n"
		<< "\t4. Yards\n";
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
		distance = pavers / 3.280;
		break;
	case 4:
		// yards
		distance = pavers * 0.9144;
		break;
	//case 2:
	default:
		// ?
		distance = pavers;
		break;
	}





	buildingName = buildingName.substr(0, 20);
	// what if not d or r
	if (angleType == 'd') {
		angle = angle * 3.1415 / 180;
	}

	if (angle > 0 && angle < 3.1415 / 2) {
		// calc distance from pavers
		//distance = static_cast<double>(pavers) / PAVERS_PER_METER;
		// calc h = b tan theta
		height = distance * tan(angle);

		// output
		cout << buildingName << "\n";
		cout << setprecision(3) << fixed;
		cout << left << setw(20) << "Angle (in radians)" << right << setw(10) << angle << "\n";
		cout << left << setw(20) << "Pavers" << setw(10) << right << pavers << "\n";
		cout << left << setw(20) << "Distance to Base" << right << setw(10) << distance << "\n";
		cout << left << setw(20) << "Building Height" << right << setw(10) << height << "\n";
	}
	else {
		cout << "The angle is invalid.\n";
	}


	

	return 0;
}









