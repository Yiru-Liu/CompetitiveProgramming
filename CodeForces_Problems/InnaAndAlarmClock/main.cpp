#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int alarms[n][2];

    int i;
    for(i = 0; i < n; ++i) {
        cin >> alarms[i][1];
        cin >> alarms[i][2];
    }

    int j;
    int distinctX = 0;
    for(i = 1; i < n; ++i) {
        for(j = 0; j < i; ++j) {
            if(alarms[i][1] == alarms[j][1]) {
                goto notDistinctX;
            }
        }
        ++distinctX;
        notDistinctX:;
    }
    return 0;
}
