/*
ID: yiru.li1
TASK: palsquare
PROG: palsquare
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/* A utility function to reverse a string  */
void reverseString(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end) {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

string intToStringNon10Base(int numToConvert, int base) {   // convert an int to a string in a specified number base
    char str[500] = {};
    int i = 0;
    int remainder;

    while(numToConvert != 0) {
        remainder = numToConvert % base;
        str[i++] = (remainder > 9) ? (remainder-10) + 'A' : remainder + '0';
        numToConvert = numToConvert/base;
    }

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverseString(str, i);

    return str;
}

bool checkIfStringIsPalindrome(string stringToCheck) {
    int halfStringLength = stringToCheck.length()/2;
    string firstHalf = stringToCheck.substr(0, halfStringLength);
    string secondHalf = stringToCheck.substr(stringToCheck.length()%2==0 ? halfStringLength : halfStringLength+1, halfStringLength);
    reverse(secondHalf.begin(), secondHalf.end());
    return firstHalf == secondHalf;
}

int main() {
    ofstream fout ("palsquare.out");// output file
    ifstream fin ("palsquare.in");  // input file

    int numBase;
    fin >> numBase;
    string currentNumSquaredString;

    for(int i = 1; i <= 300; ++i) {
        currentNumSquaredString = intToStringNon10Base(i*i, numBase);
        if(checkIfStringIsPalindrome(currentNumSquaredString)) {
            fout << intToStringNon10Base(i, numBase) << " " << currentNumSquaredString << endl;
        }
    }
    return 0;
}
