/**
* @file Bill.cpp
*
* @brief Calculates the total bill for the customer of a utility company.
*
* This computes how much a customer would pay for their utility bill. This
* equation includes gas, electric, previous outstanding charges, and service
* charges all in the total bill.
*
* @author Ben Wallen
* @date 2020-10-15
*
*/

/*
Psuedocode:

const int billingCycle = 30;
const double costKwh = 12.5;
cosnt double costTherm = 67.3;
const double serviceCharge = 25.00;
int usedElec;
double usedGas, previousBalance, lastPayment, totalBalance, elecCost, gasCost;


Equations:
nat gas cost = costTherm * used
eletricity cost= costKwh * usedElec
totalCost = serviceCharge + natgascost + eleccost  + pastbalance - lastpayment (?)
//totalcost needs fabs

output / input cmds:
cout << "enter customers's name"
cin >> customername (or, in this case -- getline. This is a bad example for cin)

These commands will be repeated frequently -- what is important is managing the variable types
(int vs. double) & the formatting. For simplicity, setw will set to make the output clean. The
output will run the equations and display the output of the equations + the declared
variables.

Tests:
* Test 1
* Enter the customer's name: John Doe
* Enter the customer's previous balance: 1050.70
* Enter the customer's last payment amount: 50.00
* Enter the amount of electricity used (in kWh) : 1024
* Enter the amount of natural gas used (in therms) : 512
*
* Customer: John Doe
* Previous Balance: 1050.70
* Last Payment: 50.00
* Electricity Used (kWh): 1024 (34.1 per day)
* Electricity Cost: 128.00
* Natural Gas Used (therms): 512 (17.1 per day)
* Natural Gas Cost: 344.58
* New Balance: 1,498.28
*
* Test 2
* Enter the customer's name: Joe Doe
* Enter the customer's previous balance: 10.12
* Enter the customer's last payment amount: 0
* Enter the amount of electricity used (in kWh) : 3
* Enter the amount of natural gas used (in therms) : 43.2

* Customer: Joe Doe
* Previous Balance: 10.12
* Last Payment: 0.00
* Electricity Used (kWh): 3 (0.1 per day)
* Electricity Cost: 0.38
* Natural Gas Used (therms): 43.2 (1.4 per day)
* Natural Gas Cost: 29.07
* New Balance: 64.57
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
/**
* @brief Calculates the total bill for the customer of a utility company.
*
* This is the main function for the program. As mentioned above, This computes
* how much a customer would pay for their utility bill. This equation
* includes gas, electric, previous outstanding charges, and service
* charges all in the total bill.
*
* @return 0 is sucessful, non-0 on error
*/
int main() {
	//variable decleration
	int usedElec;
	const double SERV_CHARGE = 25.00;
	const double COST_KWH = 0.125;
	const double COST_THERM = 0.673;
	const int CONST_CYCLE = 30;
	double usedGas, previousBalance, lastPayment, totalBalance, elecCost, gasCost;
	string customerName;
	//input code
	cout << "Enter the customer's name: ";
	getline(cin, customerName);
	cout << "Enter the customer's previous balance: ";
	cin >> previousBalance;
	cout << "Enter the customer's last payment amount: ";
	cin >> lastPayment;
	cout << "Enter the amount of electricity used (in kWh): ";
	cin >> usedElec;
	cout << "Enter the amount of natural gas used (in therms): ";
	cin >> usedGas;
	//calculations area, code simplification
	usedElec = max(usedElec, 0);
	usedGas = max(usedGas, 0.0);
	elecCost = usedElec * COST_KWH;
	gasCost = usedGas * COST_THERM;
	totalBalance = (SERV_CHARGE + gasCost + elecCost + previousBalance) - lastPayment;
	//output / equation outputs
	cout << endl << left << setw(30) << "Customer: ";
	cout << right << setw(10) << customerName << endl;
	cout << left << setw(30) << "Previous Balance: ";
	cout << right << setw(10) << fixed << setprecision(2) << previousBalance << endl;
	cout << left << setw(30) << "Last Payment: ";
	cout << right << setw(10) << fixed << setprecision(2) << fabs(lastPayment) << endl;
	cout << left << setw(30) << "Electricity Used (kWh): ";
	cout << right << setw(10) << fixed << setprecision(0) << usedElec;
	cout << right << setw(4) << "(" << fixed << setprecision(1)
		<< ((double)usedElec / CONST_CYCLE) << " per day)" << endl;
	cout << left << setw(30) << "Electricity Cost: ";
	cout << right << setw(10) << fixed << setprecision(2) << elecCost << endl;
	cout << left << setw(30) << "Natural Gas Used (therms): ";
	cout << right << setw(10) << fixed << setprecision(1) << usedGas;
	cout << right << setw(4) << "(" << fixed << setprecision(1) << (usedGas / CONST_CYCLE)
		<< " per day)" << endl;
	cout << left << setw(30) << "Natural Gas Cost: ";
	cout << right << setw(10) << fixed << setprecision(2) << gasCost << endl;
	cout << left << setw(30) << "New Balance: ";
	cout << right << setw(10) << fixed << setprecision(2) << abs(totalBalance) << endl;
	return 0;
}