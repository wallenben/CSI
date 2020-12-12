#ifndef GRADES_H_2020_11_09
#define GRADES_H_2020_11_09

#include <iostream>



// functions
int readData(std::istream &input, double values[], int maxSize);
void printData(std::ostream& output, double values[], int size);
// sum the entire used portion of the array
double sumData(double values[], int size);
void copyData(const double oldValues[], double newValues[], int size);
double minimumValue(double values[], int size);
int countGrades(double values[], int size, double low, double high);

#endif 