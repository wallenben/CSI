#ifndef GRADE_H_2020_11_09
#define GRADE_H_2020_11_09
#include <iostream>

// functions


/**
@brief ...

@param input The stream to read from
@param
@param 

*/
int readArray(std::istream& input, double grades[], int maxSize);
void printArray(std::ostream& output, double grades[], int size);
// sums the entire used portion of the array
double sumArray(double grades[], int size);
void copyArray(const double oldGrades[], double newGrades[], int size);
double minArray(double grades[], int size);
int countArray(double grades[], int size, double low, double high);


#endif 