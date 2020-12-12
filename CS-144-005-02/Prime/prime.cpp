#include <iostream>
#include <fstream>
#include "primeFunctions.h"

using namespace std;

// function
// determine if a number is prime
// input -> int
// output -> boolean
// <return type> <name>(<params>);





int main() {
	int n;
	bool prime;

	ifstream data;
	data.open("input.txt");
	ofstream results("output.txt");

	// priming read
	//cout << "Enter a number to determine if prime: ";
	n = getData(data);
	while (data) {
		
		prime = isPrime(n);
		
		outputPrime(results, n, prime);
		outputPrime(cout, n, prime);

		//cout << "Enter a number to determine if prime: ";
		n = getData(data);
	}

	data.close();
	results.close();
	// i++ <-> i = i + 1
	// ++i <-> i = i + 1 
	// y = 4;
	// x = y++;	  y = 5, x = 4 
	// x = ++y;   y = 5, x = 5




	// long
	return 0; // short
}



