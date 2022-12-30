/*
ID: yiru.li1
TASK: milk2
PROG: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int32_t minElementInt(int32_t arr[], int16_t arrLength) {
    int32_t minElement = 1000001;
    for(int16_t j = 0; j < arrLength; ++j) {
        if(arr[j] < minElement) {
            minElement = arr[j];
        }
    }
    return minElement;
}

int32_t maxElementInt(int32_t arr[], int16_t arrLength) {
    int32_t maxElement = 0;
    for(int16_t j = 0; j < arrLength; ++j) {
        if(arr[j] > maxElement) {
            maxElement = arr[j];
        }
    }
    return maxElement;
}

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

    int16_t n;  // number of farmers
    fin >> n;   // Get from input

    int32_t startingTimes[n];   // array of starting milking times of the farmers
    int32_t endingTimes[n];     // array of ending milking times of the farmers

    int16_t i;  // variable to be used in loops and stuff

    /** Get starting and ending times from input **/
    for(i = 0; i < n; ++i) {
        fin >> startingTimes[i];
        fin >> endingTimes[i];
    }
    /********/

    int32_t currentTime = minElementInt(startingTimes, n);    // variable to be used in for loop to keep track of current time loop is on

    int32_t longestMilkingTime = 0; // the longest time of milking
    int32_t startedMilkingTime = 0; // the starting time of the current milking

    int32_t longestIdleTime = 0;    // the longest time of not milking
    int32_t startedIdleTime = 0;    // the starting time of the current not milking

    bool isMilking;     // stores whether or not at least one cow is being milked for the current loop
    bool prevIsMilking = false; // stored whether or not at least one cow was being milked for the previous loop

    const int32_t lastMilkingTime = maxElementInt(endingTimes, n);  // the time when the last farmer ends milking

    for(; currentTime <= lastMilkingTime; ++currentTime) {
        /** Check if currently milking: **/
        isMilking = false;
        for(i = 0; i < n; ++i) {
            if((currentTime >= startingTimes[i]) && (currentTime < endingTimes[i])) {
                isMilking = true;
                break;
            }
        }
        /********/

        /** If there's a change from not milking to is milking: **/
        if(isMilking && !prevIsMilking) {
            if(startedIdleTime != 0) {
                longestIdleTime = max(longestIdleTime, currentTime - startedIdleTime);
            }
            startedMilkingTime = currentTime;
        }
        /********/

        /** If there's a change from is milking to not milking: **/
        if(!isMilking && prevIsMilking) {
            longestMilkingTime = max(longestMilkingTime, currentTime - startedMilkingTime);
            startedIdleTime = currentTime;
        }
        /********/

        prevIsMilking = isMilking;
    }

    fout << longestMilkingTime << " " << longestIdleTime << endl;

    return 0;
}
