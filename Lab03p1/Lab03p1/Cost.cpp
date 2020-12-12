/**
* @file Cost.cpp
*
* @brief Calculates the cost of fabricating a certain amount of units of an item.
*
* This computes how much it would cost to fabricate a certain amount of an 
* item. This is done by inputting the cost per unit, the amount per unit, specified markup,
* and the company name.
* 
* @author Ben Wallen
* @date 2020-10-07
*
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/** 
* @brief Calculates the cost of fabricating a certain amount of units of an item.
*
* This computes how much it would cost to fabricate a certain amount of an
* item. This is done by inputting the cost per unit, the amount per unit, specified markup,
* and the company name.
* 
* Input: Company1, 30, 3, 0.3
* 
* Expected: 
* Company1
* Units:        30
* Cost Per:      3.00
* Markup:      30.0%
* Total Cost:    6275.0
*
*
* Input: Company Two, 200, 0.2, 0.5
* 
* Expected:
* Company Two
* Units:       200
* Cost Per:      0.20
* Markup:      50.0%
* Total Cost:    5575.0
*
* Input: Company 3, 3000, 30, 0.5
* 
* Expected:
* Company 3
* Units:       3000
* Cost Per:      30.00
* Markup:      50.0%
* Total Cost:    138575.0
*
* Input: Company 4, 1, 0.5, 0.5
* 
* Expected:
* Company 4
* Units:       1
* Cost Per:      0.50
* Markup:      50.0%
* Total Cost:    3575.8
*
*/
int main() {
	string companyName;
	int numberOfUnits;
	double percentMarkup;
	double costPerUnit;
	const int SETUP_COST = 3575.95;
	double totalCost;
	double totalMarkup;
	int finalCost;

	cout << "Enter the company name: ";
	getline(cin, companyName);
	cout << "Enter the number of units: ";
	cin >> numberOfUnits;
	cout << "Enter the cost per unit: ";
	cin >> costPerUnit;
	cout << "Enter the percent markup: ";
	cin >> percentMarkup;

	totalCost = (numberOfUnits * costPerUnit);
	totalMarkup = percentMarkup * 100;
	finalCost = (totalCost * totalMarkup) + SETUP_COST;

	cout << companyName << endl;
	cout << "Units:" << right << fixed << setw(10) << numberOfUnits << endl;
	cout << "Cost Per:" << right << fixed << setw(10) << setprecision(2) << costPerUnit << endl;
	cout << "Markup:" << right << fixed << setw(10) << setprecision(1) << (double)(percentMarkup * 100) << "%" << endl;
	cout << "Total Cost:" << right << fixed << setw(10) << finalCost << endl;
	return 0;
}