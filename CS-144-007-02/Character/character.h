#pragma once

#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Item {
private: //only the class can use it
	string name;
	int type;
	

public: // anyone can use
	// getters
	string getName();
	int getType();

	// setters
	void setName(string nName);
	void setType(int nType);

	// other useful functions

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

	void setLeft(Item nLeft);
	void setRight(Item nRight);
	void setName(string nName);
	void setLevel(int nLevel);

	// other functions
	// leveling up, remove items

};





