#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string input;

bool match(int start, int end){
  for(int i = start; i < end-1; i++){
    for(int j = i+1; j < end; j++){
      if(input.at(i) == input.at(j)){
        return true;
      }
    }
  }
  return false;
}

int main(){
  ifstream fp("Inputs/Day6.txt");
  getline (fp, input);
  fp.close();

  int i = 4;
  while (match(i-4, i)){
    i++;
  }
  printf("answer 1: %d\n", i);

  if(i < 14){
    i=14;
  }
  while (match(i-14, i)){
    i++;
  }
  printf("answer 2: %d\n", i);

}
