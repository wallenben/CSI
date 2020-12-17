//*** MAIN FILE ***//

#include "character.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {

	Item item1;
	Item item2;
	Item item3("Handmade Bob", 42);
	Character character1("Uncle Bob");

	item1.setName("Dull Cleaver (not a sword)");
	item1.setType(1);

	item2.setName("Kitty");

	//character1.setName("Uncle Bob");
	character1.setLevel(100);
	character1.setLeft(item1);
	character1.setRight(item2);

	cout << "Name: " << item1.getName() << " Type: " << item1.getType()
		<< "\n";
	cout << "Name: " << item2.getName() << " Type: " << item2.getType()
		<< "\n";
	cout << item1 << "\n";
	cout << setw(30) << right << item3 << "\n";

	cout << character1.getName() << " (" << character1.getLevel() << ")\n"
		<< "Left: " << character1.getLeft()->getName() << "\n"
		<< "Right: " << character1.getRight()->getName() << "\n";
	cout << character1 << "\n\n";

	//Makes character 2 a copy of character 1
	Character char2(character1);
	char2 = character1; //Will do the same thing.
	//Now, this is stupid and hard to detect but self-assignment is a thing here.
	char2 = char2;

	CharacterList people; 
	people.addCharacter(character1);
	cout << endl;
	cout << people.getCharacter(0) << "\n";

	for (int i = 0; i < 82; i++) {
		//We should use a constructor with param
		stringstream name;
		name << "Kathy" << i;
		Character kathy(name.str());
		if (i == 24) {
			kathy.setLevel(5);
		}

		Item kittens("Kittens", 3);

		//Get rid of the apersands (&) because we now have a copy
		kathy.setRight(kittens);
		people.addCharacter(kathy);
	}

	cout << "\n";
	//TODO print all the list out
	for (int i = 0; i < people.getCharacterCount(); i++) {
		cout << people.getCharacter(i) << "\n";
	}

	/*
		        1	        2	3	4	5
	    | id, name, date  |   |   |   |   |
		
		items[i] How do we get an ID from an item?
		-> getID or items[i]getItemID()
		However, they don't do the same thing
		The former dereferences the pointer

		(*ptr).getX();
		ptr->getX();

		Lab 9:

		If we want an array:
		int *nums[100]

		The most common causes of having bad data is the data not being inserted correctly.
		The logic in the if statement could be wrong.
	*/

	return 0;
}