#ifndef PRIMEFUNCTION_H_2020_11_04
#define PRIMEFUNCTION_H_2020_11_04

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

// check to see if a token has not been defined
//  define it

// put all your functions/enums/etc.
/**
	@brief Determines if a number is prime.

	Determines if a number is prime.

	@param num Number to check if prime.

	@return True if prime, else false.

*/
bool isPrime(int num);
// parameter passing
// by default - passed-by-value
//	makes a copy
// passed-by-reference
//	passes a memory address
//  Add an & between the type and the name.
void outputPrime(ostream& output, int num, bool prime);
string formatPrime(int num, bool prime);
int getData(istream& input);



#endif // PRIMEFUNCTION_H_2020_11_04