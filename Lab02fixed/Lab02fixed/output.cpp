/**
* @file output.cpp
*
* @brief Prints out a paragraph of text, dictated in Lab02p1
*
* This file contains the paragraph posted in Lab02p1.
* This paragraph includes multiple special characters, causing a need for escape
* sequences at certain intervals.
* For readability, wordwrap is reccomended in your IDE.
*
* @author Ben Wallen
* @date 2020-09-30
*/
#include <iostream>
using namespace std;
/**
* @brief Prints out a paragraph of text, dictated in Lab02p1
*
* This file contains the paragraph posted in Lab02p1.
* This paragraph includes multiple special characters, causing a need for escape
* sequences at certain intervals.
*
* @return 0 is sucessful, non-0 on error
*/
int main() {
	cout << "\tIn Windows, putting the path to a file into the code is a little" << endl;
	cout << "difficult as each \"\\\" in the path must be escaped. So, if your" << endl;
	cout << "file is located at C:\\temp\\data.csv, then you would need to" << endl;
	cout << "escape it so that it looks like C:\\\\temp\\\\data.csv. It is also" << endl;
	cout << "good practice to put \"\'s around the path. This avoids problems" << endl;
	cout << "with spaces in the file name or the path. The \"\'s would have" << endl;
	cout << "to be escaped as well." << endl;
	return 0;
}