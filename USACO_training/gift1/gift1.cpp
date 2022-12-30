/*
ID: yiru.li1
TASK: gift1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findInStringArray(string arr[], int arrLength, string stringToFind) {
    for(int i = 0; i < arrLength; ++i) {
        if(arr[i] == stringToFind) {
            return i;
        }
    }
    return -1;
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");

    int np;
    fin >> np;

    string names[np] = { };

    long long accounts[np] = { };

    int i;
    for(i = 0; i < np; ++i) {
        fin >> names[i];
    }

    string currentPerson;
    string currentPersonGivingTo;
    int amountGiving;
    int currentPersonIndex;
    int currentPersonGivingToIndex;
    int numPeopleGivingTo;
    int eachPersonAmount;
    int j;
    for(i = 0; i < np; ++i) {
        fin >> currentPerson;
        currentPersonIndex = findInStringArray(names, np, currentPerson);
        fin >> amountGiving;
        fin >> numPeopleGivingTo;
        if(numPeopleGivingTo != 0) {
            eachPersonAmount = amountGiving / numPeopleGivingTo;
            accounts[currentPersonIndex] += -amountGiving + (amountGiving % numPeopleGivingTo);
            for(j = 0; j < numPeopleGivingTo; ++j) {
                fin >> currentPersonGivingTo;
                currentPersonGivingToIndex = findInStringArray(names, np, currentPersonGivingTo);
                accounts[currentPersonGivingToIndex] += eachPersonAmount;
            }
        }
    }

    for(i = 0; i < np; ++i) {
        fout << names[i] << " " << accounts[i] << endl;
    }

    return 0;
}
