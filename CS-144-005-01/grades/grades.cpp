#include "grades.h"
#include <sstream>

using namespace std;



int main() {
	stringstream input;
	input.str("87 72 40 100 2 65 50 80");

	double grades[100];
	double curvedGrades[100];

	int numGrades = readData(input, grades, 100);

	copyData(grades, curvedGrades, numGrades);


	cout << numGrades << "\n";
	printData(cout, grades, numGrades);
	cout << "\n";
	printData(cout, curvedGrades, numGrades);
	cout << "\n";
	cout << "Sum: " << sumData(grades, numGrades) << "\n";

	return 0;
}



int readData(std::istream& input, double values[], int maxSize) {
	double val;
	int count = 0;
	// loop while there is data to read and room in the array
	// arrays start at 0
	input >> val;
	while (input && count < maxSize) {
		// read a value
		
		// put the value in the array
		values[count] = val;
		// count the value
		count++;
		input >> val;
	}
	// return the count
	return count;
}

void printData(std::ostream& output, double values[], int size) {

	for (int i = 0; i < size; i++) {
		output << values[i] << " ";
	}

}

double sumData(double values[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += values[i];
	}

	return sum;
}


void copyData(const double oldValues[], double newValues[], int size) {

	for (int i = 0; i < size; i++) {
		newValues[i] = oldValues[i];
	}
}


double minimumValue(double values[], int size) {
	double min;

	if (size == 0) {
		return -1;
	}

	min = values[0];
	for (int i = 0; i < size; i++) {
		if (values[i] < min) {
			min = values[i];
		}
	}

	return min;
}


int countGrades(double values[], int size, double low, double high) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (values[i] >= low && values[i] <= high) {
			count++;
		}
	}
	return count;
}