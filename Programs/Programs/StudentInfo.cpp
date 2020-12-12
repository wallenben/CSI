/*
 *  @file StudentInfo.cpp
 *
 *  @brief Computes if a student is in good standing, or on probation based on GPA and credits.
 *
 * This programs computes the standing of a student through the GPA and credits inputted
 * by the student. It also figures out what class they are in, based on the credit amount
 * given. The program also has fallback procedures to prevent errors (negative GPA, credit
 * amount, etc.). The tables used to make these calculations are featured in the Lab04
 * PDF file.
 *
 *  @date 21-Oct-2020
 *  @author Ben Wallen
 */
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/**
 *  @brief Computes if a student is in good standing, or on probation based on GPA and credits.
 *
 * This programs computes the standing of a student through the GPA and credits inputted
 * by the student. It also figures out what class they are in, based on the credit amount
 * given. The program also has fallback procedures to prevent errors (negative GPA, credit
 * amount, etc.). The tables used to make these calculations are featured in the Lab04
 * PDF file.
 *
 * TESTS:
 * GPA 1.7, Credits 23
 * Output: GPA 1.7, Credits 23, Freshman on Probation
 *
 * GPA 2.35, Credits 40
 * Output: GPA 2.4, Credits 40, Sophomore in good standing
 *
 * GPA 4, Credits 99
 * Output: GPA 4.0, Credits 99, Senior in good standing
 *
 * GPA -3, Credits -60
 * Output: GPA 0.0, Credits 0, Freshman on Probation
 *
 * GPA 1.99, Credits 23
 * Output: GPA 2.0, Credits 23, Freshman on Probation
 *
 * @return 0 on non-error
 */

int main() {
	double GPA;
	int credits;
	const int MAX_FRESHMAN = 29;
	const int MAX_SOPHOMORE = 59;
	const int MAX_JUNIOR = 89;
	const int MIN_SENIOR = 90;
	string classLevel;
	string classStanding;
	cout << "Enter the GPA: ";
	cin >> GPA;
	if (GPA < 0.0 || GPA > 4.0) {
		GPA = 0.0;
	}
	cout << "Enter the number of credits completed: ";
	cin >> credits;
	if (credits < 0) {
		credits = 0;
	}
	if (credits <= 29) {
		classLevel = "Freshman";
	}
	else if (credits <= 59) {
		classLevel = "Sophomore";
	}
	else if (credits <= 89) {
		classLevel = "Junior";
	}
	else if (credits >= 90) {
		classLevel = "Senior";
	}
	if (credits <= 59 && GPA >= 2.0) {
		classStanding = "In good standing";
	}
	else if (credits >= 60 && GPA >= 2.5) {
		classStanding = "In good standing";
	}
	else { classStanding = "On probation"; }

	cout << "GPA: " << fixed << setprecision(1) << GPA << endl << "Credits: " << credits <<
		" (" << classLevel << ")" << endl << classStanding;
	return 0;
}