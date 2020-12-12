#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Item {
private: // only accessible by the class
	string name;
	int type;
public: // any one can use
	// getters
	string getName();
	int getType();
	// setters
	void setName(string nName);
	void setType(int nType);
	// other functions that are useful

	friend ostream & operator<<(ostream &out, const Item &item);



};


class Character {
private:
	string name;
	int level;
	Item left;
	Item right;

public:
	string getName();
	int getLevel();
	Item getLeft();
	Item getRight();

	void setName(string nName);
	void setLevel(int nLevel);
	void setLeft(Item item);
	void setRight(Item item);

	// other functions
	// leveling up, removing items

};







