#include <fstream>
#include "../utils/utils.cc"
vector<int> code;

int main(){
  ifstream fp("Inputs/Day10.txt");
  string input;
  vector<string> temp;

  while(getline (fp, input)) {
    temp = split(input, ' ');
    if(temp.at(0) == "noop"){
      code.push_back(0);
    } else {
      code.push_back(0);
      code.push_back(stoi(temp.at(1)));
    }
  }
  fp.close();

  int x = 1;
  int ptr;
  cout << "#";
  for(int clock = 1; clock <= 240; clock++){
    ptr = (clock - 1) % code.size();

    if(clock % 40 == 0){
      cout << endl;
    }
    if (code.at(ptr) == 0){
    } else {
      x += code.at(ptr);
    }
    if (abs((clock % 40) - x) <= 1){
      cout << "#";
    } else {
      cout << ".";
    }

  }
  cout << endl;

}
