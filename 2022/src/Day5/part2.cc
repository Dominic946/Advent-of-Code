#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;

stack <char> flip[9];
stack <char> crates[9];

void move(int amt, int from, int to){
  stack <char> buf;
  for(int k = 0; k < amt; k++){
    buf.push(crates[from].top());
    crates[from].pop();
  }

  for(int k = 0; k < amt; k++){
    crates[to].push(buf.top());
    buf.pop();
  }
}

void display(){
  for(int i = 0; i < 9; i++){
    cout << crates[i].top();
  }
  cout << endl;
}

int min(int a, int b){
  return (a < b)? a:b;
}

int main(){
  ifstream fp("Inputs/Day5.txt");
  string input;

  // Input first few lines of crates to the 'flip' stacks
  while(getline (fp, input)) {
    if (input == "1   2   3   4   5   6   7   8   9"){
      break;
    }
    for(int i = 1; i < min(35, input.length()); i += 4){
      if(input.at(i) != ' '){
        flip[(i-1)/4].push(input.at(i));
      }
    }
  }

  // Transfer the 'flip' stacks to the 'crates' stacks, to flip them upside down
  for(int i = 0; i < 9; i++){
    while(!flip[i].empty()){
      crates[i].push(flip[i].top());
      flip[i].pop();
    }
  }

  // Skip the empty line
  getline (fp, input);

  // Read the movement instructions
  while(getline (fp, input)) {
    int i = 5;
    int params[3]; // amt, from, to
    string paramStr[3];
    /*
    cout <<"here1\n";
    cout << input << endl;
    printf("current input letter is %c\n", input.at(i));
    cout <<"here2\n";
    */
    while(input.at(i) != ' '){
      paramStr[0] += input.at(i);
      i++;
    }
    params[0] = stoi(paramStr[0]);
    i += 6;
    paramStr[1] += input.at(i);
    params[1] = stoi(paramStr[1]) - 1;
    i += 5;
    paramStr[2] += input.at(i);
    params[2] = stoi(paramStr[2]) - 1;

    //printf("Moving %d from %d to %d\n", params[0], params[1], params[2]);
    move(params[0], params[1], params[2]);

  }

  display();
  fp.close();

}
