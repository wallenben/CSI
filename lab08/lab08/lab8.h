#ifndef CLASSES_H_2020_12_7
#define CLASSES_H_2020_12_7
#include <iostream>
#include <string>
using std::ostream;
using std::string;

#pragma once
/**
 * @class Item
 * @brief stores item information for the order
 * Represents an item (that will be "ordered") by the company.
 * Access is provided to the getter functions, as well as the
 * ostream operator, which are used by the Order class below.
 * @see class Order
 * Private variables include the item ID, date, and number,
 * as shown below.
 *
 * Tests: (basic formatting applied to the cout line for readability):
 * item x(3, "2019-02", "bruh");
 * cout << x.getItemId() << x.getDate() << x.getName() << '\n';
 * Output: Item ID: 3 Item Date: 2019-02 Item Name: bruh
 *
 * item x(-5, "2020-07-03", "Bruh Bruh");
 * cout << x.getItemId() << x.getDate() << x.getName() << '\n';
 * Output: Item ID: -5 Item Date: 2020-07-03 Item Name: Bruh Bruh
 *
 * item x(10000, "2020", " ");
 * cout << x.getItemId() << x.getDate() << x.getName() << '\n';
 * Output: Item ID: 10000 Item Date: 2020 Item Name:
 *
 */
class Item {
private:
    /**Item ID variable */
    int id;
    /**Item date*/
    string date;
    /**Item name*/
    string name;
public:
    /**
     * @brief Default constructor for the Item class
     * Default constructor for Item. Sets the item in
     * question to an ID of zero, and nulls the strings
     * (all strings are empty, defined with "").
     */
    Item();
    /**
     * @brief Constructor for the Item class
     * Constructor for Item. Sets the item in
     * question to an ID of id2, the date to
     * date2, and the name to name2.
     * @param id2 is the var assigned to class::id
     * @param date2 is the var assigned to class::date
     * @param name2 is the var assigned to class::name
     */
    Item(int id2, string date2, string name2);
    /**
     * @brief returns the item ID.
     * This getter returns the item ID when called.
     * @return the item ID.
     */
    int getItemId() const;
    /**
     * @brief returns the item date.
     * This getter returns the item date when called.
     * @return the item date.
     */
    string getDate() const;
    /**
     * @brief returns the item name.
     * This getter returns the item name when called.
     * @return the item name.
     */
    string getName() const;
    /**
     * @brief outputs the item ID, name, and date
     * This ostream operator will print out the item ID,
     * name, and date when called.
     * @param out is the output stream being used
     * @param item is the item being referenced
     * to output the data
     * @return ostream& out on completion
     */
    friend ostream& operator << (ostream& out, const Item& item);
};
/**
 * @class Order
 * @brief this class represents the order, containing up to ten items.
 * Represents the order (the order containing multiple items)
 * @see class Item
 * This class allows the usage of multiple getter functions,
 * which are used by the ostream operator later on to compile
 * the information.
 * Private variables include an array (for storing Item values)
 * and an integer value for the number of items in an array.
 *
 * Test:
 * Order order1;
 * order1.addItem(5207, "2005-11-14", "asdf");
 * order1.addItem(3, "", "");
 * order1.addItem(37, "2000", "eeeee");
 * order1.addItem(-3000, "16", "item name");
 * order1.addItem(0, "0", "0");
 * order1.addItem(1337, "1337-13-37", "leet");
 * cout << order1.findItem(1337) << '\n';
 * cout << order1.getItem(5) << '\n';
 * cout << order1.removeItem(1337) << '\n';
 * Output: findItem = 5, getItem = 1337 1337-13-37 leet, removeItem = 0
 *
 * cout << order1.findItem(1337) << '\n';
 * cout << order1.getItem(3) << '\n';
 * cout << order1.removeItem(-3000) << '\n';
 * Output: findItem = 5, getItem = -3000 16 item name, removeItem = 0
 *
 * cout << order1.findItem(0) << '\n';
 * cout << order1.getItem(3) << '\n';
 * cout << order1.removeItem(0) << '\n';
 * Output: findItem = 4, getItem = -3000 16 item name, removeItem = 0
 *
 */
class Order {
public:
    /**
    * @brief Default constructor for the Order class
    * Default constructor for Order. Sets the number
    * of variables in the array to zero.
    */
    Order();
    /**
     * @brief returns the items in the array.
     * This getter returns the items in the array when called.
     * @return the items in the array.
     */
    int getCount() const;
    /**
     * @brief returns one item in the array.
     * This getter returns one item in the array when called.
     * @param itemPosition is the position of the Item in question
     * @return the item in the array.
     */
    Item getItem(int itemPosition) const;
    /**
    * @brief adds an item into the array.
    * This  adds one item in the array when called.
    * @param itemID is the Item ID
    * @param itemDate is the Item date
    * @param itemName is the name of the Item
    * @return 1 on success.
    */
    bool addItem(int itemID, string itemDate, string itemName);
    /**
    * @brief finds the position of an item in the array.
    * This finds the position of an item in the array
    * when called. This is achieved by looking for the itemID
    * @param itemID is the Item ID
    * @return the item position on success.
    */
    int findItem(int itemID) const;
    /**
    * @brief removes an item in the array.
    * This finds the position of an item in the array
    * when called. This is achieved by looking for the itemID
    * @param itemID is the Item ID
    * @return 1 on success.
    */
    bool removeItem(int itemID);
   /**
    * @brief outputs values in the array
    * This ostream operator will print out the item ID,
    * name, and date when called for each item in the array
    * @param out is the output stream being used
    * @param order is the order object being referenced
    * to read data from
    * @return ostream& out on completion
    */
    friend ostream& operator<<(ostream& out, const Order& order);
private:
    /**Array of items used*/
    Item array[10];
    /**Number of items in the array*/
    int numOfItems;
};
#endif