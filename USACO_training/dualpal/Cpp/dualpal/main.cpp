/*
ID: yiru.li1
TASK: dualpal
PROG: dualpal
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
    ofstream fout ("dualpal.out");// output file
    ifstream fin ("dualpal.in");  // input file

    int32_t n;
    fin >> n;
    int32_t s;
    fin >> s;

    int numsFound = 0;
    bool palindromicInAtLeaseOneBase = false;

    for(int i = s+1; numsFound < n; ++i) {   // cycle through each number greater than s
        for(int j = 2; j <= 10; ++j) {  // cycle through the bases 2 to 10
            if(checkIfStringIsPalindrome(intToStringNon10Base(i, j))) {
                if(palindromicInAtLeaseOneBase) {
                    fout << i << endl;
                    ++numsFound;
                    break;
                } else {
                    palindromicInAtLeaseOneBase = true;
                }
            }
        }
        palindromicInAtLeaseOneBase = false;
    }

    return 0;
}
