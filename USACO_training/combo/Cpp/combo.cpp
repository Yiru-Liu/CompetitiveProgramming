/*
ID: yiru.li1
TASK: combo
PROG: combo
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// see if lock can be opened given a testCombination and a correctCombination:
bool canOpenLock(int16_t testCombination[3], int16_t correctCombination[3], int n) {
  bool matchingCombination[3];
  int16_t difference;
  for(int i = 0; i < 3; i++) {
    difference = testCombination[i] - correctCombination[i];
    if(difference <= 2 && difference >= -2) {
      matchingCombination[i] = true;
    } else {
      if(testCombination[i] <= 2 && correctCombination[i] >= (n-1)) {
        difference += n;
      } else if(correctCombination[i] <= 2 && testCombination[i] >= (n-1)) {
        difference -= n;
      }
      if(difference <= 2 && difference >= -2) {
        matchingCombination[i] = true;
      } else {
        matchingCombination[i] = false;
      }
    }
  }
  return matchingCombination[0] && matchingCombination[1] && matchingCombination[2];
}

int main() {
  ofstream fout ("combo.out");
  ifstream fin ("combo.in");

  int16_t n;
  fin >> n;

  int16_t farmerJohnCombination[3];
  for(int i = 0; i < 3; i++) {
    fin >> farmerJohnCombination[i];
  }

  int16_t masterCombination[3];
  for(int i = 0; i < 3; i++) {
    fin >> masterCombination[i];
  }

  int32_t numCombos = 0;
  int16_t combination[3];

  bool canOpenFarmerJohn;
  bool canOpenMaster;

  for(combination[0] = 1; combination[0] <= n; combination[0]++) {
    for(combination[1] = 1; combination[1] <= n; combination[1]++) {
      for(combination[2] = 1; combination[2] <= n; combination[2]++) {
        canOpenFarmerJohn = canOpenLock(combination, farmerJohnCombination, n);
        canOpenMaster = canOpenLock(combination, masterCombination, n);
        if(canOpenFarmerJohn || canOpenMaster) {
          //cout << combination[0] << ", " << combination[1] << ", " << combination[2]
          //     << "  \tcanOpenLock(farmerJohnCombination): " << canOpenFarmerJohn
          //     << "\tcanOpenLock(masterCombination): " << canOpenMaster << endl;
          numCombos++;
        }
      }
    }
  }

  //cout << endl << numCombos << endl;
  fout << numCombos << endl;

  return 0;
}
