#include <iostream>

using namespace std;

bool checkSorted(int arr[], int arrlength) {
    for(int i = 1; i < arrlength; ++i) {
        if(arr[i-1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int thanosSort(int arr[], int arrlength) {
    if(checkSorted(arr, arrlength)) {
        return arrlength;
    } else {
        int halfArrayLength = arrlength/2;
        int firstHalf[halfArrayLength] = { };
        int secondHalf[halfArrayLength] = { };
        for(int i = 0; i < halfArrayLength; ++i) {
            firstHalf[i] = arr[i];
            secondHalf[i] = arr[i + halfArrayLength];
        }
        int firstLength = thanosSort(firstHalf, halfArrayLength);
        int secondLength = thanosSort(secondHalf, halfArrayLength);
        if(firstLength >= secondLength) {
            return firstLength;
        } else {
            return secondLength;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int integers[n] = { };
    for(int i = 0; i < n; ++i) {
        cin >> integers[i];
    }
    cout << thanosSort(integers, n) << endl;
    return 0;
}
