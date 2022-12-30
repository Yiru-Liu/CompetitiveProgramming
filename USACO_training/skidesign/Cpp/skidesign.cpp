/*
ID: yiru.li1
TASK: skidesign
PROG: skidesign
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int32_t minInArray(int32_t arr[], int32_t arrLength) {
  int32_t smallest = arr[0];
  for(int i = 1; i < arrLength; i++) {
    if(arr[i] < smallest) {
      smallest = arr[i];
    }
  }
  return smallest;
}

int32_t maxInArray(int32_t arr[], int32_t arrLength) {
  int32_t largest = arr[0];
  for(int i = 1; i < arrLength; i++) {
    if(arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

void printArrayNicely(int32_t arr[], int32_t arrLength) {
  cout << "[";
  for(int i = 0; i < arrLength-1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[arrLength-1] << "]" << endl;
}

int32_t constrain(int32_t val, int32_t min, int32_t max) {
  return (val>max) ? (max) : ((val<min) ? min : val);
}

int main() {
  ofstream fout ("skidesign.out");
  ifstream fin ("skidesign.in");

  int32_t n;
  fin >> n;

  int32_t hillHeights[n];

  for(int i = 0; i < n; i++) {
    fin >> hillHeights[i];
  }

  int32_t lowestHill = minInArray(hillHeights, n);
  int32_t highestHill = maxInArray(hillHeights, n);

  int32_t costs[highestHill-lowestHill+1] = { };
  int32_t constrainedHillHeights[n];

  int32_t heightDifference;
  int32_t testHeight;

  for(int32_t i = 0; i <= highestHill-lowestHill; i++) {
    testHeight = lowestHill + i;
    //cout << "testHeight: " << testHeight << endl;
    for(int32_t j = 0; j < n; j++) {
      constrainedHillHeights[j] = constrain(hillHeights[j], testHeight, testHeight+17);
      heightDifference = hillHeights[j] - constrainedHillHeights[j];
      //cout << "heightDifference: " << heightDifference << endl;
      costs[i] += heightDifference * heightDifference;
      //cout << "costs: " << costs[i] << endl;
    }
  }

  //cout << minInArray(costs, highestHill-lowestHill+1);
  fout << minInArray(costs, highestHill-lowestHill+1) << endl;
  return 0;
}
