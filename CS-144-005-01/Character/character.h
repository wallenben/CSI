#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Item {
private: // no one outside of class
	string name;
	int type;

public: // any one can use
	// constructors
	// default constructor (also known as null constructor)
	//	no parameters
	Item();
	Item(string nName, int nType);

	//getters
	string getName() const;
	int getType() const;
	//setter
	void setName(string nName);
	void setType(int nType);
	//other useful functions

	friend ostream & operator<<(ostream &out, const Item &item);


};


// TODO create a Character class
class Character {
private:
	string name;
	int level;
	Item *leftHand;
	Item *rightHand;

public:
	Character();
	Character(string nName);
	// copy constructor
	Character(const Character &ch);
	// destructor
	~Character();

	Character & operator=(const Character &ch);

	string getName() const;
	int getLevel() const;
	Item * getLeftHand() const; // TODO make pointers
	Item * getRightHand() const;

	void setName(string nName);
	void setLevel(int nLevel);
	void setLeftHand(Item item); // TODO make pointers
	void setRightHand(Item item);

	// other functions
	// level up, remove item

	friend ostream& operator<<(ostream& out, const Character& ch);
};


class CharacterList {
private:
	//dynamic array
	Character *people;
	int count;
	int size;

	void growArray();

public:
	// constructor
	CharacterList();
	CharacterList(const CharacterList& cl);
	~CharacterList();
	// getters/setters
	int getCharacterCount();
	Character getCharacter(int pos);
	bool addCharacter(Character ch);
	// other functions



};


