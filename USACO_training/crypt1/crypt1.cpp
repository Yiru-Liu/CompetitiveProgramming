/*
ID: yiru.li1
TASK: crypt1
PROG: crypt1
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int16_t num1DigNsToNum(int16_t digNs[], int16_t digs[], int16_t n) {
  return digs[digNs[2]]*100 + digs[digNs[1]]*10 + digs[digNs[0]];
}

int16_t num2DigNsToNum(int16_t digNs[], int16_t digs[], int16_t n) {
  return digs[digNs[1]]*10 + digs[digNs[0]];
}

int16_t howManyDigits(int32_t num) {
  if(num >= 100000) {
    return 6;
  } else if(num >= 10000) {
    return 5;
  } else if(num >= 1000) {
    return 4;
  } else if(num >= 100) {
    return 3;
  } else if(num >= 10) {
    return 2;
  } else {
    return 1;
  }
}

// check if a single-digit number is one of the numbers with which to solve the cryptarithm:
bool checkDigitIsValid(int16_t digitToCheck, int16_t validDigits[], int16_t n) {
  for(int16_t i = 0; i < n; i++) {  // loop through each number of validDigits:
    if(digitToCheck == validDigits[i]) {  // if the digit to check is one of validDigits:
      return true;  // the digit is one of validDigits
    }
  }
  return false; // if not, then it's not one of validDigits
}

// check if all digits of a number are one of the numbers with which to solve the cryptarithm and has the correct number of digits:
bool checkIsValid(int32_t numToCheck, int16_t validDigits[], int16_t n, int16_t numDigitsWanted) {
  int16_t numDigits = howManyDigits(numToCheck);  // number of digits the number has
  if(numDigits != numDigitsWanted) {  // if the number of digits the number has is not the number of digits wanted:
    return false; // number is not valid
  }

  if(!checkDigitIsValid(numToCheck%10, validDigits, n)) { // if the ones digit isn't valid:
    return false; // number is not valid
  }
  if(!checkDigitIsValid((numToCheck/10)%10, validDigits, n)) {  // if the tens digit isn't valid:
    return false; // number is not valid
  }
  if(numDigits >= 3) {  // if the number has a hundreds digit:
    if(!checkDigitIsValid((numToCheck/100)%10, validDigits, n)) {  // if the hundreds digit isn't valid:
      return false; // number is not valid
    }
    if(numDigits >= 4) {  // if the number has a thousands digit:
      if(!checkDigitIsValid((numToCheck/1000)%10, validDigits, n)) {  // if the thousands digit isn't valid:
        return false; // number is not valid
      }
    }
  }

  return true;  // if the function hasn't returned false, then the number is valid.
}

int main() {
  ofstream fout ("crypt1.out"); // output file
  ifstream fin ("crypt1.in");   // input file

  int16_t n;  // number of digits that will be used
  fin >> n;   // get from input file

  int16_t digits[n] = { };    // the digits that will be used to solve the cryptarithm
  for(int16_t i = 0; i < n; i++) {    // get from input file:
      fin >> digits[i];
  }



  int16_t num1DigNs[3]; // the number of the digits of the first number
  int16_t num2DigNs[2]; // the number of the digits of the second number

  int16_t num1; // the actual number value of num1, as calculated by num1DigNsToNum()
  int16_t num2; // the actual number value of num2, as calculated by num2DigNsToNum()

  int32_t product;  // the value of num1 * num2
  int32_t partialProduct1;  // num1 times the first digit of num2
  int32_t partialProduct2;  // num1 times the second digit of num2

  int16_t numSolutions = 0;

  bool isValid; // bool to store the returned value of checkIsValid()

  for(num1DigNs[2] = 0; num1DigNs[2] < n; num1DigNs[2]++) {
    for(num1DigNs[1] = 0; num1DigNs[1] < n; num1DigNs[1]++) {
      for(num1DigNs[0] = 0; num1DigNs[0] < n; num1DigNs[0]++) {
        num1 = num1DigNsToNum(num1DigNs, digits, n);  // calculate actual value of num1
        for(num2DigNs[1] = 0; num2DigNs[1] < n; num2DigNs[1]++) {
          for(num2DigNs[0] = 0; num2DigNs[0] < n; num2DigNs[0]++) {
            num2 = num2DigNsToNum(num2DigNs, digits, n);  // calculate actual value of num2
            product = num1 * num2;  // calculate the product of num1 and num2
            isValid = checkIsValid(product, digits, n, 4);  // check to see if the product if valid
            if(isValid) { // if so, then:
              //cout << "num1 * num2: " << product << "\tproduct is valid: " << isValid << endl;
              partialProduct1 = num1 * (num2%10); // calculate partialProduct1
              isValid = checkIsValid(partialProduct1, digits, n, 3); // check to see if it is valid
              if(isValid) { // if so:
                //cout << "partialProduct1: " << partialProduct1 << "\tpartialProduct1 is valid: " << isValid << endl;
                partialProduct2 = num1 * (num2/10); // calculate partialProduct2
                isValid = checkIsValid(partialProduct2, digits, n, 3);  // check to see if it is valid
                if(isValid) { // if so:
                  //cout << "partialProduct2: " << partialProduct2 << "\tpartialProduct2 is valid: " << isValid << endl;
                  numSolutions++; // add 1 to the number of solutions there are
                }
              }
            }
          }
        }
      }
    }
  }

  cout << endl << numSolutions << endl;
  fout << numSolutions << endl;


  return 0;
}
