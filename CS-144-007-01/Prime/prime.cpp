#include <iostream>
#include <fstream>
#include <sstream>
#include "primeFunctions.h"

using namespace std;


// functions
// determines if a number is prime
// input -> int
// output -> boolean
// <return type> <name>(<params>);




int main() {
	int n;
	bool prime;
	//ifstream data;

	//data.open("input.txt");
	stringstream data;

	//data << 9 << " " << 10;
	data.str("1 2 3 4 5 6 7 8");

	ofstream output("results.txt");

	//priming read
	// cout << "Enter the number to determine if it is prime: ";
	n = inputPrime(data);
	// data <-> !data.fail()
	while (data) {
		
		prime = isPrime(n);
		
		outputPrime(output, n, prime);
		outputPrime(cout, n, prime);
		

		// cout << "Enter the number to determine if it is prime: ";
		n = inputPrime(data);
	}


	//data.close();
	output.close();

	// i++ <-> i = i + 1






	return 0;
}








/**

	"abcde"  length = 5



*/