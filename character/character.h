//***HEADER FILE***//

#pragma once

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

class Item {
private: // only within the class
	string name;
	int type;

public: // accessible by everyone
	//constructor
	//default constructor (also known as a null constructor)
	//no parameters
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
	//We will take an item pointer here
	void setRight(Item item);
	void setLeft(Item item);

	Character();
	Character(string nName);
	//A copy constructor NEEDS to be passed by referance and should be const
	Character(const Character &ch);
	//A Destructor has a tilde and NO parameters
	~Character();
	Character& operator=(const Character& ch);

	friend ostream& operator<<(ostream& out, const Character& ch);
	//Pass i by reference but DO NOT MAKE CONST
	friend istream& operator>>(istream& in, Character& ch);

	// other functions
	// leveling up, removing items
private:
	string name;
	int level;

	//We will make these pointers
	Item *rightHand;
	Item *leftHand;


};

class CharacterList {
private:
	//dynamic array. Changing it to a pointer will get new data.
	Character *chars;
	int count; //How many values
	//We will need another variable for the array's length.
	int size; //How big is the array

	//We need a function to grow the array and nobody outside should choose
	void growArray();

public:
	//constructor
	CharacterList();
	//Copy constructior
	CharacterList(const CharacterList &cl);
	//Destructor
	~CharacterList();

	//assignment operator
	CharacterList& operator=(const CharacterList& cl);

	//getters/setters
	int getCharacterCount() const;
	Character getCharacter(int pos) const;
	bool addCharacter(Character ch);
	//other functions
};