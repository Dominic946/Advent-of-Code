#include <fstream>
#include "../utils/utils.cc"
#include <set>
#include <utility>

#define NUM_KNOTS 10

set< pair<int,int> > visited;
vector< pair<string, int> > moves;
vector< pair<int, int> > knots;

pair<int,int> tailFollow(int xDis, int yDis){
  if (abs(xDis) <= 1 && abs(yDis) <= 1){
    return make_pair(0,0);
  }
  int Dx;
  int Dy;
  if (xDis == 0){
    Dx = 0;
  } else {
    Dx = (xDis<0)? 1:-1;
  }
  if (yDis == 0){
    Dy = 0;
  } else {
    Dy = (yDis<0)? 1:-1;
  }

  return make_pair(Dx, Dy);
}

int main(){
  ifstream fp("Inputs/Day9.txt");
  string input;
  vector<string> tokens;
  pair<int, int> temp;

  while(getline (fp, input)) {
    tokens = split(input, ' ');
    moves.push_back(make_pair(tokens.at(0), stoi(tokens.at(1))));
  }
  fp.close();

  for(int i = 0; i < NUM_KNOTS; i++){
    knots.push_back(make_pair(0,0));
  }

  visited.insert(knots.at(NUM_KNOTS-1));

  for(int i = 0; i < moves.size(); i++){

    for(int j = 0; j < moves.at(i).second; j++){
      if(strcmp(moves.at(i).first.c_str(), "U") == 0){
        knots.at(0).second++;
      }
      if(strcmp(moves.at(i).first.c_str(), "D") == 0){
        knots.at(0).second--;
      }
      if(strcmp(moves.at(i).first.c_str(), "L") == 0){
        knots.at(0).first--;
      }
      if(strcmp(moves.at(i).first.c_str(), "R") == 0){
        knots.at(0).first++;
      }
      for(int k = 1; k < NUM_KNOTS; k++){
        temp = tailFollow(knots.at(k).first - knots.at(k-1).first, knots.at(k).second - knots.at(k-1).second);
        knots.at(k).first += temp.first;
        knots.at(k).second += temp.second;
      }
      visited.insert(knots.at(NUM_KNOTS-1));
    }
  }
  printf("ended at (%d, %d)\n", knots.at(0).first, knots.at(0).second);
  printf("tail visited %lu spaces\n", visited.size());
}
