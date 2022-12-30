#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

//#define cin fin

int16_t statusToPenaltyTime(string status) {
  size_t slashIndex = status.find('/');
  if(slashIndex == string::npos) {
    return 0;
  }
  cout << status.substr(slashIndex+1, 2) << endl;
  int16_t hour = stoi(status.substr(slashIndex+1, 2), nullptr, 10);
  int16_t minutes = stoi(status.substr(slashIndex+4, 2), nullptr, 10);
  int16_t seconds = stoi(status.substr(slashIndex+7, 2), nullptr, 10);
  int16_t numWrongSubmittions = stoi(status.substr(slashIndex-1, 1), nullptr, 10) - 1;
  return hour*3600 + minutes*60 + seconds + numWrongSubmittions*1200;
}

bool wayToSortAscendingByNumberOfCorrectSolutions(tuple <string, int16_t, int16_t> team1, tuple <string, int16_t, int16_t> team2) {
  return (get<1>(team1) > get<1>(team2));
}

int16_t findInArray(string arr[], int16_t arrLength, string toFind) {
  for(int i = 0; i < arrLength; i++) {
    if(toFind == arr[i]) {
      return i;
    }
  }
  return -1;
}

int16_t findInTupleArray(tuple <string, int16_t, int16_t> arr[], int16_t arrLength, string toFind) {
  for(int i = 0; i < arrLength; i++) {
    if(toFind == (get<0>(arr[i]))) {
      return i;
    }
  }
  return -1;
}

void printArrayNicely(int32_t arr[], int16_t arrLength) {
  cout << "[";
  for(int i = 0; i < arrLength-1; i++) {
    cout << arr[i] << ", ";
  }
  cout << arr[arrLength-1] << "]" << endl;
}

int main() {
  /*ofstream fout ("acm.out");
  ifstream fin ("acm.in");*/

  int16_t n;  // number of teams
  cin >> n;

  int16_t m;  // number of problems
  cin >> m;

  string teamNames[n];  // the team names
  string teamStatus[n][m];  // the status of each team
  for(int i = 0; i < n; i++) {  // get from input file:
    cin >> teamNames[i];
    for(int j = 0; j < m; j++) {
      cin >> teamStatus[i][j];
    }
  }

  string ourTeamName; // our team name
  cin >> ourTeamName; // get from input file
  string ourTeamStatus[m];  // the final status of our team
  for(int i = 0; i < m; i++) {  // get from input file:
    cin >> ourTeamStatus[i];
  }

  int16_t ourTeamIndex = findInArray(teamNames, n, ourTeamName);  // find the index of our team in the frozen standings
  for(int i = 0; i < m; i++) {  // replace the status of our team with the final status:
    teamStatus[ourTeamIndex][i] = ourTeamStatus[i];
  }

  int16_t teamProblemsCorrect[n] = { }; // the number of correct solutions of each team

  for(int i = 0; i < n; i++) {  // calculate teamProblemsCorrect:
    for(int j = 0; j < m; j++) {
      teamProblemsCorrect[i] += (teamStatus[i][j].at(0) != '-');  // if the team didn't get the problem wrong, assume they got it right
    }
  }

  int16_t teamPenaltyTimes[n];
  int16_t teamPenaltyTime;
  for(int i = 0; i < n; i++) {
    teamPenaltyTime = 0;
    for(int j = 0; j < m; j++) {
      teamPenaltyTime += statusToPenaltyTime(teamStatus[i][j]);
    }
    teamPenaltyTimes[i] = teamPenaltyTime;
  }

  tuple <string, int16_t, int16_t> teamsSortedByScore[n]; // the teams sorted by the number of correct solutions
  for(int i = 0; i < n; i++) {  // make the array of tuples:
    teamsSortedByScore[i] = make_tuple(teamNames[i], teamProblemsCorrect[i], teamPenaltyTimes[i]);
  }
  sort(teamsSortedByScore, teamsSortedByScore+n, wayToSortAscendingByNumberOfCorrectSolutions); // sort the array

  int16_t currentOurTeamIndex = findInTupleArray(teamsSortedByScore, n, ourTeamName);  // find the current index of the team (after sorting)
/*  if((get<1>(teamsSortedByScore[currentOurTeamIndex]) == get<1>(teamsSortedByScore[currentOurTeamIndex+1])) || (get<1>(teamsSortedByScore[currentOurTeamIndex]) == get<1>(teamsSortedByScore[currentOurTeamIndex-1]))) {  // see if there are other teams with the same score:

} else {*/
    cout << currentOurTeamIndex << endl;
  //}
  return 0;
}
