#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    const char word[] = "ninetee";
    string s;
    cin >> s;
    int i;
    int index;
    int numFound = 0;
    while(true) {
        for(i = 0; i < 7; ++i) {
            index = s.find(word[i]);
            if(index == string::npos) {
                if(i == 0) {
                    --numFound;
                }
                goto exit;
            }
            s.erase(index, 1);
        }
        ++numFound;
    }
    exit:
    if(numFound == -1) {
        numFound = 0;
    }
    cout << numFound << endl;
    return 0;
}
