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
	//All data comes from the character. We can copy this for another function here.
	name = ch.getName();
	level = ch.level;
	leftHand = nullptr;
	rightHand = nullptr;
	/*
	Oh boy, left and right are set at null pointers, but that is not the only problem here.
	Even if we fix that, we still have to deal with the fact that they are items.
	The two pointers would point to the same memory object, corrupting memory and wrecking the data. 
	Using ch.leftHand/ch.rightHand is BAD. We will have to use "new". It will create a copy and use
	the respective memory. We will have to delete it later though.
	*/
	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	//We're using a different constructor here, as the above constructor takes in a name + type.
	//We're using the copy constructor here, as it will need just an item and then be fine. It's cleaner than the above.
	//This will be CRUCIAL for Project 3
	if (ch.leftHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}
}

Character::~Character() {
	delete leftHand;
	leftHand = nullptr;
	delete rightHand;
	rightHand = nullptr;

	//Not necessary but its a good thing to do. If we delete it, then we should set it to a
	//nullptr or another good piece of data. However, bizzarely, it is actually safe to delete
	//a nullptr, as it doesn't do anything. DON'T assume that for anything else.
	
}

Character& Character::operator=(const Character& ch) {

	//Check for self assignment
	if (this == &ch) {
		return *this;
	}

	//The assignment operator is the destructor followed by the copy constructor
	delete leftHand;
	delete rightHand;

	//Then we can CTRL+C and CTRL+V our copy constructor

	name = ch.getName();
	level = ch.level;
	leftHand = nullptr;
	rightHand = nullptr;
	
	if (ch.leftHand != nullptr) {
		leftHand = new Item(ch.leftHand->getName(), ch.leftHand->getType());
	}
	
	if (ch.leftHand != nullptr) {
		rightHand = new Item(*ch.rightHand);
	}

	//Now, we would have to return the character reference. We can use "this"
	//It is pointing to something, the correct thing, but this is a pointer and not an object.
	//De-reference it!
	return *this;

}


string Character::getName() const {
	return name;
}

int Character::getLevel() const {
	return level;
}

Item *Character::getRight() const {
	return rightHand;
}

Item *Character::getLeft() const {
	return leftHand;
}

void Character::setName(string nName) {
	name = nName;
}

void Character::setLevel(int nLevel) {
	level = nLevel;
}

void Character::setRight(Item item) {
	//When we create an item, we will know that we will use one of our constructors. If we don't give it
	//any parenthesis (or no params), it will call/use the default constructor. If we do, then we have to 
	//create a constructor to fix that.
	rightHand = new Item(item.getName(), item.getType());
	//This will create the same data as the one in our parameter. We could use a copy constructor here as it
	//would be shorter.
}

void Character::setLeft(Item item) {
	//Lets do a different approach for left.

	//We can still use new item and a default constructor, but we can use setters! 
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
	//Derferencing a null pointer will crash your program.
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
		out << "Right: " << ch.getRight()->getName();
	}

	return out;
}

istream& operator>>(istream& in, Character& ch) {
	delete ch.leftHand;
	delete ch.rightHand;

	//Assume that we will read in the data by name, level, left (name and type/none), right (same as left).
	string name;
	in >> name;
	//The name isn't inside a character. It needs that name. We have to assign it since it is a friend.
	ch.name = name;

	string itemName;
	int type;

	in >> itemName;
	if (itemName == "None") {
		ch.leftHand = nullptr;
	}
	else {
		in >> type;
		ch.leftHand = new Item(itemName, type);
	}

	in >> itemName;
	if (itemName == "None") {
		ch.rightHand = nullptr;
	}
	else {
		in >> type;
		ch.rightHand = new Item(itemName, type);
	}


	return in;
}

CharacterList::CharacterList() {
	count = 0;
	size = 16;
	chars = new Character[size];
}

CharacterList::CharacterList(const CharacterList& cl) {
	count = cl.count;
	size = cl.size;
	chars = new Character[];

	//Copies everything over in the array
	for (int i = 0; i < count; i++) {
		chars[i] = cl.chars[i];
	}
}

CharacterList& CharacterList::operator=(const CharacterList& cl) {
	//Check for self-assignment
	if (this == &cl) {
		return *this;
	}

	//destroy
	delete[] chars;
	//copy
	count = cl.count;
	size = cl.size;
	chars = new Character[];

	//Copies everything over in the array
	for (int i = 0; i < count; i++) {
		chars[i] = cl.chars[i];
	}

	return *this;
}

CharacterList::~CharacterList() {
	delete[] chars;
}

int CharacterList::getCharacterCount() const{
	return count;
}
//Can decide which character in the array to return

Character CharacterList::getCharacter(int pos) const{
	if (pos >= 0 && pos < count) {
		return chars[pos];
	}

	Character invalid;
	return invalid;
}

void CharacterList::growArray() {
	//create a new, bigger array
	Character* newChars = new Character[size + 5];
	//copy over the data into the new array
	for (int i = 0; i < size; i++) {
		newChars[i] = chars[i];
	}
	//release the old array
	delete[] chars;
	//make the class pointer point to the new array
	chars = newChars;
	//increase the size
	size += 5;
}

bool CharacterList::addCharacter(Character ch) {
	// check if there is room
	if (count == size) {
		//grow the array
		growArray();
	}
	//add the new character
	chars[count] = ch;
	count++;
	return true;
}

