#include <fstream>
#include "../utils/utils.cc"

ifstream fp("Inputs/Day7.txt");
string input;

int main(){
  ifstream fp("Inputs/Day7.txt");
  string input;

  while(getline (fp, input)) {
    vector<string> tokens = split(input, ' ');
    printVector(tokens);
  }

  fp.close();
}
