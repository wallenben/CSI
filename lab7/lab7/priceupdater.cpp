/*
*
* @file priceupdater.cpp
*
* @brief Contains the functions necessary to update and print prices.
*
*This program will read in a percent (the markup) and a list of prices.
*It will store them in an array and then process the prices by increasing them
*by the markup amount. This markup will only be applied to those prices less than
*$175.00. The program will also compute some basic statistics (the average and maximum).
*Finally, it will be able to print the array out in a nicely formatted
*manner.
*
* @date 30 - Nov - 2020
* @author Ben Wallen
*/

#include "lab7.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;


/**
* @brief Calculates the average
* @param arrayOne is the array being averaged
* @param numVals is the number of values in the array
* Returns the average of the array by using a for loop.
* If the array has no numbers inside of it, the function returns zero.
*
* Tests:
* double arrayOne[3];
    arrayOne[0] = 3;
    arrayOne[1] = 4;
    arrayOne[2] = 5;
    Output = 4
* double arrayOne[1];
    Output = 0
*double arrayOne[2];
    arrayOne[0] = 1;
    arrayOne[1] = 0;
    Output = 0.5
*/
double getAverage(double arrayOne[], int numVals) {
    double averageVal = 0;
    if (numVals == 0) {
        return 0;
    }
    else {
        for (int i = 0; i <= numVals; i++) {
            averageVal += arrayOne[i];

        }
        averageVal = averageVal / (numVals);
        return averageVal;
    }
}
/**
* @brief Calculates the maximum value
* @param arrayTwo is the array being averaged
* @param numVals2 is the number of values in the array
* Returns the maximum of the array by using a for loop.
* If the array has no numbers inside of it, the function returns zero.
*
* Tests:
* double arrayOne[3];
    arrayOne[0] = 3;
    arrayOne[1] = 4;
    arrayOne[2] = 5;
    Output = 5
* double arrayOne[1];
    Output = 0
*double arrayOne[2];
    arrayOne[0] = 1;
    arrayOne[1] = 0;
    Output = 1
*/
double getMaximum(double arrayTwo[], int numVals2) {
    double max = arrayTwo[0];
    if (numVals2 == 0) {
        return 0;
    }
    for (int i = 0; i < numVals2; i++) {
        if (arrayTwo[i] > max) {
            max = arrayTwo[i];
        }
    }
    return max;
}
/**
* @brief Updates prices if they are lower than $175
* @param arrayThree is the array being averaged
* @param numVals3 is the number of values in the array
* @param percentMarkup is the percent being marked up. (decimal)
* This function will change the value of numbers in an array if they
* are lower than $175. It will multiply the amount by the percent markup,
* and add it to the original cost.
*
* Tests:
* Input: arrayOne, 3, 0.05
* double arrayOne[3];
    arrayOne[0] = 3;
    arrayOne[1] = 4;
    arrayOne[2] = 5;
    Output:
    arrayOne[0] = 3.15;
    arrayOne[1] = 4.2;
    arrayOne[2] = 5.25;

* Input: arrayOne, 1, 0.05
* double arrayOne[1];
    arrayOne[0] = 180;
    Output:
    arrayOne[0] = 180

* Input: arrayOne, 2, 0.05
* double arrayOne[2];
    arrayOne[0] = 0;
    arrayOne[1] = 155;
    Output:
    arrayOne[0] = 0;
    arrayOne[1] = 162.75;

*/
int updatePrices(double arrayThree[], int numVals3, double percentMarkup) {
    int prices = 0;
    for (int i = 0; i < numVals3; i++) {
        if (arrayThree[i] < 175) {
            arrayThree[i] = (arrayThree[i] * percentMarkup) + arrayThree[i];
            prices++;
        }
    }
    return prices;
}
/**
* @brief converts an array to a readable string
* @param array is the array being converted
* @param numValues is the number of values in the array
* This function takes an array and converts it to a string format. This
* is accomplished using istream and ostream operators, which output to a string
* called stringOne.
*
* Tests:
* Input: arrayOne, 3
* double arrayOne[3];
    arrayOne[0] = 3;
    arrayOne[1] = 4;
    arrayOne[2] = 5;
    Output: [3, 4, 5]

* Input: arrayOne, 1, 1
* double arrayOne[1];
    arrayOne[0] = 180;
    Output: [180]


* Input: arrayOne, 0
* double arrayOne[0];

    Output: []


*/
string arrayToString(double array[], int numValues) {
    ostringstream ostream;
    ostream << "[";
    for (int i = 0; i < numValues; i++) {
        ostream << array[i];

        if (i < numValues - 1) {
            ostream << ", ";
        }
    }
    ostream << "]";
    return ostream.str();
}
/**
* @brief Inserts a value into an array.
* @param array is the array being utilized.
* @param numVals is the number of values in the array
* @param maxSize is the maximum size of the array
* @param insertVal is the value being inserted
* This function takes a double variable, and inserts it into an already present array.
* Furthermore, this function assumes that the array is properly formatted, and as such
* formats the new variable so the array isn't out of order.
*/
int insertValue2(double array[], int numVals, int maxSize, double insertVal) {
    int counter = numVals;
    if (numVals >= maxSize) {
        return maxSize;
    }
    else {
        while ((counter > 0) && (array[counter - 1] > insertVal)) {
            array[counter] = array[counter - 1];
            --counter;
        }
        array[counter] = insertVal;
        return numVals + 1;
    }
}



