#include "p3.h"
#include <string>
#include <iostream>
using namespace std;

BallotList::BallotList() {
	numBallots = 0;
	currentArraySize = 4;
	ballotPointer = new Ballot[4];

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
		return &ballotPointer[ballotPosition];
	}
}
const Ballot* BallotList::getBallot(int pos) const {
	if (pos < numBallots) {
		return &ballotPointer[pos];
	}
}
//1 test needed
void BallotList::addBallot(Ballot ballot) {
	if (currentArraySize == numBallots) {
		currentArraySize = currentArraySize * 2;
		ballotPointer[currentArraySize];
	}
	ballotPointer[numBallots] = ballot;
	numBallots++;
}
//2 tests needed
Ballot* BallotList::findBallot(string voterID) {
	for (int i = 0; i < currentArraySize; i++) {
		if (ballotPointer[i].getVoterId() == voterID) {
			//validCheck for the else statement
			//If it matches, return the position of that value
			return &ballotPointer[i];
		}
	}
	//otherwise return -1 after looping
	return nullptr;
}
//2 tests
int BallotList::countBallotFor(string office, string candidateName) const {
	int count = 0;
	for (int i = 0; i < currentArraySize; i++) {
		for (int z = 0; z < ballotPointer[i].getVoteCount(); i++) {
			if (ballotPointer[i].getVote(z)->getOffice() == office) {
				if (ballotPointer[i].getVote(z)->getCandidate() == office) {
					++count;;
				}
			}
		}
	}
	return count;
}
//1 test
int BallotList::getTotalVotesCast() const {
	int vote = 0;
	for (int i = 0; i < currentArraySize; i++) {
		vote += ballotPointer[i].getVoteCount();
	}
	return vote;
}
void BallotList::resetList() {
	currentArraySize = 0;
	numBallots = 0;
}
VoteSummary::VoteSummary(BallotList* listPointer2) {
	listPointer = listPointer2;
}
BallotList* VoteSummary::getBallot() {
	return listPointer;
}
void VoteSummary::loadVoterData(istream i) {
	Ballot x;
	string identifier;
	string voteID;
	int count;
	string office1;
	string candidate1;
	bool inPerson;
	string office2;
	if (listPointer != nullptr) {
		listPointer->resetList();
		i >> identifier;
		if (identifier == "ballot") {
			i >> voteID; // voteid
			i >> count; // count
			for (int x = 0; x < count; x++) {
				i >> office1; // office
				i >> candidate1;
				i >> inPerson;
			}


		}
		else if (identifier == "vote") {

		}
	}
}


////vote <voter id> <office> <candidate> <in person>
/// ballot <voter id> <count> <office1> <candidate1> <in person1> <office>
/// //ballot WI-1598-MHN 2 DA Banshee 0 ADA Nightcrawler 0 \n