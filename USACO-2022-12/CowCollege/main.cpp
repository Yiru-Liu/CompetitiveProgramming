#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll numCows;
    cin >> numCows;

    ll *cows = new ll[numCows];
    for (ll i = 0; i < numCows; i++) {
        cin >> cows[i];
    }

    sort(cows, cows + numCows);

    ll maxTuition{};
    ll maxCharge{};
    ll currentAmount;

    for (ll i = 0; i < numCows; i++) {
        currentAmount = (numCows - i) * cows[i];
        if (currentAmount > maxTuition) {
            maxTuition = currentAmount;
            maxCharge = cows[i];
        }
    }

    printf("%lld %lld\n", maxTuition, maxCharge);

    delete[] cows;
    return 0;
}
