#include <iostream>
#include <fstream>
#include "primeFunctions.h"
#include <sstream>
using namespace std;


// function
// determines if it is prime
// input -> int
// output -> boolean
// <return type> <name> (<params>);
// TODO document




int main() {
	int n;
	bool prime;

	//ifstream data;
	//data.open("input.txt");
	stringstream data;
	ofstream output("results.txt");

	//data.str("1 2 3 4 5 6 7 ");
	data << 8 << " " << 9;

	// priming read
	//cout << "Enter the number to check if prime (0 to quit): ";
	n = getNumber(data);
	// data <-> !data.fail()
	while (data) {
		
		prime = isPrime(n);
		
		outputPrime(output, n, prime);
		outputPrime(cout, n, prime);

		//cout << "Enter the number to check if prime (0 to quit): ";
		n = getNumber(data);
	}


	//data.close();
	output.close();
	// i++ <-> i = i + 1
	// ++i <-> i = i + 1 
	// y = 4, x = 0
	// x = y++;	 // y = 5, x = 4
	// x = ++y;  // y = 5, x = 5








	return 0;
}
