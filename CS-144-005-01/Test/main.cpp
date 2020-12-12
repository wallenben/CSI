#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
// using namespace std;
using namespace std;

// starting point - main function
int main() {

	//cout << "All of Pie.";
	// std::cout << "All of Pie.";


	/*int age = 0;
	string group;
	if (age < 0) {
		group = "Invalid";
	}
	else {
		if (age <= 2) {
			group = "Baby";
		}
		else {
			if (age <= 12) {
				group = "Child";
			}
			else {
				if (age <= 19) {
					group = "Teenager";
				}
				else {
					if (age <= 64) {
						group = "Adult";
					}
					else {
						group = "Old Person";
					}
				}
			}
		}
	}*/



	//// enums
	//// declaring outside of main
	//// or in a header file
	//enum class Grade { A = 4, B = 3, C = 2, D = 1, F = 0 };

	//Grade myGrade;

	//myGrade = Grade::B;


	//// print the int value - in this case 3
	//cout << static_cast<int>(myGrade);


	//// normally do this (in a function)
	//string gradeText;

	//switch (myGrade) {
	//case Grade::A:
	//	gradeText = "A";
	//	break;
	//case Grade::B:
	//	gradeText = "B";
	//	break;
	//case Grade::C:
	//	gradeText = "C";
	//	break;
	//case Grade::D:
	//	gradeText = "D";
	//	break;
	//case Grade::F:
	//	gradeText = "F";
	//	break;
	//}


	//cout << gradeText;




	//stringstream money;
	//double val = 4.0;
	//string moneyStr;


	//cout << val << " "; // 4
	//// $4.00
	//money << "$" << fixed << setprecision(2) << val;
	//money >> moneyStr;
	//cout << moneyStr; // $4.00
















	string myString = "Test String";
	string* strPtr;

	strPtr = &myString;

	cout << strPtr << " " << *strPtr;

	*strPtr = "Not a Test String";


	cout << strPtr << " " << *strPtr << " " << myString;










	return 0;
}