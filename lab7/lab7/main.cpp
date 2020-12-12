#include "lab7.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

int main() {
    stringstream ss;
    double array[10];
    array[0] = 0.00;
    array[1] = 250.03;
    array[2] = 150.34;
    array[3] = 175;
    array[4] = 50.550;
    array[5] = 195;
    array[6] = 450.95;
    array[7] = 90.90;
    array[8] = 4;
    stringstream s;
    s << "0.05 250.0 150.3 175 0 50.55 195 450.95 90.90 ";
    processPrices(s, cout);
   // cout << readData(cin, array, 10);


}