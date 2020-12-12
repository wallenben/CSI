#ifndef POLAR_H_2020_11_10
#define POLAR_H_2020_11_10

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;


double calculateR(double x, double y);
double radToDegrees(double angle);
double calculateTheta(double x, double y);
string formatPoint(double x, double y);
double getValue(istream& inputStream, ostream& outputStream, string promptUser);
void convertRectToPolar(istream& inputStream, ostream& outputStream);


#endif // POLAR_H_2020_11_10