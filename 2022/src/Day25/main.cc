#include <fstream>
#include "../utils/utils.cc"
#define lld long long int

// Works in theory, but has really long runtime.

lld toDecimal(string s){
  lld total = 0;
  int p = 0;
  for(int i = s.size() - 1; i >= 0; i--){
    switch(s.at(i)){
      case '0':
        break;
      case '1':
        total += pow(5,p);
        break;
      case '2':
        total += 2 * pow(5,p);
        break;
      case '-':
        total -= pow(5,p);
        break;
      case '=':
        total -= 2 * pow(5,p);
        break;
    }
    p++;
  }
  return total;
}

string addOne(string s){

  if(s.size() == 0){
    return "1";
  }
  string head;
  if(s.size() == 1){
    head = "";
  } else {
    head = s.substr(0, s.size()-1);
  }
  char last = s.at(s.size() - 1);

  switch(last){
    case '0':
      return head + '1';
    case '1':
      return head + '2';
    case '2':
      return addOne(head) + '=';
    case '=':
      return head + '-';
    case '-':
      return head + '0';
  }
  return s;
}

string toSnafu(lld n){
  string result = "0";
  for(lld i = 0; i < n; i++){
    result = addOne(result);
  }
  return result;
}

int main(){
  ifstream fp("Inputs/Day25.txt");
  string input;
  lld total = 0;

  while(getline (fp, input)) {
    lld dec = toDecimal(input);
    cout << input << " ~~ "<< dec << endl;
    total += dec;
    //cout << " ~~ " << toSnafu(dec) << endl;
  }

  fp.close();
  printf("Part 1 number: %lld\n", total);
  printf("Part 1 answer: %s\n", toSnafu(total).c_str());
}
