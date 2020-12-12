#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	// variables
	// angle
	double angle;
	// pavers
	int pavers;
	// pavers per meter
	const int PAVERS_PER_METER = 5;
	// height
	double height;
	// distance
	double distance;
	string buildingName;
	char angleType;
	int unitType;

	// input angle
	cout << "Enter the building name: ";
	// cin >> buildingName;
	cin >> ws;
	getline(cin, buildingName);
	cout << "Enter the angle: ";
	cin >> angle;
	cout << "Is the angle in degrees (d) or radians (r)? ";
	cin >> angleType;
	// input pavers
	cout << "Enter the distance: ";
	cin >> pavers;
	cout << "What is the unit?\n"
		<< "\t1. Pavers\n"
		<< "\t2. Meters\n"
		<< "\t3. Feet\n"
		<< "\t4. Yards\n";
	cin >> unitType;

	buildingName = buildingName.substr(0, 20);

	if (angleType == 'd') {
		angle = angle * 3.1415 / 180;
	}

	switch (unitType) {
	case 1:
		// convert pavers
		distance = static_cast<double>(pavers) / PAVERS_PER_METER;
		break;
	//case 2:
		// meters
	////	distance = pavers;
	//	break;
	case 3:
		// feet
		distance = pavers * 0.3048;
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





	
	if (angle <= 0 || angle >= 3.1415 / 2) {
		cout << "The angle is invalid.\n";
	}
	else {
		// calc distance from pavers
		//distance = static_cast<double>(pavers) / PAVERS_PER_METER;
		// calc h = b tan theta
		height = distance * tan(angle);

		// output 
		cout << fixed << setprecision(2);
		cout << buildingName << "\n";
		cout << left << setw(25) << "Angle (in radians):" << right << setw(20) << angle << "\n";
		cout << left << setw(25) << "Pavers:" << setw(20) << right << pavers << "\n";
		cout << left << setw(25) << "Distance to Building:" << right << setw(20) << distance << "\n";
		cout << left << setw(25) << "Building Height: (m)" << right << setw(20) << height << "\n";
		cout << "\n";
	}



	return 0;
}







