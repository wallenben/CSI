#include "grades.h"
#include <fstream>


using namespace std;

int main() {
	ifstream input;
	input.open("gradeInput.txt");

	double grades[35];
	double curvedGrades[35];


	int numGrades = readGrades(input, grades, 35);

	copyGrades(grades, curvedGrades, numGrades);

	cout << numGrades << "\n";
	printGrades(cout, grades, numGrades);
	printGrades(cout, curvedGrades, numGrades);
	cout << sumGrades(grades, numGrades) << "\n";

	input.close();

	return 0;
}


int readGrades(std::istream& input, double data[], int maxSize) {
	int count = 0;
	double val;

	// loop until no more data or no more room
	input >> val;
	while (input && count < maxSize) {
		// get a value
		
		// put the value in the array
		data[count] = val;
		// count it
		count++;
		input >> val;
	}
	// return the count
	return count;
}


void printGrades(std::ostream& output, double data[], int size) {

	for (int i = 0; i < size; i++) {
		output << data[i] << " ";
	}
	output << "\n";

}


double sumGrades(double data[], int size) {
	double sum = 0;

	for (int i = 0; i < size; i++) {
		sum += data[i];
	}

	return sum;
}


void copyGrades(const double oldData[], double newData[], int size) {

	for (int i = 0; i < size; i++) {
		newData[i] = oldData[i];
	}

}





double findMinGrade(double data[], int size) {
	double min;

	if (size <= 0) {
		return -1;
	}

	min = data[0];
	for (int i = 0; i < size; i++) {
		if (data[i] < min) {
			min = data[i];
		}
	}

	return min;
}


int countGrades(double data[], int size, double low, double high) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (low <= data[i] && data[i] <= high) {
			count++;
		}
	}

	return count;
}





