#ifndef GRADES_H_2020_11_10
#define GRADES_H_2020_11_10
#include <iostream>

// functions
int readValues(std::istream &input, double data[], int maxSize);
void printValues(std::ostream &output, double data[], int size);
// sum the grades in the used portion of the array
double sumValues(double data[], int size);
void copyValues(const double oldData[], double newData[], int size);
double minValues(double data[], int size);
int countValues(double data[], int size, double min, double max);


#endif 