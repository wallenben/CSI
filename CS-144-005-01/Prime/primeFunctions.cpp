#include <iostream>
#include <cmath>
#include "primeFunctions.h"
#include <sstream>

using namespace std;


bool isPrime(int num) {
	int sqrtN;
	bool prime;

	// check if n < 0
	if (num >= 2) {
		sqrtN = static_cast<int>(sqrt(num));
		prime = true;
		// check 2 to sqrtN
		for (int i = 2; i <= sqrtN; i++) {
			//cout << i << "\n";
			// n / i -> int
			double ans = static_cast<double>(num) / i;
			if (ans == static_cast<int>(ans)) {
				// mark as not prime
				prime = false;
			}
		}
	}
	else {
		prime = false;
	}

	return prime;
}


void outputPrime(ostream& output, int num, bool prime) {

	output << num << " -> ";
	if (prime) {
		output << "Prime";
	}
	else {
		output << "Not prime";
	}
	output << "\n";


}


int getNumber(istream& input) {
	int n;

	input >> n;
	if (input.fail()) {
		do {
			input.clear();

			string temp;
			input >> temp;
			input >> n;
		} while (input.fail() && !input.eof());
	}
	return n;
}


string formatPrime(int num, bool prime) {
	stringstream str;
	string outStr;

	// num -> Prime/Not Prime\n
	str << num << " -> ";
	if (prime) {
		str << "Prime";
	}
	else {
		str << "Not Prime";
	}
	str << "\n";

	outStr = str.str();
	return outStr;
}
