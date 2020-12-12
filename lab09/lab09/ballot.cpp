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
const Vote * Ballot::getVote(int votePosition) const {
    //if the parameter is within the used portion of the array
    if (votePosition >= 0 && votePosition < votesStored) {
        //return the voter pointer based on position
        return votePointer[votePosition];
    }
    else { return nullptr; }
}
int Ballot::findVote(string office) const {
    bool validCheck = false;
    //For each Voter pointer in the array, get the office and then compare it to the parameter.
    for (int i = 0; i < votesStored; ++i) {
        if (votePointer[i]->getOffice() == office) {
            //validCheck for the else statement
            validCheck == true;
            //If it matches, return the position of that value
            return i;
        }
    }
    //otherwise return -1 after looping
    if (validCheck == false) {
        return -1;
    }
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
}