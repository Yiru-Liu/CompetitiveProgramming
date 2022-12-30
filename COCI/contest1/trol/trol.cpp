#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*int16_t howManyDigits(int64_t x) {
  return (x < 10 ? 1 :
    (x < 100 ? 2 :
    (x < 1000 ? 3 :
    (x < 10000 ? 4 :
    (x < 100000 ? 5 :
    (x < 1000000 ? 6 :
    (x < 10000000 ? 7 :
    (x < 100000000 ? 8 :
    (x < 1000000000 ? 9 :
    (x < 10000000000 ? 10 :
    (x < 100000000000 ? 11 :
    (x < 1000000000000 ? 12 :
    (x < 10000000000000 ? 13 :
    (x < 100000000000000 ? 14 :
    (x < 1000000000000000 ? 15 :
    (x < 10000000000000000 ? 16 :
    (x < 100000000000000000 ? 17 :
    (x < 1000000000000000000 ? 18 : 19))))))))))))))))));
}*/

/*int64_t findSumDigits(int64_t num) {
  int64_t sum = 0;
  for(int64_t i = 1000000000000000000; i >= 1; i /= 10) {
    sum += (num/i)%10;
  }
  if(sum > 9) {
    return findSumDigits(sum);
  }
  return sum;
}*/

int16_t findSumDigits(int64_t num) {
  int16_t sum = num % 9;
  return (sum==0) ? 9 : sum;
}

int main() {
  ofstream fout ("trol.out");
  ifstream fin ("trol.in");

  int16_t q;  // how many queries there are
  fin >> q;   // get from input file

  pair <int64_t,int64_t> queries[q];  // to store the queries
  for(int i = 0; i < q; i++) {  // get from input file:
    fin >> queries[i].first;
    fin >> queries[i].second;
  }

  int64_t sum;
  int16_t sumDigits;
  for(int i = 0; i < q; i++) {  // loop through each query:
    sum = 0;
    for(int64_t j = queries[i].first; j <= queries[i].second; j++) {
      sumDigits = findSumDigits(j);
      if(sumDigits < 9) {
        sum += sumDigits;
      } else if(j+9<queries[i].second) {
        sum += 45;
        j += 8;
      } else {
        sum += 9;
      }
    }
    cout << sum << endl;
    fout << sum << endl;
  }

  return 0;
}
