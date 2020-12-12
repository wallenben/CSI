#include <cmath>
#include <iostream>
#include "primeFunctions.h"
#include <sstream>

using namespace std;





bool isPrime(int num) {
	int sqrtN;
	bool prime;

	if (num >= 2) {
		sqrtN = static_cast<int>(sqrt(num));
		prime = true;
		// divide by 2 through sqrtN
		for (int i = 2; i <= sqrtN; i++) {
			// if n / i is int -> not prime
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

string formatPrime(int num, bool prime) {
	string outputStr;
	stringstream mStr;
	// num -> Prime/Not Prime\n
	mStr << num << " -> ";
	if (prime) {
		mStr << "Prime";
	}
	else {
		mStr << "Not prime";
	}
	mStr << "\n";
	outputStr = mStr.str();

	return outputStr;
}




int getData(istream& input) {
	int n;

	input >> n;
	if (input.fail()) {
		do {
			//cout << "data failed";
			input.clear();
			string temp;
			input >> temp;
			input >> n;
		} while (input.fail() && !input.eof());
	}

	return n;
}


