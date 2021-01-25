#include <iostream>
using namespace std;
int main() {
    //this formula uses stdev to award more points based on how well the player does
    //stdev allows for point flucuation regardless of map difficulty, completions, etc
    //this also (if stored) can be used to incentivize more surf competition e.g. storing all stdev vars for one user 
    //and averaging it to get a surf "skill" rank
    float mean, time;
    //the mean time. this will have to be recalculated every time a rank is updated
    //number of times - total maptimes. pointnumber is the value multiplied by the number of deviations from mean, probably like 0.5
    int noOfTimes, pointNumber, basePoints;
    //calc deviations
    bool goodtime = false;
    if (time - mean < 0) {
        goodtime = true;
    }
    int calc = pow((abs(time - mean));
    //35 - 40 = -5 == 25
    //this is stdev, use this to discover how far it deviates from mean, disperse points
    calc = sqrt(calc / noOfTimes);
    if (goodtime = true) {
        calc = abs(time - mean) / calc;
        return (calc * pointNumber) + basePoints;
    }
    else {
        return basePoints;
    }

}
/**
 * test cases:
 * surf_aircontrol mean time: 30 seconds, 1000 completions
 * reported time: 25 seconds, considerably faster than avg
 * goodtime = true, better than mean
 * calc = 25
 * calc deviation is 0.025
 * 100 points are returned plus base point allotment
 */
int rank, totalCompletitions, pts;
float time, mean;
pts = time - mean;
if (pts < 0) {
    pts = (abs(pts * 20)) * 1.5;
    return pts;
}
else {
    pts = (abs(pts * 20));
    return pts;
}

/**
 * test cases:
 * time (25) - mean (30) = -5
 * run loop, return 150.
 * if the time is lower than the mean, return 100
 */