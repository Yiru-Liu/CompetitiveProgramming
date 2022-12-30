/*
ID: yiru.li1
TASK: ride
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");

    unsigned char cometName[8] = { };
    unsigned char groupName[8] = { };
    fin >> cometName >> groupName;

    long long cometNumber = 1;
    long long groupNumber = 1;

    int i;
    for(i = 0; i < 6; ++i) {
        if(cometName[i] == 0) {
            break;
        }
        cometNumber *= cometName[i] - 64;
    }
    cometNumber %= 47;

    for(i = 0; i < 6; ++i) {
        if(groupName[i] == 0) {
            break;
        }
        groupNumber *= groupName[i] - 64;
    }
    groupNumber %= 47;

    if(cometNumber == groupNumber) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }
    return 0;
}
