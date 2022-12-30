/*
ID: yiru.li1
TASK: milk
PROG: milk
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

pair <pair <int16_t,int32_t>, int16_t> findLowestFarmerPrice(pair <int16_t,int32_t> farmers[], int16_t numFarmers) {    // find the farmer with the lowest price (to help with sorting the farmers by price):
    int16_t lastPrice = INT16_MAX;  // the price of the last farmer with the lowest price (to compare with the current farmer)
    int32_t milkAvailible = -1;     // amount of milk availible for that farmer
    int16_t indexOfLeastPriceFarmer = -1;   // the index of the farmer
    for(int16_t i = 0; i < numFarmers; i++) {
        if(farmers[i].first < lastPrice) {
            lastPrice = farmers[i].first;
            milkAvailible = farmers[i].second;
            indexOfLeastPriceFarmer = i;
        }
    }
    return make_pair(make_pair(lastPrice, milkAvailible), indexOfLeastPriceFarmer);
}
/*
void printFarmersNicely(pair <int16_t, int32_t> farmers[], int16_t numFarmers) {
    for(int i = 0; i < numFarmers; i++) {
        cout << farmers[i].first << " " << farmers[i].second << endl;
    }
}
*/
int main() {
    ofstream fout ("milk.out");
    ifstream fin ("milk.in");

    int32_t n;  // amount of milk needed per day
    fin >> n;   // get from input file
    int16_t m;  // number of farmers they're buying from
    fin >> m;   // get from input file


    pair <int16_t,int32_t> sortedFarmers[m];    // farmers sorted by price

    {/// GET FARMERS FROM INPUT FILE AND SORT THE FARMERS:
        pair <int16_t,int32_t> farmers[m];  // the .first is the price (in cents) that each farmer charges; the .second stores the amount of milk each farmer can sell.

        for(int16_t i = 0; i < m; ++i) {    // get p and a from input file:
            fin >> farmers[i].first;
            fin >> farmers[i].second;
        }

        /*printFarmersNicely(farmers, m);*/

        pair <pair <int16_t,int32_t>, int16_t> cheapestFarmer;  //to store the value returned by findLowestFarmerPrice()

        for(int16_t i = 0; i < m; i++) {
            cheapestFarmer = findLowestFarmerPrice(farmers, m); // get the cheapest farmer
            // Set the cheapest farmer to the sortedFarmers:
            sortedFarmers[i].first = cheapestFarmer.first.first;    // the price
            sortedFarmers[i].second = cheapestFarmer.first.second;  // amount of milk availible
            farmers[cheapestFarmer.second].first = INT16_MAX;   // make it so the farmer just added to sortedFarmers could not be chosen again
        }
    }/// -----------------
    /*
    cout << endl;
    printFarmersNicely(sortedFarmers, m);
    */
    int64_t cost = 0;
    int64_t milkNeedToBuy = n;

    for(int i = 0; i < m; i++) { // loop all the farmers:
        if(sortedFarmers[i].second > milkNeedToBuy) {    // if the amount of milk the farmer can provide is more than the milk we still need:
            cost += milkNeedToBuy*sortedFarmers[i].first;    // buy the milk we need to buy
            break; // break out of the loop
        } else {    // if the milk we still need to buy is more than the farmer could provide:
            /// BUY ALL THEIR MILK:
            milkNeedToBuy -= sortedFarmers[i].second;   // we bought all their milk; subtract the milk we bought
            cost += sortedFarmers[i].second*sortedFarmers[i].first; // add the cost
        }
    }
    /*
    cout << endl;
    cout << cost << endl;
    */
    fout << cost << endl;
    return 0;
}
