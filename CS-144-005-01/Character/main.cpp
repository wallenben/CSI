#include "character.h"
#include <iostream>
#include <sstream>

using namespace std;

int main() {

	Item item1;
	Item item2;
	Item item3("Corgie", 5);
	Character carl("Carl the Clumsy");

	// TODO make it easier to print
	// TODO make sure everything is initialized
	item1.setName("Sword of Swords");
	item1.setType(2);

	item2.setName("Kitty");

	cout << carl << "\n";

	//carl.setName("Carl the Clumsy");
	//carl.setLevel(1);
	carl.setRightHand(item1);
	carl.setLeftHand(item2);

	cout << "Name: " << item1.getName() << " Type: " << item1.getType()
		<< "\n";

	cout << "Name: " << item2.getName() << " Type: " << item2.getType()
		<< "\n";
	cout << item1 << "\n";



	cout << carl.getName() << " (" << carl.getLevel() << ")\n"
		<< "Left: " << (*carl.getLeftHand()).getName() << "\n"
		<< "Right: " << carl.getRightHand()->getName() << "\n";
	cout << carl;
	cout << item3 << '\n';

	//carl = carl2;
	Character carl2(carl);

	carl2 = carl;

	carl2 = carl2;

	CharacterList cast;
	cast.addCharacter(carl);

	cout << cast.getCharacter(0) << "\n";

	for (int i = 0; i < 61; i++) {
		// create a new character
		stringstream name;
		name << "Carl " << (i + 2);
		Character ch(name.str());
		// add some items to the character
		Item stout("UW Stout", 11);
		ch.setRightHand(stout);
		// store them in the list
		cast.addCharacter(ch);
	}

	// TODO print out all of the characters

	for (int i = 0; i < cast.getCharacterCount(); i++) {
		cout << cast.getCharacter(i) << "\n";
	}



	return 0;
}