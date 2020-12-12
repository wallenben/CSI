#include "Header.h"
#include <iostream>
using namespace std;
int main() {
    Ballot ballot1("WI-643UWO");
    const Vote* vote3 = ballot1.getVote(2);
    cout << vote3 << "\n";


}