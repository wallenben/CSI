#include <iostream>
#include <string>
// namespace? std 
//using namespace std;
using std::cout;
using std::string;

// place to start - main
int main() {

	// cout << "Pancakes!";

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




	// enum
	// normally go outside of main, near the top
	// or in a header file
	enum class LetterGrade {A = 4, B = 3, C = 2, D = 1, F = 0};

	LetterGrade myGrade;

	myGrade = LetterGrade::C;

	// prints the int associated with the value; 2 in this case
	cout << static_cast<int>(myGrade);

	// convert to string
	// normally in a separate function
	string gradeText;

	switch (myGrade) {
	case LetterGrade::A:
		gradeText = "A";
		break;
	case LetterGrade::B:
		gradeText = "B";
		break;
	case LetterGrade::C:
		gradeText = "C";
		break;
	case LetterGrade::D:
		gradeText = "D";
		break;
	case LetterGrade::F:
		gradeText = "F";
		break;

	}


	cout << gradeText;







	return 0;
}
