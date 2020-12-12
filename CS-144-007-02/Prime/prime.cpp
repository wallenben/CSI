#include <iostream>
#include <fstream>
#include "primeFunctions.h"
#include <sstream>

using namespace std;


// functions
// determine if a number is prime
// input -> int
// output -> boolean
// <return type> <name>(<params>);
// TODO document






int main() {
	int n;
	bool prime;

	//ifstream data;
	//data.open("input.txt");

	stringstream data;

	data.str("1 2 3 4 5 6 7 8 9 ");

	ofstream output("results.txt");

	// priming read
	// cout << "Enter a number to determine if prime: ";
	n = getValidInput(data);
	while (data) {
		
		prime = isPrime(n);
		
		outputPrimeNum(output, n, prime);
		outputPrimeNum(cout, n, prime);
		

		//cout << "Enter a number to determine if prime: ";
		n = getValidInput(data);
	}

	//data.close();

	// i++ <-> i = i + 1 
	// ++i <-> i = i + 1
	// y = 4
	// x = y++;	  y = 5, x = 4
	// x = ++y;   y = 5, x = 5










	return 0;
}



