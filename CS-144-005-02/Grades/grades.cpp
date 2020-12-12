#include "grades.h"
#include <sstream>

using namespace std;

int main() {
	stringstream input;

	input.str("96 88 42 4 53 27.3 0 99.9 ");

	double grades[50];
	double curvedGrades[50];
	
	int numGrades = readValues(input, grades, 50);

	copyValues(grades, curvedGrades, numGrades);

	cout << numGrades << "\n";
	printValues(cout, grades, numGrades);
	printValues(cout, curvedGrades, numGrades);
	cout << sumValues(grades, numGrades) << "\n";
	cout << "A: " << countValues(grades, numGrades, 90, 100) << "\n";
	cout << "B: " << countValues(grades, numGrades, 80, 89.999) << "\n";
	cout << "C: " << countValues(grades, numGrades, 70, 79.999) << "\n";
	cout << "D: " << countValues(grades, numGrades, 60, 69.999) << "\n";
	cout << "F: " << countValues(grades, numGrades, 0, 59.999) << "\n";

	return 0;
}



int readValues(std::istream& input, double data[], int maxSize) {
	int count = 0;
	double val;

	// loop until no more data or no more room
	input >> val;
	while (count < maxSize && input) {
		// read a value
		
		// put the value in the array
		data[count] = val;
		// count it
		count++;
		input >> val;
	}
	// return the count
	return count;
}

void printValues(std::ostream& output, double data[], int size) {

	for (int i = 0; i < size; i++) {
		output << data[i] << " ";
	}
	output << "\n";
}

double sumValues(double data[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += data[i];
	}

	return sum;
}


void copyValues(const double oldData[], double newData[], int size) {

	for (int i = 0; i < size; i++) {
		newData[i] = oldData[i];
	}

}


double minValues(double data[], int size) {
	double min;

	if (size <= 0) {
		return -1;
	}

	min = 101;
	//min = data[0];
	for (int i = 0; i < size; i++) {
		if (data[i] < min) {
			min = data[i];
		}
	}

	return min;
}



int countValues(double data[], int size, double min, double max) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (data[i] >= min && data[i] <= max) {
			count++;
		}
	}

	return count;
}


