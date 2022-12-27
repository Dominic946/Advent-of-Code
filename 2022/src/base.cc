#include <fstream>
#include "../utils/utils.cc"

int main(){
  ifstream fp("Inputs/Day1.txt");
  string input;

  while(getline (fp, input)) {
    cout << input << endl;
  }

  fp.close();
}
