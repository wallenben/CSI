#ifndef PRICEUPDATER_H_2020_11_30
#define PRICEUPDATER_H_2020_11_30
#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream> 
using namespace std;

double getAverage(double arrayOne[], int numVals);
double getMaximum(double arrayTwo[], int numVals2);
int updatePrices(double arrayThree[], int numVals3, double percentMarkup);
string arrayToString(double array[], int numValues);
int insertValue(double array[], int numVals, int maxSize, double insertVal);
int readData(istream& inputStream, double array[], int maxNum);
void processPrices(istream& inputStream, ostream& outputStream);

#endif