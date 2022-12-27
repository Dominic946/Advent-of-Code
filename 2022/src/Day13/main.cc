#include <fstream>
#include "../utils/utils.cc"

// 5372 is too low

bool compare(string left, string right){
  int lptr = 0;
  int rptr = 0;
  int ldep = 0;
  int rdep = 0;
    //while(left.at(lptr) != ']' && right.at(rptr) != ']'){

  while (lptr < left.length() && rptr < right.length()){
    while(left.at(lptr) == '['){
      ldep++;
      lptr++;
    }
    while(right.at(rptr) == '['){
      rdep++;
      rptr++;
    }
    while(left.at(lptr) == ']'){
      ldep--;
      lptr++;
      if(ldep == 0){
        break;
      }
    }
    while(right.at(rptr) == ']'){
      rdep--;
      rptr++;
      if(rdep == 0){
        break;
      }
    }
    if(ldep == 0 && rdep > 0){
      return true;
    }
    if(rdep == 0 && ldep > 0){
      return false;
    }

    if(ldep == 0 && rdep == 0){
      return lptr < rptr;
    }

    if(left.at(lptr) == ','){
      lptr++;
      continue;
    }
    if(right.at(rptr) == ','){
      rptr++;
      continue;
    }

    if((int)left.at(lptr) < (int)right.at(rptr)){
      return true;
    }
    if((int)left.at(lptr) > (int)right.at(rptr)){
      return false;
    }
    lptr++;
    rptr++;

  }
  return true;
}


int main(){
  ifstream fp("Inputs/Day13.txt");
  string line1;
  string line2;
  string blank;
  int i = 0;
  int ans = 0;
  bool comp;

  while(getline (fp, line1)) {
    getline (fp, line2);
    getline(fp, blank);
    i++;

    comp = compare(line1, line2);
    ans += comp? i:0;
    comp? printf("Pair %d is good\n", i):0;
  }
  fp.close();

  printf("Part 1 answer: %d\n", ans);
}
