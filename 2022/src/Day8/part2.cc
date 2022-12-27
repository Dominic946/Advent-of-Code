#include <fstream>
#include "../utils/utils.cc"

ifstream fp("Inputs/Day8.txt");
string input;
vector< vector<int> > data;

int score(int y, int x){
  int score = 1;
  int amt = 0;
  int height = data.at(y).at(x);
  int k;

  for(k = x-1; k >= 0; k--){
    amt++;
    if(data.at(y).at(k) >= height){
      break;
    }
  }
  score *= amt;
  amt = 0;
  for(k = x+1; k < data.at(0).size(); k++){
    amt++;
    if(data.at(y).at(k) >= height){
      break;
    }
  }
  score *= amt;
  amt = 0;
  for(k = y-1; k >= 0; k--){
    amt++;
    if(data.at(k).at(x) >= height){
      break;
    }
  }
  score *= amt;
  amt = 0;
  for(k = y+1; k < data.size(); k++){
    amt++;
    if(data.at(k).at(x) >= height){
      break;
    }
  }
  score *= amt;
  return score;
}

int main(){
  ifstream fp("Inputs/Day8.txt");
  string input;
  vector<string> row;
  int i = 0;

  while(getline (fp, input)){

    row = split(input);
    data.push_back(vectorStoi(row));
    i++;
  }

  int max = 0;
  int maybe;

  for(i = 0; i < data.size(); i++){
    for(int j = 0; j < data.at(0).size(); j++){
      maybe = score(i, j);
      max = (maybe > max)? maybe:max;
    }
  }

  printf("Max score: %d\n", max);

  fp.close();
}
