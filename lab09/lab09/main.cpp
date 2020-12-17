#include "p3.h"
#include <string>
#include <iostream>
#include <sstream>

int main() {
	//create a ballot
	Ballot ballot2("WI-534MES");
	//add vote
	ballot2.recordVote("President", "Banshee", false);
	ballot2.recordVote("Treasurer", "Magneto", true);
	//test insertion operator
	cout << ballot2 << "\n";
	//test copy constructor
	Ballot ballotCopy(ballot2);
	//should see the same output as before
	cout << ballotCopy << "\n";
	//tests extraction operator
	stringstream cInput;
	cInput << "WI-1604-XZI 3 ADA Nightcrawler 0 Secretary "
		<< "Wolverine 1 DA Gambit 1 ";
	Ballot ballot3;
	cInput >> ballot3;

	
}