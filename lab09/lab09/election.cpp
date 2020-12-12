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