#include "character.h"



Item::Item() {
	name = "No Name";
	type = -1;
}

Item::Item(string nName, int nType) {
	name = nName;
	if (nType >= 0) {
		type = nType;
	}
	else {
		type = -1;
	}
}


string Item::getName() const {
	return name;
}

int Item::getType() const {
	return type;
}

//setters
void Item::setName(string nName) {
	name = nName;
}

void Item::setType(int nType) {
	if (nType >= 0) {
		type = nType;
	}
}

Character::Character() {
	name = "No Name Nomad";
	level = 1;
	leftHand = nullptr;
	rightHand = nullptr;
}

Character::Character(string nName) {
	name = nName;
	level = 1;
	leftHand = nullptr;
	rightHand = nullptr;
}

Character::Character(const Character& ch) {
	name = ch.getName();
	level = ch.level;
	leftHand = nullptr;
	rightHand = nullptr;

	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	if (ch.rightHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}
}


Character::~Character() { //destructor
	delete leftHand; // safe to delete nullptr
	leftHand = nullptr;
	delete rightHand;
	rightHand = nullptr;
}

Character& Character::operator=(const Character& ch) {

	// check for self assignment
	if (this == &ch) {
		return *this;
	}

	// destructor
	delete leftHand;
	delete rightHand;

	// copy constructor
	name = ch.getName();
	level = ch.level;
	leftHand = nullptr;
	rightHand = nullptr;

	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	if (ch.rightHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}

	return *this;

}



string Character::getName() const {
	return name;
}

int Character::getLevel() const {
	return level;
}

Item * Character::getRight() const {
	return rightHand;
}

Item * Character::getLeft() const {
	return leftHand;
}

void Character::setName(string nName) {
	name = nName;
}

void Character::setLevel(int nLevel) {
	level = nLevel;
}

void Character::setRight(Item item) {
	rightHand = new Item(item.getName(), item.getType());
}

void Character::setLeft(Item item) {
	leftHand = new Item;
	leftHand->setName(item.getName());
	leftHand->setType(item.getType());
}


ostream& operator<<(ostream& out, const Item& item) {
	// name (type)
	out << item.name << " (" << item.type << ")";

	return out;
}


ostream& operator<<(ostream& out, const Character& ch) {
	// name (level)
	// left
	// right
	out << ch.getName() << " (" << ch.getLevel() << ")\n";
	if (ch.getLeft() == nullptr) {
		out << "Left: Empty\n";
	}
	else {
		out << "Left: " << (*ch.getLeft()).getName() << "\n";
	}
	if (ch.getRight() == nullptr) {
		out << "Right: Empty\n";
	}
	else {
		out << "Right: " << ch.getRight()->getName() << "\n";
	}
	return out;
}




CharacterList::CharacterList() {
	count = 0;
	size = 16;
	chars = new Character[size];
}

// getters/setters
int CharacterList::getCharacterCount() const {
	return count;
}

Character CharacterList::getCharacter(int pos) const {
	if (pos >= 0 && pos < count) {
		return chars[pos];
	}

	Character invalid;
	return invalid;
}


void CharacterList::growArray() {
	// create a new, bigger array
	Character* newChars = new Character[size + 5];
	// copy over the data into the new array
	for (int i = 0; i < size; i++) {
		newChars[i] = chars[i];
	}
	// make the class pointer point to the new array
	chars = newChars;
	// increase the size
	size += 5;
}


bool CharacterList::addCharacter(Character ch) {
	// check if the array if full
	if (count == size) {
		// grow the array
		growArray();
	}

	// add the new character
	chars[count] = ch;
	// count it
	count++;
	return true;
}





