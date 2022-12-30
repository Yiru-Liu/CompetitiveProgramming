/*
ID: yiru.li1
TASK: ariprog
PROG: ariprog
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool sortSequencesFunc(std::pair< int32_t, int32_t > sequence1, std::pair< int32_t, int32_t > sequence2) {
    if(sequence1.second == sequence2.second) {
        return sequence1.first < sequence2.first;
    }
    return sequence1.second < sequence2.second;
}

int main() {
    std::ofstream fout ("ariprog.out");
    std::ifstream fin ("ariprog.in");

    int16_t n;
    fin >> n;
    int16_t m;
    fin >> m;

    std::vector< uint32_t > bisquares;  // vector of all possible bisquares

    for(int p = 0; p <= m; p++) {    // generate bisquares:
        for(int q = p; q <= m; q++) {
            bisquares.push_back(p*p + q*q);
        }
    }

    std::sort(bisquares.begin(), bisquares.end());  // sort the bisquares
    bisquares.resize(std::distance(bisquares.begin(), std::unique(bisquares.begin(), bisquares.end())));    // remove duplicate elements

    /*for(auto aaa : bisquares) {
        std::cout << aaa << std::endl;
    }*/

    //std::cout << std::endl << bisquares.size() << std::endl;

    std::vector< std::pair< int32_t, int32_t > > foundSequences;

    for(int32_t a = 0; a < bisquares.size(); a++) {
        for(int32_t b = 1; b <= (bisquares.back()-bisquares[a])/(n-1); b++) {
            for(int32_t nthTerm = 1; nthTerm < n; nthTerm++) {
                if (!std::binary_search(bisquares.begin(), bisquares.end(), bisquares[a] + nthTerm * b)) {
                    //std::cout << "Not valid: " << bisquares[a] << '\t' << b << '\t' << "Value: " << bisquares[a] + nthTerm * b << std::endl;
                    goto sequenceNotValid;
                }
            }
            foundSequences.emplace_back(bisquares[a], b);
            sequenceNotValid:;
        }
    }

    std::sort(foundSequences.begin(), foundSequences.end(), sortSequencesFunc);

    std::cout << std::endl;
    for(auto sequence : foundSequences) {
        std::cout << sequence.first << '\t' << sequence.second << std::endl;
    }

    if(foundSequences.empty()) {
        fout << "NONE" << std::endl;
    } else {
        for(auto sequence : foundSequences) {
            fout << sequence.first << " " << sequence.second << std::endl;
        }
    }

    return 0;
}
