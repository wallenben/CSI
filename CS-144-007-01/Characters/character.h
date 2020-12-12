#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Item {
private: // only within the class
	string name;
	int type;

public: // accessible by everyone
	//constructor
	// default constructor (also known as a null constructor)
	//	no parameters
	Item();
	Item(string nName, int nType);

	//getters
	string getName() const;
	int getType() const;
	//setters
	void setName(string nName);
	void setType(int nType);


	friend ostream& operator<<(ostream& out, const Item &item);

};


class Character {
public:
	string getName() const;
	int getLevel() const;
	Item * getRight() const;
	Item * getLeft() const;

	void setName(string nName);
	void setLevel(int nLevel);
	void setRight(Item item);
	void setLeft(Item item);

	Character();
	Character(string nName);
	// copy constructor
	Character(const Character &ch);
	~Character(); //destructor
	Character& operator=(const Character& ch);


	// other functions
	// leveling up, removing items
private:
	string name;
	int level;
	Item *rightHand;
	Item *leftHand;

	friend ostream& operator<<(ostream& out, const Character& ch);

};





class CharacterList {
private:
	// dynamic array
	Character *chars;
	int count; // how many values
	int size; // length of the array

public:
	// constructor
	CharacterList();
	// getters/setters
	int getCharacterCount() const;
	Character getCharacter(int pos) const;
	bool addCharacter(Character ch);
	// other functions

};




