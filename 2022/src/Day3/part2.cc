#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

char findCommon(string first, string second, string third){
  int len = first.size();
  for(int i = 0; i < len; i++){
    if(second.find(first.at(i)) != string::npos && third.find(first.at(i)) != string::npos){
      return first.at(i);
    }
  }
  return '\0';
}

int letterScore(char letter){
  return alphabet.find(letter) + 1;
}

int main(){
  ifstream fp("Inputs/Day3.txt");
  string input;
  string* bags = new string[3];
  char common;
  int total = 0;

  while(getline (fp, input)) {
    bags[0] = input;
    getline (fp, input);
    bags[1] = input;
    getline (fp, input);
    bags[2] = input;
    common = findCommon(bags[0], bags[1], bags[2]);
    //printf("common letter: %c\n", common);
    total += letterScore(common);
    //printf("score: %d\n", letterScore(common));
  }

  printf("total: %d\n", total);
  fp.close();
}
