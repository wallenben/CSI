#include "grades.h"
#include <sstream>
#include <iostream>

using namespace std;

int main() {
	stringstream input;
	input.str("92 54 78 12 5 25 42 100 0 93");

	double grades[100];
	double curvedGrades[100];

	int numGrades = readArray(input, grades, 100);

	copyArray(grades, curvedGrades, numGrades);
	
	cout << numGrades << "\n";
	printArray(cout, grades, numGrades);
	printArray(cout, curvedGrades, numGrades);
	cout << "Sum: " << sumArray(grades, numGrades) << "\n";
	int aCount = countArray(grades, numGrades, 90, 100);


	return 0;
}


int readArray(std::istream& input, double grades[], int maxSize) {
	double val;
	int count = 0;
	// loop until no more data or  no more room
	input >> val;
	while (input && count < maxSize) {
		// read in value
		
		// put value in the array
		grades[count] = val;
		// count the number of values
		count++;
		input >> val;
	}
	// return the count
	return count;
}


void printArray(std::ostream& output, double grades[], int size) {

	for (int i = 0; i < size; i++) {
		output << grades[i] << " ";
	}
	output << "\n";
}

double sumArray(double grades[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}

	return sum;
}

void copyArray(const double oldGrades[], double newGrades[], int size) {

	for (int i = 0; i < size; i++) {
		newGrades[i] = oldGrades[i];
	}
}



double minArray(double grades[], int size) {
	double min;

	if (size <= 0) {
		return -1;
	}

	min = 101;
	//min = grades[0];
	for (int i = 0; i < size; i++) {
		if (min > grades[i]) {
			min = grades[i];
		}
	}

	return min;
}

int countArray(double grades[], int size, double low, double high) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (grades[i] >= low && grades[i] <= high) {
			count++;
		}
	}

	return count;
}

