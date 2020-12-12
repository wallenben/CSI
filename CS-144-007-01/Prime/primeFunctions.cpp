#include <cmath>
#include <iostream>
#include <sstream>
#include "primeFunctions.h"

using namespace std;


bool isPrime(int num) {
	int sqrtN;
	bool prime;

	// if n < 0
	if (num >= 2) {
		sqrtN = static_cast<int>(sqrt(num));
		prime = true;
		// check divide by 2 through sqrtN
		for (int i = 2; i <= sqrtN; i++) {
			// if n / i is integer -> not prime
			double ans = static_cast<double>(num) / i;
			if (ans == static_cast<int>(ans)) {
				// not prime
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

string formatPrime(int num, bool prime) {
	string primeStr;
	stringstream mStr;
	// num -> Prime/Not prime\n
	mStr << num << " -> ";
	if (prime) {
		mStr << "Prime";
	}
	else {
		mStr << "Not prime";
	}
	primeStr = mStr.str();
	return primeStr;
}






int inputPrime(istream& input) {
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






