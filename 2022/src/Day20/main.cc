#include <fstream>
#include "../utils/utils.cc"

vector< pair<int, int> > nums;
int size;

void move(int pos){
  pair<int, int> temp = nums.at(pos);
  nums.erase (nums.begin()+pos);
  int idx = pos+temp.second;
  while(idx < 0 || idx >= size){
    if(idx < 0){
      idx += size;
      idx --;
    }
    if(idx >= size){
      idx -= size;
      idx ++;
    }
  }

  if(idx == 0){
    nums.push_back(temp);
  } else {
    nums.insert(nums.begin()+idx, temp);
  }
}

int main(){
  ifstream fp("Inputs/Day20.txt");
  string input;
  size = 0;

  while(getline (fp, input)) {
    nums.push_back(make_pair(size++, stoi(input)));
  }
  //printPairVector(nums);
  fp.close();
  // <priority, value>

  for(int i = 0; i < size; i++){
    for(int j = 0; j < nums.size(); j++){
      if(nums.at(j).first == i){
        move(j);
        //printPairVector(nums);
        break;
      }
    }
  }

  int zero;
  for(zero = 0; zero < size; zero++){
    if(nums.at(zero).second == 0){
      break;
    }
  }

  int ans = 0;
  for(int i = 0; i < 3; i++){
    zero += 1000;
    while(zero < 0 || zero >= size){
      if(zero < 0){
        zero += size;
      }
      if(zero >= size){
        zero -= size;
      }
    }
    ans += nums.at(zero).second;
  }

  printf("Part 1: %d\n", ans);

  //printPairVector(nums);

}
