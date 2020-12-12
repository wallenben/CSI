#include "lab8.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    Order x;
    x.addItem(52943, "2019-11-12", "FKE-4392");
    x.addItem(933, "2009-11-12", "Fa-4392");
    cout << x;



    
    
    /*
 Order order1;
    order1.addItem(5207, "2005-11-14", "asdf");
    order1.addItem(3, "", "");
    order1.addItem(37, "2000", "eeeee");
    order1.addItem(-3000, "16", "item name");
    order1.addItem(0, "0", "0");
    order1.addItem(1337, "1337-13-37", "leet");

*/
   


    /*
    cout << order1.findItem(1337) << '\n';
    cout << order1.getItem(5) << '\n';
    cout << order1.removeItem(1337) << '\n';
   
    cout << order1.findItem(1337) << '\n';
    cout << order1.getItem(3) << '\n'; 
    cout << order1.removeItem(-3000) << '\n';
   
    cout << order1.findItem(0) << '\n';
    cout << order1.getItem(3) << '\n';
    cout << order1.removeItem(0) << '\n';
    cout << order1.findItem(0) << '\n';

    //cout << item1.getItemID() << endl;
    //cout << item1.getItemName() << endl;
    //cout << item1.getItemDate() << endl;
    
   /* Item x(10000, "2020", " ");
    cout << "Item ID: " << x.getItemId() << " " << "Item Date: " << x.getDate() << " " << "Item Name: " << x.getName() << '\n';
    */
   /* Order order1;
    order1.addItem(5202, "2019-11-14", "Stuff");
    // these only work if << operator is working
    // if not, use the member functions to print the data out
    // should print 1 5202 2019-11-14 Stuff
    cout << order1.getCount() << " " << order1.getItem(0) << "\n";
    order1.addItem(53535, "2016-12-08", "More Stuff");
    cout << order1 << "\n"; // prints two orders
    // should print -1 and some spaces since it is invalid
    cout << order1.getItem(5) << "\n";
    cout << order1.findItem(53535) << "\n"; // prints 1
    cout << order1.removeItem(5202) << "\n"; // prints true (1)
    // prints just the second 
   /* Item yum;
    Order order1;
    order1.addItem(5202, "2019-11-14", "Stuff");
    order1.addItem(53535, "2016-12-08", "More Stuff");
    cout << "Item number: " << order1.findItem(5202) << endl;
    cout << "Item count: " << order1.getCount() << endl;
   // cout << order1.findItem(53535) << "\n";
    cout << order1.removeItem(5202) << "\n";
    cout << "testing..finding item.. (-1) on successful removal: " << order1.findItem(5202) << endl;
    cout << order1 << "\n";
    */

    //todo:

    //addItem (should) work fine. Learned a lot about arrays today.
    //I need to polish up getCount so I can verify that these functions work properly
    //finish Lab tomorrow!
}