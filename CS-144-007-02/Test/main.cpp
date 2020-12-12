#include <iostream>
#include <string>
// namespace?
//using namespace std;
using std::cout;
using std::string;

// starting place - main
int main() {

	//cout << "Just don't do Hello World.";





	//int age = 0;
	//string group;

	//if (age >= 0 && age <= 2) {
	//	group = "Baby";
	//}
	//// TODO finish



	// enum
	// normally declare enum outside of main near the top
	// or in a header file
	enum class Grade {A = 4, B = 3, C = 2, D = 1, F = 0};

	Grade myGrade;

	myGrade = Grade::A;

	// prints the int associated with the Grade; in this case 4
	cout << static_cast<int>(myGrade);


	// separate function
	string gradeText;

	switch (myGrade) {
	case Grade::A: 
		gradeText = "A";
		break;
	case Grade::B:
		gradeText = "B";
		break;
	case Grade::C:
		gradeText = "C";
		break;
	case Grade::D:
		gradeText = "D";
		break;
	case Grade::F:
		gradeText = "F";
		break;


	}


	cout << gradeText;



	return 0;
}
