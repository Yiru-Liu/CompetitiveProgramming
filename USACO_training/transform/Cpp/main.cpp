/*
ID: yiru.li1
TASK: transform
PROG: transform
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int coordinatesToArrayNum(int x, int y, int n) {
    return y*n+x;
}

string rotate90(int n, int numTiles, char beforeSquare[]) {
    char testSquare[numTiles];
    for(int i = n-1; i >= 0; --i) {
    cout << i << endl;
        for(int j = 0; j < n; ++j) {
            cout << j << endl;
            testSquare[coordinatesToArrayNum(i, j, n)] = beforeSquare[coordinatesToArrayNum(j, i, n)];
        }
    }
    return testSquare;
}

int main() {
    ofstream fout ("transform.out"); // output file
    ifstream fin ("transform.in");   // input file

    int i; // variable for use in loops

    int n;      // N, the size of the square
    fin >> n;   // Get N from the input file

    const int numTiles = n*n; // the total amount of tiles in the square

    string beforeSquare; // square before transformation

    // Get beforeSquare from the input file:
    for(i = 0; i < numTiles; ++i) {
        fin >> beforeSquare[i];
    }

    char afterSquare[numTiles]; // square after transformation

    // Get afterSquare from the input file:
    for(i = 0; i < numTiles; ++i) {
        fin >> afterSquare[i];
    }

    string testSquare; // square we'll use to try different tranformations of beforeSquare

    testSquare = rotate90(n, numTiles, beforeSquare);
/*
    for(int k = 0; k < numTiles; ++k) {
        cout << testSquare[k];
    }

    return 0;*/
}
