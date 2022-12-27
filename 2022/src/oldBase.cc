#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
  ifstream fp("Inputs/sample.txt");
  string input;

  while(getline (fp, input)) {
    cout << input;
  }

  fp.close();
}
