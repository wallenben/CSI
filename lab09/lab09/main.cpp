#include "p3.h"
#include <string>
#include <iostream>

int main() {
    Ballot ballot1("WI-643UWO");
    //try get the 3rd vote
    //vote3 needs to start with const since
    //getVote returns a const pointer
    const Vote* vote3 = ballot1.getVote(2);
    //should be nullptr (0) since there are no votes yet
    cout << vote3 << "\n";
    //add a vote
    ballot1.recordVote("President", "Ferb", false);
    vote3 = ballot1.getVote(0);

}