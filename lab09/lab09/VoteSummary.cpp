/*
* @file VoteSummary.cpp
*
* @brief Contains the functions related to the VoteSummary class
* This file contains all functions pertaining to the VoteSummary
* class detailed in the header.
*
* @date 17 - Dec - 2020
* @author Ben Wallen
*/
#include "p3.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

VoteSummary::VoteSummary(BallotList* listPointer2) {
	listPointer = listPointer2;
}
BallotList * VoteSummary::getBallots() {
	return listPointer;
}
void VoteSummary::loadVoterData(istream &i) {
	//BALLOT VOTE FUNCTIONS
	string identifier;
	string voteID;
	int count;
	string office1;
	string candidate1;
	bool inPerson;
	string office2;
	BallotList ballotList;
	//VOTE FUNCTIONS
	//might not need any
	if (listPointer != nullptr) {
		listPointer->resetList();
		i >> identifier;
		if (identifier == "ballot") {
			i >> voteID; // voteid
			i >> count; // count 
			Ballot z(voteID);
			for (int x = 0; x < count; x++) {
				i >> office1; // office
				i >> candidate1;
				i >> inPerson;
				z.recordVote(office1, candidate1, inPerson);
			}
			ballotList.addBallot(z);
		}
		else if (identifier == "vote") {
			i >> voteID; //voteid
			i >> office1;
			i >> candidate1;
			i >> inPerson;
			if (ballotList.findBallot(voteID) != nullptr) {
				ballotList.findBallot(voteID)->recordVote(office1, candidate1, inPerson);
			}
		}
	}
}
string VoteSummary::printVoterRecord() {
	stringstream ss;
	string stringy;
	if (listPointer == nullptr) {
		return "";
	}
	else {
		ss << "Votes" << '\n';
		for (int i = 0; i < listPointer->getNumBallots(); i++) {
			ss << listPointer[i].getBallot(i) << '\n';
		}
		ss << "Total number of votes: " <<
			listPointer->getTotalVotesCast();
	}
	ss.str(stringy);
	return stringy;
}
string VoteSummary::printElectionReport(Election electionArray[], int arraySize) {
	string tempOffice;
	string tempCandidate;
	stringstream ss;
	string stringster;

	if (listPointer == nullptr) {
		return "";
	}
	for (int i = 0; i < arraySize; i++) {
		tempOffice = electionArray[i].getOffice();
		tempCandidate = electionArray[i].getCandidate1();
		ss << tempOffice << '\n';
		ss << tempCandidate << setw(5) << right <<
			listPointer->countBallotsFor(tempOffice, tempCandidate)
			<< '\n';
		tempCandidate = electionArray[i].getCandidate2();
		ss << tempCandidate << setw(5) << right <<
			listPointer->countBallotsFor(tempOffice, tempCandidate)
			<< '\n';
	}
	ss.str(stringster);
	return stringster;
}