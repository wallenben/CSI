#pragma once
#include <string>
#include <iostream>
class Vote {
private:
    string vOffice;
    string canidiateName;
    bool voteMadeInPerson;
public:
    Vote(string vOffice2, string canidiateName2, bool voteMadeInPerson2);
};
class Ballot {
private:
    string voterID;
    int votesStored;
    Vote* votePointer[6];
public:
    Ballot();
    Ballot(string voterID2);
    ~Ballot();
    const Vote* getVote(int votePosition) const;
};
