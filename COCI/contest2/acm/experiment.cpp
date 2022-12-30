#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  int16_t arr[6] = {1, 4, 3, 7, 5, 6};
  sort(arr+1, arr+3);
  for(int16_t aaa : arr) {
    cout << aaa << endl;
  }
}
