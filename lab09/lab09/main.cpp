#include "p3.h"
#include <string>
#include <iostream>

int main() {
	Ballot ballot2("WI-534MES");
	ballot2.recordVote("President", "Banshee", false);
	ballot2.recordVote("Treasurer", "Magneto", true);
	Ballot ballotCopyballot2(ballot2);
}