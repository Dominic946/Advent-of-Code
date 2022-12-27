#include <fstream>
#include "../utils/utils.cc"

//number of rounds, 20 for part 1, 10000 for part 2
#define NUM_ROUNDS 10000

 //#################################################
 //# FOR INPUT, FUND ALL ", " AND REPLACE WITH "," #
 //#################################################

vector< vector<unsigned long int> > held (9);
vector<char> op;
vector<string> amt;
vector<string> temp;
vector<int> divs;
vector<int> tru;
vector<int> fals;
vector<unsigned int> inspects;
int m = 0;
int lcm = 1;

void round(){
  for(int i = 0; i < m; i++){
    while(held.at(i).size() > 0){
      inspects.at(i) ++;

      switch (op.at(i)){
        case '*':
          if(amt.at(i) == "old"){
            held.at(i).at(0) *= held.at(i).at(0);
          } else {
            held.at(i).at(0) *= stoi(amt.at(i));
          }
          break;

        case '+':
          if(amt.at(i) == "old"){
            held.at(i).at(0) += held.at(i).at(0);
          } else {
            held.at(i).at(0) += stoi(amt.at(i));
          }
          break;
      }

      if(NUM_ROUNDS == 20){
         held.at(i).at(0) /= 3;
      } else {
         held.at(i).at(0) %= lcm;
      }

      if(held.at(i).at(0) % divs.at(i) == 0){
        held.at(tru.at(i)).push_back(held.at(i).at(0));
      } else {
        held.at(fals.at(i)).push_back(held.at(i).at(0));
      }
      held.at(i).erase(held.at(i).begin());

    }
  }
}


int main(){
  ifstream fp("Inputs/Day11.txt");
  string input;
  bool more = true;


  while(more) {
    for(int i = 0; i < 7; i++){
      if (!getline (fp, input)){
        more = false;
        break;
      }
      switch (i){
        case 1:
          temp = split(input, ' ');
          temp = split(temp.at(4), ',');
          for(int j = 0; j < temp.size(); j++){
            held.at(m).push_back(stoi(temp.at(j)));
          }
          inspects.push_back(0);
          break;

        case 2:
          temp = split(input, ' ');
          op.push_back(temp.at(6)[0]);
          amt.push_back(temp.at(7));
          break;

        case 3:
          temp = split(input, ' ');
          divs.push_back(stoi(temp.at(5)));
          break;

        case 4:
          temp = split(input, ' ');
          tru.push_back(stoi(temp.at(9)));
          break;

        case 5:
          temp = split(input, ' ');
          fals.push_back(stoi(temp.at(9)));
          break;
      }
    }
    m++;
  }

  fp.close();
  /*
  cout << m << endl;
  printVector(op);
  printVector(amt);
  printVector(divs);
  printVector(tru);
  printVector(fals);
  */

  for(int i = 0; i < m; i++){
    lcm *= divs.at(i);
  }

  for(int i = 0; i < NUM_ROUNDS; i++){
    round();
  }

  printVector(inspects);

  sort(inspects.begin(), inspects.end());

  printf("Answer: %lu\n", (unsigned long int) inspects.at(m-1) * inspects.at(m-2));
}
