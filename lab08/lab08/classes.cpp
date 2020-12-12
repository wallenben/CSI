/*
* @file classes.cpp
*
* @brief Contains the functions necessary for the Item and order classes to work.
*
* This cpp file contains the functions declared in lab8.h. Essentially, these
* functions have the ability to assign Items to an Order class (containing an
* array of items), and can perform various activities to them, e.g. finding
* a specific value, removing a value, and adding a value.
*
* @date 7 - Dec - 2020
* @author Ben Wallen
*/

#include "lab8.h"
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;
Item::Item() {
    id = -1;
    date = "";
    name = "";
}
int Item::getItemId() const {
    return id;
}
string Item::getDate() const {
    return date;
}
string Item::getName() const {
    return name;
}
//second constructor -- not a function
Item::Item(int id2, string date2, string name2) {
    id = id2;
    date = date2;
    name = name2;
}

Order::Order() {
    //this could be -1 or zero depending on code-logic used farther on
    //if we need to call this inside of the array later, leave at -1. 
    //if errors are thrown, change to zero
    numOfItems = 0;
}

int Order::getCount() const {
    return numOfItems;
}

Item Order::getItem(int itemPosition) const {
    if (itemPosition <= 9 && itemPosition >= 0) {
        //the prompt makes little sense here, but i believe this was implemented properly
        return array[itemPosition];

    }
    else {
        Item z;
        return z;
        /**
         * test this -- PROMPT:
         * If it is not valid, create an Item variable using the default
         * constructor (so that the  has an id of -1 and a date and name of "").
         * Return that value.
         */
    }
}
bool Order::addItem(int itemID, string itemDate, string itemName) {
    if (numOfItems > 9) {
        return false;
    }
    else
    {
        Item var(itemID, itemDate, itemName);
        array[numOfItems] = var;
        ++numOfItems;
        return true;
    }
}
//function works fine now
int Order::findItem(int itemID) const {
    bool posCheck = false;
    //the array item ID matches the parameter
    for (int i = 0; i < numOfItems; ++i) {
        int z = array[i].getItemId();
        if (z == itemID) {
            posCheck = true;
            return i; //itempostition 1;
        }
    }
    if (posCheck == false) { return -1; }
}

bool Order::removeItem(int itemID) {
    int x = 0; // this is the position of the item
    x = findItem(itemID);
    if (x == -1) {
        return false;
    }
    else {
        for (int z = x; z < numOfItems; z++) {
            array[z] = array[z + 1];
        }
        numOfItems--;
        return true;
    }

}

ostream & operator << (ostream & out, const Item & item) {
    // name (type)
    out << right << setw(8) << item.getItemId() << " " << left << setw(10) 
        << item.getDate() << " " << left << item.getName();
    return out;
}
ostream & operator << (ostream & out, const Order & order) {
    // name (type)
    for (int i = 0; i < order.getCount(); ++i) {
        Item z = order.getItem(i);
        out << "Array position: " << setw(5) << i << endl << "Item ID: "
            << setw(5) << z.getItemId() << endl <<
            "Item Date: " << setw(5) << z.getDate() << endl 
            << "Item name: " << setw(5) << z.getName() << endl;
    }
    return out;
}
