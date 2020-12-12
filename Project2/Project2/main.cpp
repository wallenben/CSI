#include <string>
#include "Header.h"
#include <iostream>
using namespace std;


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

Ballot::Ballot(string voterID2) {
    voterID = voterID2;
    votesStored = -1;
}
Ballot::Ballot() {
    voterID = "Invalid ID";
    votesStored = 0;
}
Ballot::~Ballot() {
    /**this is what the prompt asks for, technically.
    the book details that this can be achieved in a more simple matter --
    using the delete[] operator.
    */
    for (int i = 0; i < 6; ++i) {
        delete votePointer[i];
    }
}

const Vote* Ballot::getVote(int votePosition) const {
    if (votePosition > -1 && votePosition < votesStored) {
        //unsure if this is proper syntax -- will need testing
        return votePointer[votePosition];
    }
    else {
        return nullptr;
    }

}