#ifndef PRIMEFUNCTIONS_H_2020_11_05
#define PRIMEFUNCTIONS_H_2020_11_05

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

// check if a file has not been seen
//	mark it as seen

// functions/enums/etc.
/**
	@breif Determines if a number is prime.

	Determines if a number is prime.

	@param num The number to check if it is prime.

	@return True if prime, false if not.
*/
bool isPrime(int num);
// TODO add more functions
// parameter passing
// by default - parameters are passed-by-value
//	makes a copy
// passed-by-reference
//	pass a memory address
//  add an & between the type and the name
void outputPrimeNum(ostream& output, int num, bool prime);
string formatPrimeNum(int num, bool prime);
int getValidInput(istream& input);


#endif // PRIMEFUNCTIONS_H_2020_11_05