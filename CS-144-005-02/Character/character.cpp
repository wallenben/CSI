#include "character.h"




string Item::getName() {
	return name;
}


int Item::getType() {
	return type;
}

// setters
void Item::setName(string nName) {
	name = nName;
}



void Item::setType(int nType) {
	if (nType >= 0) {
		type = nType;
	}
}



string Character::getName() {
	return name;
}

int Character::getLevel() {
	return level;
}

Item Character::getLeft() {
	return left;
}

Item Character::getRight() {
	return right;
}

void Character::setName(string nName) {
	name = nName;
}

void Character::setLevel(int nLevel) {
	level = nLevel;
}

void Character::setLeft(Item item) {
	left = item;
}

void Character::setRight(Item item) {
	right = item;
}






ostream & operator<<(ostream& out, const Item& item) {
	// name (type)
	out << item.name << " (" << item.type << ")";

	return out;
}

