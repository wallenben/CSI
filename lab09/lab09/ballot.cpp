#include "p3.h"
#include <string>
#include <iostream>
using namespace std;

string Ballot::getVoterId() const {
    return voterID;
}
int Ballot::getVoteCount() const {
    return votesStored;
}
Ballot::Ballot(string voterID2) {
    //set string param to voterID
    voterID = voterID2;
    votesStored = 0;
}
Ballot::Ballot() {
    //same thing, default becomes "Invalid ID"
    voterID = "Invalid Id";
    votesStored = 0;
}
Ballot::~Ballot() {
    /**this is what the prompt asks for, technically.
    the book details that this can be achieved in a more simple matter --
    using the delete[] operator, but that would nuke the whole array - not whats asked
    */
    for (int i = 0; i < votesStored; ++i) {
        delete votePointer[i];
    }
}
const Vote* Ballot::getVote(int votePosition) const {
    //if the parameter is within the used portion of the array
    if (votePosition >= 0 && votePosition < votesStored) {
        //return the voter pointer based on position
        return votePointer[votePosition];
    }
    else { return nullptr; }
}
int Ballot::findVote(string office) const {
    //For each Voter pointer in the array, get the office and then compare it to the parameter.
    for (int i = 0; i < votesStored; ++i) {
        if (votePointer[i]->getOffice() == office) {
            //validCheck for the else statement
            //If it matches, return the position of that value
            return i;
        }
    }
    //otherwise return -1 after looping
    return -1;
}
void Ballot::recordVote(string office, string candidateName, bool voteInPerson) {
    if (votesStored + 1 < 6) {
        int x = findVote(office);
        if (x == -1) {
            //dynamically create a newVote object
            Vote* x;
            x = new Vote(office, candidateName, voteInPerson);
            //put that new value in the first unused position
            votePointer[votesStored] = x;
            ////Increment the class’s variable
            ++votesStored;
        }
    }
}
int Ballot::countInPersonVotes() {
    int count = 0;
    for (int i = 0; i < votesStored; ++i) {
        bool x = false;
        x = votePointer[i]->wasInPerson();
        if (x == true) {
            count++;
        }
    }
    return count;
}//wtf is this
//review copy-constructor logic. 
//copying the vote-point array logic SHOULD make sense. Unsure on how to do the other ones.
//this needs two tests
Ballot::Ballot(const Ballot& origBallot) {
    voterID == (origBallot.voterID);
    Vote* x;
    //hopefully this is alright, no pointers needed
    votesStored == (origBallot.votesStored);
    for (int i = 0; i < votesStored < i++;) {
        x = (origBallot.votePointer[i]);
        votePointer[i] = x;
    }
}
//needs two tests
Ballot& Ballot::operator = (const Ballot& ballot) {
    voterID == (ballot.voterID);
    votesStored == (ballot.votesStored);
    for (int i = 0; i < votesStored < i++;) {
        delete ballot.votePointer[i];
    }
    return *this;
}
//two tests needed
ostream& operator<<(ostream& out, const Ballot& ballot) {
    out << ballot.getVoterId() << '\n';
    for (int i = 0; i < ballot.votesStored < i++;) {
        out << ballot.votePointer[i]->getOffice() << '\n';
        out << ballot.votePointer[i]->getCandidate() << '\n';

    }
    return out;
}
//also requries two tests
istream& operator>>(istream& in, Ballot& ballot) {
    for (int i = 0; i < ballot.votesStored < i++;) {
        delete ballot.votePointer[i];
    }
    ballot.votesStored = 0;
    in >> ballot.voterID;
    int ballotCount;
    in >> ballotCount;
    string candidatex;
    string officex;
    bool inOfficeCheck;
    //on compiler error: switch < to != maybe
    for (int i = 0; i < ballotCount; i++) {
        ballot.votePointer[i]->getCandidate() = candidatex;
        in >> candidatex;
        ballot.votePointer[i]->getOffice() = officex;
        in >> officex;
        ballot.votePointer[i]->wasInPerson() == inOfficeCheck;
        in >> inOfficeCheck;

    }
    return in;
}
BallotList::BallotList() {
    numBallots = 0;
    currentArraySize = 4;

}
//deletes ballotpointer, deletes array
BallotList::~BallotList() {
    for (int i = 0; i < currentArraySize; ++i) {
        delete[] ballotPointer;
        ballotPointer = nullptr;
    }
}

//returns number of ballots in the array
int BallotList::getNumBallots() const {
    return numBallots;
}
Ballot* BallotList::getBallot(int ballotPosition) {
    //check if the parameter (the position in the list to retrieve) is valid
    if (ballotPosition < numBallots) {
        return ballotPointer[ballotPosition];
    }
}
