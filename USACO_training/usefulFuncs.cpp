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

template<typename T>
void printArrayNicely(T arr[], int32_t arrLength) {
  cout << "[";
  for(int i = 0; i < arrLength-1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[arrLength-1] << "]" << endl;
}

int32_t constrain(int32_t val, int32_t min, int32_t max) {
  return (val>max) ? (max) : ((val<min) ? min : val);
}

int16_t howManyDigits(int64_t num) {
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
    (x < 1000000000000000000 ? 18 : 19))))))))))))))))))
}
