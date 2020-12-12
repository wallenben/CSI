// access other files #include 
#include <iostream>
#include <string>
// something std
//using namespace std;
using std::cout;
using std::string;

// main - starting point
int main() {

	//cout << "Bye World! ;(";



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
	//// outside of main, near the top
	//// or in a header file
	//enum class Grade {A = 4, B = 3, C = 2, D = 1, F = 0};

	//Grade myGrade;

	//myGrade = Grade::D;

	//// accesses the int value; prints a 1 in this case
	//cout << static_cast<int>(myGrade);


	//// normally in a function
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












	string myString = "kitty";
	string* strPtr;

	strPtr = &myString;

	cout << strPtr << " " << *strPtr << "\n";

	*strPtr = "Cat";

	cout << strPtr << " " << *strPtr << " " << myString << "\n";










	return 0;
}


