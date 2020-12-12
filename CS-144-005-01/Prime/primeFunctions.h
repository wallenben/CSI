#ifndef PRIMEFUNCTIONS_H_2020_11_04
#define PRIMEFUNCTIONS_H_2020_11_04

#include <iostream>
#include <string>
using std::string;
using std::ostream;
using std::istream;

// check if the file has not been included
// mark that it is include

// put my functions/enums/etc.

/**
	@brief Determines if a number is prime.

	Determines if a number is prime.

	@param num Number to check if prime.

	@return True if prime, false otherwise.
*/
bool isPrime(int num);

// TODO write more functions
// by default - parameters are passed-by-value
//	making a copy
// passed-by-reference
//	pass the memory address - not a copy
//	add a & between the type and the name of the parameter
void outputPrime(ostream& output, int num, bool prime);
string formatPrime(int num, bool prime);
int getNumber(istream& input);


#endif // PRIMEFUNCTIONS_H_2020_11_04