#include "character.h"

#include <iostream>

using namespace std;

int main() {

	Item item1;
	Item item2;

	Character char1;

	// TODO initialize data
	item1.setName("Steve");
	item1.setType(1);

	item2.setName("Samatha-Paul");

	char1.setName("Sabre");
	char1.setLevel(3);
	char1.setLeft(item1);
	char1.setRight(item2);

	// TODO make output easier
	cout << "Name: " << item1.getName() << " Type: " << item1.getType()
		<< "\n";

	cout << "Name: " << item2.getName() << " Type: " << item2.getType()
		<< "\n";

	cout << item1 << "\n";

	cout << char1.getName() << " (" << char1.getLevel() << ")\n"
		<< "Left: " << char1.getLeft().getName() << "\n"
		<< "Right: " << char1.getRight().getName();



	// 1 3 5 7 
	// 4

	return 0;
}