/*
ID: yiru.li1
TASK: friday
PROG: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    const int friday13Days[12] = {13, 44, 72, 103, 133, 164, 194, 225, 256, 286, 317, 347}; // first day of the year is day 1

    int daysOfWeek[7] = { };

    int currentMonth;
    int currentYear;
    int dayOfWeek;
    long long yearDays = 0;
    bool isLeapYear;

    long long numYears;
    fin >> numYears;

    for(currentYear = 1900; currentYear < 1900+numYears; ++currentYear) {
        if(currentYear % 4 == 0) {
            if(currentYear % 100 == 0) {
                if(currentYear % 400 == 0) {
                    isLeapYear = true;
                } else {
                    isLeapYear = false;
                }
            } else {
                isLeapYear = true;
            }
        } else {
            isLeapYear = false;
        }
        for(currentMonth = 0; currentMonth < 12; ++currentMonth) {
            dayOfWeek = (friday13Days[currentMonth] + yearDays) % 7;
            if(isLeapYear && currentMonth > 1) {
                ++dayOfWeek;
                dayOfWeek %= 7;
            }
            ++daysOfWeek[dayOfWeek];
        }
        if(isLeapYear) {
            yearDays += 366;
        } else {
            yearDays += 365;
        }
    }


    fout << daysOfWeek[6] << " "
         << daysOfWeek[0] << " "
         << daysOfWeek[1] << " "
         << daysOfWeek[2] << " "
         << daysOfWeek[3] << " "
         << daysOfWeek[4] << " "
         << daysOfWeek[5] << endl;

    return 0;
}
