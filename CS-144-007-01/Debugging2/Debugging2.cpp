#include <iostream>
#include <iomanip>
#include <string>


using namespace std;


/*
*  Formats part of a table.  Lays out the name of an item, the idNumber, and cost
*  of each item, the quantity, and the total cost of that row into a single line of output.
*  The formatting is as follows:
*   value    width   alignment
*   =====    =====   =========
*   name     20      left
*   idNumber 8       left
*   quantity 4       right
*   cost     9(2)    right
*   total    9(2)    right
*
*  All values are written to out.
*/
void formatTableRow(ostream &out, string name, int idNumber, double cost, int quantity)
{
    double total = cost * quantity; 
	
    out << fixed << setprecision(2) << setw(20) << left;  
    out << name  << setw(8) << idNumber;  
	out << right << setw(4) << quantity;
    out << setw(9) << cost; 
    out << setw(9) << total << "\n";

}

/**
*  Gets a value from the istream and tries to add it to currValue. 
*  If adding the value to currValue causes it to be outside of the
*  range -100 to 100, then an error occurs and currValue is not changed.
*
*  @param in Input stream to read from
*  @param currValue Value to update with data from in
*  @return -1 if currValue outside the range -100 to 100 inclusive, 
*   -2 if in cannot be read from,
*	0 currValue between -100 and 100 inclusive
*	
*/
int updateValue(istream &in, int &currValue) {
	int newValue;

	if (in.fail()) {
		return -2;
	}

	in >> newValue; 

	currValue += newValue; 
	if (currValue > 100 
		|| currValue < -100) { 
		return -1;
	}

	
	return 0;
}



void testUpdateValue() {
	int exitValue;
	int cValue = 0;

	do {
		cout << "Enter a new value: ";
		exitValue = updateValue(cin, cValue);
		cout << "Current Value: " << cValue 
			<< " Exit Value: " << exitValue << "\n";
	} while (exitValue == 0);
}


int main() {
    //test formatTableRow
	// Rotor               456932     1  5875.45  5875.45
    /*formatTableRow(cout, "Rotor", 456932, 5875.45, 1);
    formatTableRow(cout, "Blade", 120532, 19.50, 5);
    formatTableRow(cout, "Motor", 1344563, 439.10, 3);
*/
	testUpdateValue();
    return 0;
}
