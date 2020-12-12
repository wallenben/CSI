#include "character.h"

#include <iostream>

using namespace std;

int main() {

	Item item1;
	Item item2;
	Character char1;

	// TODO initialize to good data
	item1.setName("Broadsword");
	item1.setType(1);

	item2.setName("Watermelon Bomb");

	char1.setName("Steve");
	char1.setLevel(20);
	char1.setRight(item2);
	char1.setLeft(item1);

	// TODO make printing easier
	cout << "Name: " << item1.getName() << " Type: " << item1.getType()
		<< "\n";

	cout << "Name: " << item2.getName() << " Type: " << item2.getType()
		<< "\n";
	cout << item1 << "\n";

	item1.setType(-1);
	cout << "Name: " << item1.getName() << " Type: " << item1.getType()
		<< "\n";
	cout << char1.getName() << " (" << char1.getLevel() << ")\n"
		<< "Left: " << char1.getLeft().getName() << "\n"
		<< "Right: " << char1.getRight().getName();

	return 0;
}