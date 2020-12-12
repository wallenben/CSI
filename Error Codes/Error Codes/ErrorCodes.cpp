/*
 *  @file ErrorCodes.cpp
 *
 *  @brief User inputs an error code and the program outputs a message for the code.
 *
 * This programs computes the message for the user inputted error code using
 * switchcase, and outputs the error code and the error message.
 *
 *  @date 21-Oct-2020
 *  @author Ben Wallen
 */
#include <iostream>
using namespace std;
/**
 *  @brief User inputs an error code and the program outputs a message for the code.
 *
 * This programs computes the message for the user inputted error code using
 * switchcase, and outputs the error code and the error message.
 *
 * TESTS:
 * Input: -1, Output: File not Found
 * Input -7, Output: Unknown Error
 * Input -4, Output: Out of Memory
 * Input -8, Output: Invalid Operation
 * Input -2, Output: Invalid File Format
 * Input 3, Output: Unknown Error
 */
int main() {
	int errorCode;
	string errorMessage = "";
	cout << "Input error code: ";
	cin >> errorCode;
	switch (errorCode) {
	case - 1:
		errorMessage = "File not Found";
		break;
	case - 2:
		errorMessage = "Invalid File Format";
		break;
	case - 4:
		errorMessage = "Out of Memory";
		break;
	case - 8:
		errorMessage = "Invalid Operation";
		break;
	default:
		errorMessage = "Unknown Error";
		break;
	}
	cout << "Your error code was: " << errorCode << endl;
	cout << "Error message: " << errorMessage << endl;
	return 0;
}