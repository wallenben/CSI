#ifndef GRADE_H_2020_11_10
#define GRADE_H_2020_11_10

#include <iostream>

// functions
int readGrades(std::istream &input, double data[], int maxSize);
void printGrades(std::ostream& output, double data[], int size);
// sum all of grades in the used portion of the array
double sumGrades(double data[], int size);
void copyGrades(const double oldData[], double newData[], int size);
double findMinGrade(double data[], int size);
int countGrades(double data[], int size, double low, double high);

#endif 