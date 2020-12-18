/*
* @file BallotList.cpp
*
* @brief Contains the functions related to the BallotList class
* This file contains all functions pertaining to the BallotList
* class detailed in the header.
*
* @date 17 - Dec - 2020
* @author Ben Wallen
*/
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
		delete [] ballotPointer;
		ballotPointer = nullptr;
	}
}

//returns number of ballots in the array
int BallotList::getNumBallots() const {
	return numBallots;
}
Ballot * BallotList::getBallot(int ballotPosition) {
	//check if the parameter (the position in the list to retrieve) is valid
	if (ballotPosition < numBallots) {
		return &ballotPointer[ballotPosition];
	}
}
const Ballot * BallotList::getBallot(int pos) const {
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
Ballot * BallotList::findBallot(string voterID) {
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
int BallotList::countBallotsFor(string office, string candidateName) const {
	int count = 0;
	for (int i = 0; i < currentArraySize; i++) {
		for (int z = 0; z < ballotPointer[i].getVoteCount(); i++) {
			if (ballotPointer[i].getVote(z)->getOffice() == office) {
				if (ballotPointer[i].getVote(z)->getCandidate() == office) {
					++count;
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