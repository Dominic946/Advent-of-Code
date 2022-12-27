#include <fstream>
#include "../utils/utils.cc"

vector< pair<int, int> > nums;
int size;
int key;
// 1,3,-2

void move(int pos){
  pair<int, int> temp = nums.at(pos);
  nums.erase (nums.begin()+pos);
  int idx = pos+(temp.second * key);
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
  printPairVector(nums);
  fp.close();

  key = 811589153 % size;
  cout << key << endl;

  // <priority, value>

  for(int reps = 0; reps < 10; reps++){
    for(int i = 0; i < size; i++){
      for(int j = 0; j < nums.size(); j++){
        if(nums.at(j).first == i){
          move(j);
          break;
        }
      }
    }
    printf("completed rep %d\n", reps + 1);
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
    printf("adding %d\n", nums.at(zero).second);
    ans += nums.at(zero).second;
  }
  printf("ans: %d\n", ans);
  printf("Part 2: %d\n", ans * 811589153);

  //printPairVector(nums);

  // not right -1108365991
  // too high 11681202679129

}
