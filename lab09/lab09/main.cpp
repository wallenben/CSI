#include "p3.h"
#include <string>
#include <iostream>
#include <sstream>

int main() {
	Ballot ballot2("WI-534MES");
	//add vote
	ballot2.recordVote("President", "Banshee", false);
	ballot2.recordVote("Treasurer", "Magneto", true);

	cout << ballot2 << "\n";
	Ballot ballotCopy(ballot2);
	cout << ballotCopy << "\n";


	stringstream cInput;
	cInput << "WI-1604-XZI 3 ADA Nightcrawler 0 Secretary "
		<< "Wolverine 1 DA Gambit 1 ";
	Ballot ballot3;
	cInput >> ballot3;
	cout << ballot3 << "\n";
}