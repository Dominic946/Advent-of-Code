#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

string* splitBag(string in){
  string* bag = new string[2];
  int len = in.size();
  int i = 0;
  string temp = "";

  for(i = 0; i < len/2; i++){
    temp += in.at(i);
  }

  bag[0] = temp;
  temp = "";
  for(i = len/2; i < len; i++){
    temp += in.at(i);
  }
  bag[1] = temp;
  return bag;
}

char findCommon(string first, string second){
  int len = first.size();
  for(int i = 0; i < len; i++){
    if(second.find(first.at(i)) != string::npos){
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
  string* bags;
  char common;
  int total = 0;

  while(getline (fp, input)) {
    bags = splitBag(input);
    //printf("first bag: %s, second bag: %s\n", bags[0].c_str(), bags[1].c_str());
    common = findCommon(bags[0], bags[1]);
    //printf("common letter: %c\n", common);
    total += letterScore(common);
    //printf("score: %d\n", letterScore(common));
  }

  printf("total: %d\n", total);
  fp.close();
}
