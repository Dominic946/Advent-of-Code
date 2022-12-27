#include <fstream>
#include "../utils/utils.cc"
#include "elf.h"

vector<elf*> elves;
int minX;
int maxX;
int minY;
int maxY;

bool occupied(int x, int y){
  for(int i = 0; i < elves.size(); i++){
    if((elves.at(i)->x == x) && (elves.at(i)-> y == y)){
      return true;
    }
  }
  return false;
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
  this->x = this->Px;
  this->y = this->Py;
}

elf::elf(int x_, int y_, int idx_){
  this->x = x_;
  this->Px = x_;
  this->y = y_;
  this->Py = y_;
  this->idx = idx_;
  this->nextDir = 'N';
}

void elf::print(){
  printf("elf at (%d, %d)\n", this->x, this->y);
}

void elf::move(){
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
      return;
    default:
      printf("ERROR direction is not one of N, S, E, W, -\n");
      break;
  }

  for(int i = 0; i < elves.size(); i++){
    if((i != this->idx) && (this->x == elves.at(i)->x) && (this->y == elves.at(i)->y)){
      elves.at(i)->goBack();
      this->goBack();
      return;
    }
  }
}

void elf::consider(string order){
  assert(order.length() == 4);
  if(!(occupied(this->x, this->y-1) || occupied(this->x-1, this->y-1) || occupied(this->x+1, this->y-1))){
    if(!(occupied(this->x, this->y+1) || occupied(this->x-1, this->y+1) || occupied(this->x+1, this->y+1))){
      if(!(occupied(this->x+1, this->y) || occupied(this->x-1, this->y))){
        nextDir = '-';
        return;
      }
    }
  }

  for(int i = 0; i < order.length(); i++){
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


//vector<elf*> elves;

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

  vector<string> dirs;
  dirs.push_back("NSWE");
  dirs.push_back("SWEN");
  dirs.push_back("WENS");
  dirs.push_back("ENSW");

  for(int reps = 0; reps < 10; reps++){
    //printf("after rep %d:\n", reps);
    //setBounds();
    //printBoard();
    for(int i = 0; i < elves.size(); i++){
      elves.at(i)->consider(dirs.at(reps%4));
    }
    for(int i = 0; i < elves.size(); i++){
      elves.at(i)->move();
    }
  }

  setBounds();
  cout << "Final ";
  printf("bounds:\n  %d ≤ x ≤ %d\n  %d ≤ y ≤ %d\n", minX, maxX, minY, maxY);

  printBoard();

  printf("Total elves: %lu\n", elves.size());

  printf("Part 1 answer: %lu\n", (maxX-minX+1) * (maxY-minY+1) - elves.size());

  for(int i = 0; i < elves.size(); i++){
    delete elves.at(i);
  }
}
