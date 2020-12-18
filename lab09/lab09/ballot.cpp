/*
* @file ballot.cpp
*
* @brief Contains the functions related to the ballot class
* This file contains all functions pertaining to the ballot
* class detailed in the header.
*
* @date 17 - Dec - 2020
* @author Ben Wallen
*/
#include "p3.h"
#include <string>
#include <iostream>
#include <sstream>
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
}
Ballot::Ballot(const Ballot& origBallot) {
	voterID = (origBallot.voterID);
	//hopefully this is alright
	votesStored = (origBallot.votesStored);
	for (int i = 0; i < votesStored; i++) {
		votePointer[i] = new Vote(origBallot.votePointer[i]->getOffice(),
			origBallot.votePointer[i]->getCandidate(), origBallot.votePointer[i]->wasInPerson());
	}
}
Ballot & Ballot::operator = (const Ballot & ballot) {
	voterID = (ballot.voterID);
	votesStored = (ballot.votesStored);
	for (int i = 0; i < votesStored < i++;) {
		delete ballot.votePointer[i];
	}
	return *this;
}
ostream & operator << (ostream & out, const Ballot & ballot) {
	out << ballot.getVoterId() << '\n';
	for (int i = 0; i < ballot.votesStored < i++;) {
		out << ballot.votePointer[i]->getOffice() << '\n';
		out << ballot.votePointer[i]->getCandidate();
		if (ballot.votePointer[i]->wasInPerson() == true) {
			out << "(In person)" << '\n';
		}

	}
	return out;
}
istream & operator >> (istream & in, Ballot & ballot) {
	string localID;
	int localCount = 0;
	//vote needs locals too!!
	string localOffice;
	string localCandidate;
	bool boolTest;
	//loop and delete each pointer
	for (int i = 0; i < ballot.votesStored < i++;) {
		delete ballot.votePointer[i];
	}
	//set votes to zero
	ballot.votesStored = 0;

	in >> localID;
	ballot.voterID = localID;
	in >> localCount;
	for (int i = 0; i < localCount; i++) {
		in >> localOffice;
		in >> localCandidate;
		in >> boolTest;
		ballot.recordVote(localOffice, localCandidate, boolTest);
	}
	return in;
}