/**
* @file Rectangle.cpp
*
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
* @author turners
* @date 2016-09-12
*
*/
#include <string>
#include <iostream>
using namespace std;
/**
* @brief Computes the area and perimter of a rectangle.
*
* This computes the area and perimeter of a rectangle given
* the rectangle's length and width.
*
*
* @return 0 is sucessful, non-0 on error
*
*
* Input:
* length: 5.5, width: 10
* Expected:
* perimeter: 31, area: 55
*
*
* Input:
* length: 10: width 10
* Expected:
* perimeter: 40, area: 100
*
*
* Input:
* length -5: width -3
* Expected:
* perimeter: -16, area: 15
*
*
*
*/
int main() {
	double length;
	double width;
	double perimeter;
	double area;

	//prompt for and read in length and width
	cout << "Enter the length of the rectangle: ";
	cin >> length;

	cout << "Enter the width of the rectangle: ";
	cin >> width;

	//compute perimeter and area
	perimeter = (2 * (length + width));
	area = width * length;

	//output results
	cout << "For a " << length << " x " << width
		<< " rectangle, the perimeter is " << perimeter << " and the area is "
		<< area << ".\n";

	return 0;


}