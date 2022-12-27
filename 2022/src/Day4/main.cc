#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool fullyContain(int LA, int LB, int RA, int RB){
  if(LA <= RA && LB >= RA){
    return true;
  }
  if(RA <= LA && RB >= LA){
    return true;
  }
  return false;
}

int main(){
  ifstream fp("Inputs/Day4.txt");
  string input;
  string LA;
  string LB;
  string RA;
  string RB;
  int i;
  int total = 0;

  while(getline (fp, input)) {
    i = 0;
    LA = "";
    LB = "";
    RA = "";
    RB = "";
    while(input[i] != '-'){
      LA += input[i];
      i++;
    }
    i++;
    while(input[i] != ','){
      LB += input[i];
      i++;
    }
    i++;
    while(input[i] != '-'){
      RA += input[i];
      i++;
    }
    i++;
    while(input[i] != ','){
      RB += input[i];
      i++;
    }

    if(fullyContain(stoi(LA), stoi(LB), stoi(RA), stoi(RB))){
      total++;
    }
  }

  printf("Total pairs with overlap: %d\n", total);
  fp.close();
}
