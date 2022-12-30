/*
ID: yiru.li1
TASK: beads
PROG: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

    int numBeads;
    fin >> numBeads;

    char necklace[numBeads+1];
    fin >> necklace;

    int breakingPoint;
    int i;
    int j;

    char brokenNecklace[numBeads+1] = { };

    char currentBeadColor;

    int numCollectedBeads;

    int prevNumCollectedBeads = -1;

    for(breakingPoint = 0; breakingPoint < numBeads; ++breakingPoint) {
        for(i = 0; breakingPoint+i < numBeads; ++i) {
            brokenNecklace[i] = necklace[breakingPoint+i];
        }
        for(j = 0; i < numBeads; ++i) {
            brokenNecklace[i] = necklace[j];
            ++j;
        }

        numCollectedBeads = 2;
        currentBeadColor = brokenNecklace[0];
        for(i = 1; i < numBeads; ++i) {
            if(brokenNecklace[i] == currentBeadColor || brokenNecklace[i] == 'w' || currentBeadColor == 'w') {
                ++numCollectedBeads;
                if(currentBeadColor == 'w') {
                    currentBeadColor = brokenNecklace[i];
                }
            } else {
                break;
            }
        }

        currentBeadColor = brokenNecklace[numBeads-1];
        for(i = numBeads-2; i >= 0; --i) {
            if(brokenNecklace[i] == currentBeadColor || brokenNecklace[i] == 'w' || currentBeadColor == 'w') {
                ++numCollectedBeads;
                if(currentBeadColor == 'w') {
                    currentBeadColor = brokenNecklace[i];
                }
            } else {
                break;
            }
        }

        if(numCollectedBeads > prevNumCollectedBeads) {
            prevNumCollectedBeads = numCollectedBeads;
        }
    }

    if(prevNumCollectedBeads > numBeads) {
        prevNumCollectedBeads = numBeads;
    }

    fout << prevNumCollectedBeads << endl;

    return 0;
}
