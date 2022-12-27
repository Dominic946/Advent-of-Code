#include <fstream>
#include "../utils/utils.cc"
#include "elf.h"

// 952 is too low.
// Guessing 953, maybe off-by-one error. Is too low.
// Guessing 955, is too low.
// After half hour of debugging, 957 was answer.

vector<elf*> elves;
int minX;
int maxX;
int minY;
int maxY;
int still;
set< pair<int,int> > positions;


bool occupied(int x, int y){
  return positions.count(make_pair(x, y)) == 1;
}

void setBounds(){
  minX = 0;
  maxX = 0;
  minY = 0;
  maxY = 0;

  for(int i = 0; i < elves.size(); i++){
    minX = min(minX, elves.at(i)->x);
    maxX = max(maxX, elves.at(i)->x);
    minY = min(minY, elves.at(i)->y);
    maxY = max(maxY, elves.at(i)->y);
  }
}

void printBoard(){
  for(int y = minY; y <= maxY; y++){
    for(int x = minX; x <= maxX; x++){
      if(occupied(x, y)){
        cout << "#";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void elf::goBack(){
  positions.erase(make_pair(this->x, this->y));
  this->x = this->Px;
  this->y = this->Py;
  positions.insert(make_pair(this->x, this->y));
}

elf::elf(int x_, int y_, int idx_){
  this->x = x_;
  this->Px = x_;
  this->y = y_;
  this->Py = y_;
  this->idx = idx_;
  this->nextDir = 'N';
  positions.insert(make_pair(this->x, this->y));
}

void elf::print(){
  printf("elf at (%d, %d)\n", this->x, this->y);
}

void elf::move(){
  positions.erase(make_pair(this->x, this->y));
  this->Px = this->x;
  this->Py = this->y;
  switch(this->nextDir){
    case 'N':
      this->y--;
      break;
    case 'S':
      this->y++;
      break;
    case 'E':
      this->x++;
      break;
    case 'W':
      this->x--;
      break;
    case '-':
      still++;
      positions.insert(make_pair(this->x, this->y));
      return;
    default:
      printf("ERROR direction is not one of {N, S, E, W, -}\n");
      break;
  }
  positions.insert(make_pair(this->x, this->y));

  for(int i = 0; i < elves.size(); i++){
    if((i != this->idx) && (this->x == elves.at(i)->x) && (this->y == elves.at(i)->y)){
      elves.at(i)->goBack();
      this->goBack();
      return;
    }
  }
}

void elf::consider(string order){
  //assert(order.length() == 4);
  if(!(occupied(this->x, this->y-1) || occupied(this->x-1, this->y-1) || occupied(this->x+1, this->y-1))){
    if(!(occupied(this->x, this->y+1) || occupied(this->x-1, this->y+1) || occupied(this->x+1, this->y+1))){
      if(!(occupied(this->x+1, this->y) || occupied(this->x-1, this->y))){
        nextDir = '-';
        return;
      }
    }
  }

  for(int i = 0; i < 4; i++){
    switch(order.at(i)){
      case 'N':
        if(!(occupied(this->x, this->y-1) || occupied(this->x-1, this->y-1) || occupied(this->x+1, this->y-1))){
          nextDir = 'N';
          return;
        }
        break;
      case 'S':
        if(!(occupied(this->x, this->y+1) || occupied(this->x-1, this->y+1) || occupied(this->x+1, this->y+1))){
          nextDir = 'S';
          return;
        }
        break;
      case 'E':
        if(!(occupied(this->x+1, this->y) || occupied(this->x+1, this->y-1) || occupied(this->x+1, this->y+1))){
          nextDir = 'E';
          return;
        }
        break;
      case 'W':
        if(!(occupied(this->x-1, this->y) || occupied(this->x-1, this->y-1) || occupied(this->x-1, this->y+1))){
          nextDir = 'W';
          return;
        }
        break;
      default:
        printf("ERROR order.at(%d) is not one of N, S, E, W\n", i);
        break;
    }
  }
  nextDir = '-';
  return;
}


int main(){
  ifstream fp("Inputs/Day23.txt");
  string input;
  int x = 0;
  int y = 0;

  while(getline (fp, input)) {
    for(x = 0; x < input.length(); x++){
      if(input.at(x) == '#'){
        elves.push_back(new elf(x,y,elves.size()));
      }
    }
    y++;
  }
  fp.close();

  setBounds();
  cout << "Initial ";
  printf("bounds:\n  %d ≤ x ≤ %d\n  %d ≤ y ≤ %d\n", minX, maxX, minY, maxY);

  string dirs[4] = {"NSWE", "SWEN", "WENS", "ENSW"};

  int reps = 0;
  still = 0;
  while(still < elves.size()){
    still = 0;
    for(int i = 0; i < elves.size(); i++){
      elves.at(i)->consider(dirs[reps%4]);
    }
    for(int i = 0; i < elves.size(); i++){
      elves.at(i)->move();
    }

    // Part 1 answer
    if(reps == 9){
      setBounds();
      cout << "Part 1 ";
      printf("bounds:\n  %d ≤ x ≤ %d\n  %d ≤ y ≤ %d\n", minX, maxX, minY, maxY);
      //printBoard();
      printf("Total elves: %lu\n", elves.size());
      printf("Part 1 answer: %lu\n\n", (maxX-minX+1) * (maxY-minY+1) - elves.size());
    }

    reps++;
    if(reps%100 == 0){
      printf("rep %d\n", reps);
    }
  }

  setBounds();
  cout << "Final ";
  printf("bounds:\n  %d ≤ x ≤ %d\n  %d ≤ y ≤ %d\n", minX, maxX, minY, maxY);

  //printBoard();

  printf("Part 2 answer: %d\n", reps);

  for(int i = 0; i < elves.size(); i++){
    delete elves.at(i);
  }
}
