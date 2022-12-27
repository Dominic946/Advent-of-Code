#include <fstream>
#include "../utils/utils.cc"
#define lld long long int
// FOR INPUT:
// Find all ": ", replace with ":"

// THIS WILL WORK IN THEORY, BUT RUNTIME IS WAY TOO LONG

vector<string> names;
vector<string> ops;

lld calculate(string monkey){
  bool good = false;
  int idx;
  for(idx = 0; idx < names.size(); idx++){
    if(names.at(idx) == monkey){
      good = true;
      break;
    }
  }
  if(!good){
    printf("ERROR: couldn't find monkey name %s\n", monkey.c_str());
    return -1;
  }
  vector<string> op = split(ops.at(idx), ' ');
  if(op.size() == 1){
    return stoi(op.at(0));
  } else {
    switch(op.at(1).at(0)){
      case '+':
        return calculate(op.at(0)) + calculate(op.at(2));
        break;
      case '-':
        return calculate(op.at(0)) - calculate(op.at(2));
        break;
      case '*':
        return calculate(op.at(0)) * calculate(op.at(2));
        break;
      case '/':
        return calculate(op.at(0)) / calculate(op.at(2));
        break;
      default:
        printf("ERROR: operation %s is not valid\n", op.at(1).c_str());
        return -1;
    }
  }
}

int main(){
  ifstream fp("Inputs/Day21.txt");

  string input;

  while(getline (fp, input)) {
    names.push_back(split(input, ':').at(0));
    ops.push_back(split(input, ':').at(1));
  }
  int hum = 0;
  for(hum = 0; hum < names.size(); hum++){
    if(names.at(hum) == "humn"){
      break;
    }
  }
  lld yell = 1;
  while(calculate("qntq") != 8226036122233){
  //while(calculate("pppw") != calculate("sjmn")){
    ops.at(hum) = to_string(yell);
    if(yell%10 == 0){
      printf("trying yell %lld\n", yell);
      printf("qntq: %lld\nqgth: %lld\n", calculate("qntq"), calculate("qgth"));
    }
    yell++;
  }
  yell--;

  printf("Part 2 answer: %lld\n", yell);
  fp.close();
}
