/*
ID: yiru.li1
TASK: wormhole
PROG: wormhole
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector< std::vector< int16_t > > allWormholePairings;

void generateWormholePairings(std::vector< int16_t > inputPairings, int16_t numWormholes, int start) {
    // is this a complete pairing?
    if(start == numWormholes) {
        allWormholePairings.push_back(inputPairings);   // if so, add to allWormholePairings:
        return;
    }

    for(int i = start+1; i < numWormholes; i++) {
        std::vector< int16_t > passedInputPairings = inputPairings;
        std::swap(passedInputPairings[start+1], passedInputPairings[i]);

        generateWormholePairings(passedInputPairings, numWormholes, start+2);
    }
}

int16_t getPairedWormhole(int16_t onePair, std::vector< int16_t > wormholePairing) {    // given the # of a wormhole, find the wormhole it is paired to
    std::vector< int16_t >::iterator itWormhole = std::find(wormholePairing.begin(), wormholePairing.end(), onePair);
    if(itWormhole == wormholePairing.end()) {
        std::cout << "ERROR: Wormhole not found in wormholePairing. onePair: " << onePair << std::endl;
        return -1;
    }
    int16_t indexOfWormhole = itWormhole - wormholePairing.begin();
    if(indexOfWormhole % 2 == 0) {
        return wormholePairing[indexOfWormhole+1];
    } else {
        return wormholePairing[indexOfWormhole-1];
    }
}

int16_t getWormholeWillWalkInto(int16_t startingWormhole, std::vector< std::pair<int32_t,int32_t> > wormholeCoordinates) {
    std::pair<int16_t, std::pair<int32_t,int32_t> > wormholeWillWalkInto = std::make_pair(-1, std::make_pair(INT32_MAX, INT32_MAX));
    for(int i = 0; i < wormholeCoordinates.size(); i++) {
        if((wormholeCoordinates[i].second == wormholeCoordinates[startingWormhole].second) && (wormholeCoordinates[i].first > wormholeCoordinates[startingWormhole].first) && (wormholeCoordinates[i].first < wormholeWillWalkInto.second.first)) {
            wormholeWillWalkInto = std::make_pair(i, wormholeCoordinates[i]);
        }
    }
    return wormholeWillWalkInto.first;
}

bool canGetStuck(int16_t startingWormhole, std::vector< int16_t > wormholePairing, std::vector< std::pair<int32_t,int32_t> > wormholeCoordinates) {
    int16_t wormholeWillWalkInto;
    int16_t pairedWormhole = startingWormhole;

    do {
        wormholeWillWalkInto = getWormholeWillWalkInto(pairedWormhole, wormholeCoordinates);
        if (wormholeWillWalkInto == -1) { // if won't walk into another wormhole:
            return false;
        }
        pairedWormhole = getPairedWormhole(wormholeWillWalkInto, wormholePairing);
    } while(pairedWormhole != startingWormhole);
    return true;
}

int main() {
    std::ofstream fout ("wormhole.out");
    std::ifstream fin ("wormhole.in");

    int16_t numWormholes;
    fin >> numWormholes;

    std::vector< int16_t > startInputPairings;
    startInputPairings.reserve(numWormholes);
    for(int i = 0; i < numWormholes; i++) {
        startInputPairings.push_back(i);
    }

    /// -----DEBUG-----:
    for(auto aaa : startInputPairings) {
        std::cout << aaa << ", ";
    }
    std::cout << std::endl << std::endl;
    /// ----------------

    generateWormholePairings(startInputPairings, numWormholes, 0);

    /// -----DEBUG-----:
    for(auto bbb : allWormholePairings) {
        for(auto ccc : bbb) {
            std::cout << ccc << ", ";
        }
        std::cout << std::endl;
    }
    /// ----------------

    std::vector< std::pair<int32_t,int32_t> > wormholeCoordinates(numWormholes);
    for(int i = 0; i < numWormholes; i++) {
        fin >> wormholeCoordinates[i].first;
        fin >> wormholeCoordinates[i].second;
    }

    /// -----DEBUG-----:
    std::cout << std::endl << std::endl;
    for(auto ddd : wormholeCoordinates) {
        std::cout << ddd.first << '\t' << ddd.second << std::endl;
    }
    /// ----------------

    int64_t numPairingsCanGetStuck = 0;
    for(uint64_t i = 0; i < allWormholePairings.size(); i++) {
        for(int j = 0; j < numWormholes; j++) {
            if(canGetStuck(j, allWormholePairings[i], wormholeCoordinates)) {
                numPairingsCanGetStuck++;
                break;
            }
        }
    }

    /// -----DEBUG-----:
    std::cout << std::endl << std::endl << numPairingsCanGetStuck << std::endl;
    /// ----------------

    fout << numPairingsCanGetStuck << std::endl;

    return 0;
}
