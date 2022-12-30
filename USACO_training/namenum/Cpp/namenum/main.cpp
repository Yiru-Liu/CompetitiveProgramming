/*
ID: yiru.li1
TASK: namenum
PROG: namenum
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

#define MAX_NUM_ACCEPTABLE_CATTLE_NAMES 5000
#define MAX_CATTLE_NAME_LENGTH 12

using namespace std;

/*
          2: A,B,C     5: J,K,L    8: T,U,V
          3: D,E,F     6: M,N,O    9: W,X,Y
          4: G,H,I     7: P,R,S
*/

int charToNum(char charToConvert) { // a function to convert a char to its corresponding number
    switch(charToConvert) {
        case 'A':
        case 'B':
        case 'C':
            return 2; break;
        case 'D':
        case 'E':
        case 'F':
            return 3; break;
        case 'G':
        case 'H':
        case 'I':
            return 4; break;
        case 'J':
        case 'K':
        case 'L':
            return 5; break;
        case 'M':
        case 'N':
        case 'O':
            return 6; break;
        case 'P':
        case 'R':
        case 'S':
            return 7; break;
        case 'T':
        case 'U':
        case 'V':
            return 8; break;
        case 'W':
        case 'X':
        case 'Y':
            return 9; break;
        default:
            return -1; break;
    }
}

int main() {
    ofstream fout ("namenum.out");  // input file
    ifstream fin ("namenum.in");    // output file
    ifstream dictin ("dict.txt");   // dictionary of acceptable names

    string validNames[MAX_NUM_ACCEPTABLE_CATTLE_NAMES] = {};  // char array to store dictionary of acceptable names
    for(int i = 0; i < MAX_NUM_ACCEPTABLE_CATTLE_NAMES; ++i) {  // get the dictionary of acceptable names from the file to the char array:
        dictin >> validNames[i];
        cout << validNames[i] << " ";
    }

    int64_t validNameNums[MAX_NUM_ACCEPTABLE_CATTLE_NAMES] = {};    // the numbers of the names
    int currentNameLength;  // int to store to the length of the current name in the loop
    int currentInt; // current int that the loop has converted to a number
    for(int i = 0; i < MAX_NUM_ACCEPTABLE_CATTLE_NAMES; ++i) {  // convert the names to the numbers of the names:
        currentNameLength = validNames[i].length(); // get the current name length
        for(int j = 0; j < currentNameLength; ++j) {    // cycle through each character of the string:
            validNameNums[i] *= 10; // by multiplying the current value of the int by 10, we shift each of the digits to the left by one digit and leave a 0 in the units digit, so the current int could be added on.
            currentInt = charToNum(validNames[i].at(j));    // get the current int
            if(currentInt == -1) {  // if the current char is invalid (is a 'Q' or a 'Z'):
                validNameNums[i] = -1;  // assign a -1 as the number of the name (to mark the name as invalid)
                break;  // exit the loop to move on to the next word
            } else {    // if the char is valid:
                validNameNums[i] += currentInt; // add the current int to the number of the name
            }
        }
    }
    cout << endl;
    for(int64_t heccinhecc : validNameNums) {
        cout << heccinhecc << " ";
    }
    cout << endl << endl;

    int64_t cowNum; // the serial number of the cow
    fin >> cowNum;  // get from input file
    cout << cowNum << endl;

    bool validNameNotFound = true;
    for(int i = 0; i < MAX_NUM_ACCEPTABLE_CATTLE_NAMES; ++i) {
        if(cowNum == validNameNums[i]) {
            fout << validNames[i] << endl;
            validNameNotFound = false;
        }
    }

    if(validNameNotFound) {
        fout << "NONE" << endl;
    }

    return 0;
}
