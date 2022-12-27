#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int rules[3][3] = {{3,6,0},{0,3,6},{6,0,3}};
const int rules2[3][3] = {{3,1,2},{1,2,3},{2,3,1}};

int gameScore(char opp, char me){
  //printf("opp: %c, me: %c\n", opp, me);
  int score = 0;
  switch (me) {
    case 'Z': score++;
    case 'Y': score++;
    case 'X': score++;
  }

  int other = 0;
  switch (opp) {
    case 'C': other++;
    case 'B': other++;
    case 'A': other++;
  }

  //printf("Score: %d, Other: %d, Result: %d, Total: %d\n", score, other, rules[other-1][score-1], score + rules[other-1][score-1]);
  return score + rules[other-1][score-1];
}

int correctScore(char opp, char end){
  int result = 0;
  switch (end) {
    case 'Z': result++;
    case 'Y': result++;
    case 'X': break;
  }

  int other = 0;
  switch (opp) {
    case 'C': other++;
    case 'B': other++;
    case 'A': other++;
  }

  return (result*3) + rules2[other-1][result];
}

int main(){
  ifstream fp("Inputs/Day2.txt");
  string input;

  int total1 = 0;
  int total2 = 0;
  while(getline (fp, input)) {
    total1 += gameScore(input[0], input[2]);
    total2 += correctScore(input[0], input[2]);
  }

  printf("round 1: %d\n", total1);
  printf("round 2: %d\n", total2);

  fp.close();
}
