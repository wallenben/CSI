#include "character.h"


Item::Item() {
	// goal: initialize all class variables
	name = "Item";
	type = 0;
}

Item::Item(string nName, int nType) {
	name = nName;
	if (nType >= 0) {
		type = nType;
	}
	else {
		type = 0;
	}
}


string Item::getName() const {
	return name;
}

int Item::getType() const {
	return type;
}
//setter
void Item::setName(string nName) {
	name = nName;
}

void Item::setType(int nType) {
	if (nType >= 0) {
		type = nType;
	}
}



Character::Character() {
	name = "No Name";
	level = 1;
	leftHand = nullptr;
	rightHand = nullptr;
	// leftHand = Item("Empty", 0);
	// rightHand - uses default constructor
}

Character::Character(string nName) {
	name = nName;
	level = 1;
	leftHand = nullptr;
	rightHand = nullptr;
	//leftHand = Item("Empty", 0);
	// rightHand - uses default constructor
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

// destructor
Character::~Character() {
	delete leftHand;	// it is safe to delete nullptr
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

Item * Character::getLeftHand() const {
	return leftHand;
}

Item * Character::getRightHand() const {
	return rightHand;
}

void Character::setName(string nName) {
	name = nName;
}

void Character::setLevel(int nLevel) {
	level = nLevel;
}

void Character::setLeftHand(Item item) {
	delete leftHand;
	leftHand = new Item; // TODO Fix this
	leftHand->setName(item.getName());
	leftHand->setType(item.getType());
}

void Character::setRightHand(Item item) {
	delete rightHand;
	rightHand = new Item(item.getName(), item.getType()); // TODO Fix this
}




ostream & operator<<(ostream& out, const Item& item) {
	// name (type)
	out << item.name << " (" << item.type << ")";

	return out;
}


ostream& operator<<(ostream& out, const Character& ch) {
	// name (level)
	// Left: left
	// Right: right
	out << ch.getName() << " (" << ch.getLevel() << ")\n";
	if (ch.getLeftHand() == nullptr) {
		out << "Left: Empty\n";
	}
	else {
		out << "Left: " << ch.getLeftHand()->getName() << "\n";
	}
	if (ch.getRightHand() == nullptr) {
		out << "Right: Empty\n";
	}
	else {
		out << "Right: " << (*ch.getRightHand()).getName() << "\n";
	}

	return out;
}



CharacterList::CharacterList() {
	count = 0;
	size = 6;
	people = new Character[size];
}

CharacterList::CharacterList(const CharacterList& cl) {
	count = cl.count;
	size = cl.size;
	// create a new array
	// copy values from cl to my people
}



CharacterList::~CharacterList() {
	delete[] people;
}



// getters/setters
int CharacterList::getCharacterCount() {
	return count;
}

Character CharacterList::getCharacter(int pos) {
	if (pos >= 0 && pos < count) {
		return people[pos];
	}

	Character dummy;
	return dummy;
}


void CharacterList::growArray() {
	// create a new, bigger array
	Character* newPeople = new Character[size + 3];
	// copy the old array into the new array
	for (int i = 0; i < size; i++) {
		newPeople[i] = people[i];
	}
	// delete the old array
	delete[] people;
	// point our class variable to the new array
	people = newPeople;
	// increase size
	size += 3;
}

bool CharacterList::addCharacter(Character ch) {
	// check if the array is full
	if (count == size) {
		// grow the array
		growArray();
	}
	
	// put the character in the array
	people[count] = ch;
	// count the character
	count++;
	return true;
}





