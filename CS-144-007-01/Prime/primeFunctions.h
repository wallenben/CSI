#ifndef PRIMEFUNCTION_H_2020_11_04
#define PRIMEFUNCTION_H_2020_11_04

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

// check if the file has not been seen
//	mark it as seen

// functions/enums/etc.
/**
	@brief Determines if a number is prime.

	Determines if a number is prime.

	@param num Number to check if it is prime.

	@return True if prime, false if not prime
*/
bool isPrime(int num);
// by default - parameters are passed-by-value
//	makes a copy
// passed-by-reference
//	does not make a copy; sends a memory location
//  add an & between the type and the name of the parameter
void outputPrime(ostream& output, int num, bool prime);
string formatPrime(int num, bool prime);
int inputPrime(istream& input);



#endif // PRIMEFUNCTION_H_2020_11_04