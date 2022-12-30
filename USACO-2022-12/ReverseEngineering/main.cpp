#include <iostream>

using namespace std;
using ll = long long;

bool detectDiscrepancies(char **inputArrays, const char *outputs, ll n, ll m) {
    if (n <= 0) return true;

    ll x = m;
    while(--x > 0 && inputArrays[x][0] == inputArrays[0][0]);
    bool currentCheckingAllSame = x == 0;

    char whereDiscrepancyFound{};
    char typicalOutput[2]{};

    // Only one input ('0' or '1') could have discrepancies in the output
    for (ll i = 0; i < m; i++) {     // Loop through each line
        if (typicalOutput[inputArrays[i][0] - '0'] == 0) {   // If the typical output for the current input is uninitialized:
            typicalOutput[inputArrays[i][0] - '0'] = outputs[i];    // Initialize the typical output
        } else {    // If we already know the typical output for the current input:
            if (outputs[i] != typicalOutput[inputArrays[i][0] - '0']) {    // If the current output is not the typical output:
                if (currentCheckingAllSame) {
                    return false;
                }
                if (whereDiscrepancyFound == 0) {    // If we have not found a discrepancy before:
                    whereDiscrepancyFound = inputArrays[i][0];      // Record which input has discrepancies
                } else {    // If we have found a discrepancy before:
                    if (whereDiscrepancyFound != inputArrays[i][0]) {    // If where the discrepancy was found is different from where the current discrepancy is:
                        return false;   // Must be a lie
                    }
                }
            }
        }
    }

    char **trimmedInputArrays = new char *[m];    // Trim the first character off each input array to pass recursively
    for (ll i = 0; i < m; i++) {
        trimmedInputArrays[i] = new char[n - 1];
        for (ll j = 0; j < n - 1; j++) {
            trimmedInputArrays[i][j] = inputArrays[i][j + 1];
        }
    }

    bool result = detectDiscrepancies(trimmedInputArrays, outputs, n - 1, m);

    for (ll i = 0; i < m; i++) {
        delete[] trimmedInputArrays[i];
    }
    delete[] trimmedInputArrays;

    return result;
}

int main() {
    ll t;
    cin >> t;

    bool *responses = new bool[t];

    for (ll i = 0; i < t; i++) {
        ll n;
        cin >> n;
        ll m;
        cin >> m;

        char **inputArrays = new char *[m];
        char *outputs = new char[m];

        for (ll j = 0; j < m; j++) {
            inputArrays[j] = new char[n];
            for (ll k = 0; k < n; k++) {
                cin >> inputArrays[j][k];
            }
            cin >> outputs[j];
        }

//        for (ll j = 0; j < m; j++) {
//            printf("%s %c\n", inputArrays[j], outputs[j]);
//        }

        responses[i] = detectDiscrepancies(inputArrays, outputs, n, m);

        for (ll j = 0; j < m; j++) {
            delete[] inputArrays[j];
        }
        delete[] inputArrays;
        delete[] outputs;
    }

    for (ll i = 0; i < t; i++) {
        printf("%s\n", responses[i] ? "OK" : "LIE");
    }

    delete[] responses;
    return 0;
}