int insertValue(double valArray[], int arrayValues, int arraySize, double insertValue) {
    int counter = arraySize; //This will count down from the number of values in the array
    int i;

    //First, we check if the array is full or not.
    if (arrayValues >= arraySize) {
        return arraySize;
    }
    


    i = arraySize;
    //Now, we have to loop backwards over the array. Oh boy...
    for (i; i > 0; i--) {
        //This will start counting down in the array
        if (valArray[i - 1] < insertValue ) {
            break;
        }
        valArray[i] = valArray[i - 1];
        counter--;

    }
    counter--;

    valArray[counter] = insertValue;
    return arrayValues + 1;
}




/**
* @brief Reads data from an array.
* @param inputStream is the input stream used to read in numbers
* @param array is the array being read from
* @param maxNum is the maximum numbers being read in.
* This function reads in data from an array using an inputStream. Furthermore, this
* function utilizes the insertValue function to insert the numbers it reads in into
* an array.
*/
int readData(istream& inputStream, double array[], int maxNum) {
    int count = 0;
    double insertNum;
    inputStream >> insertNum;
    while (inputStream && count < maxNum) {
        array[count] = insertNum;
        count++;
        inputStream >> insertNum;
        cout << array[0] << endl;
        insertValue(array, count, maxNum, insertNum);
        cout << "after:" << endl;
        cout << array[0] << endl;
    }
    return count;
}
/**
* @brief Processes the data from all the functions above
* @param inputStream2 is the input stream used to read in numbers
* @param outputStream is the output method specified by the user
* This function utilizes all the other functions to calculate and format
* the array as specified in the prompt.
*
*/
void processPrices(istream& inputStream2, ostream& outputStream) {
    double array1[25];
    double insertNum = 0;
    double percentMarkup = 0;
    double average = 0;
    double maximum = 0;
    string arrayString;
    int counter = 0;
    int prices = 0;
    inputStream2 >> percentMarkup;
    if (inputStream2.fail()) {
        outputStream << "Error";
    }
    else {
        counter = readData(inputStream2, array1, 25);
        prices = updatePrices(array1, counter, percentMarkup);
        average = getAverage(array1, counter);
        maximum = getMaximum(array1, counter);
        arrayString = arrayToString(array1, counter);
        outputStream << arrayString << '\n' << left << setw(20) << "Percent:" << right
            << setw(5) << fixed << setprecision(1) << (percentMarkup * 100) << "%" << '\n'
            << left << setw(20) << "Average:" << right << setw(5) << fixed << setprecision(2)
            << average << '\n' << left << setw(20) << "Max:" << right << setw(5) <<
            fixed << setprecision(2) << maximum << '\n' << left << setw(20) << "Updated:" <<
            right << setw(5) << prices << '\n';
    }
}