/*
* @file election.cpp
*
* @brief Contains the functions related to the election class
* This file contains all functions pertaining to the election
* class detailed in the header. 
* This is mainly code from Lab09.
*
* @date 17 - Dec - 2020
* @author Ben Wallen
*/
#include "p3.h"
#include <string>
using namespace std;

Election::Election(string office2, string firstCanidiateName2, string secondCanidiateName2) {
    office = office2;
    firstCanidiateName = firstCanidiateName2;
    secondCanidiateName = secondCanidiateName2;
}

string Election::getOffice() const {
    return office;
}
string Election::getCandidate1() const {
    return firstCanidiateName;
}
string Election::getCandidate2() const {
    return secondCanidiateName;
}