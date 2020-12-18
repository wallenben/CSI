/*
* @file vote.cpp
*
* @brief Contains the functions related to the vote class
* This file contains all functions pertaining to the vote
* class detailed in the header.
* This is mainly code from Lab09.
*
* @date 17 - Dec - 2020
* @author Ben Wallen
*/
#include "p3.h"
#include <string>
using namespace std;

string Vote::getOffice() const {
    return vOffice;
}
string Vote::getCandidate() const {
    return canidiateName;
}
bool Vote::wasInPerson() const {
    return voteMadeInPerson;
}
Vote::Vote(string vOffice2, string canidiateName2, bool voteMadeInPerson2) {
    if (vOffice2.empty() == true) {
        vOffice2 = "Unknown";
    }
    vOffice = vOffice2;
    if (canidiateName2.empty() == true) {
        canidiateName2 = "Write In";
    }
    canidiateName = canidiateName2;
    voteMadeInPerson = voteMadeInPerson2;
}