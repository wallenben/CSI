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
		<< "Right: " << (*character1.getRight()).getName() << "\n";
	cout << character1 << "\n";

	Character char2(character1);
	char2 = character1;
	char2 = char2;

	CharacterList people;
	people.addCharacter(character1);
	cout << people.getCharacter(0) << "\n";

	for (int i = 0; i < 82; i++) {
		stringstream name;
		name << "Kathy " << i;
		Character kathy(name.str());
		if (i == 24) {
			kathy.setLevel(5);
		}
		Item kittens("Kittens", 3);

		kathy.setRight(kittens);
		people.addCharacter(kathy);
	}

	cout << "\n";
	// TODO print all the list out
	for (int i = 0; i < people.getCharacterCount(); i++) {
		cout << people.getCharacter(i) << "\n";
	}

	/*
	
		1     2     3    4    5
       |id,name, date    |    |     |    |    |
	
		items[i].getItemId()
		items[i]->
	
		(*ptr).getX();
		ptr->getX()




		int *nums[100];

	*/




	return 0;
}