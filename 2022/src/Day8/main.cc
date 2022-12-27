#include <fstream>
#include "../utils/utils.cc"

ifstream fp("Inputs/Day8.txt");
string input;
vector< vector<int> > data;

bool isVisible(int y, int x){
  if (x == 0 || y == 0){
    return true;
  }
  if (x == data.size() - 1 || y == data.at(0).size() - 1){
    return true;
  }

  int height = data.at(y).at(x);
  bool good = false;
  int k;

  for(k = x-1; k >= 0; k--){
    if(data.at(y).at(k) >= height){
      good = true;
      break;
    }
  }
  if(!good){
    return true;
  }
  good = false;
  for(k = x+1; k < data.at(0).size(); k++){
    if(data.at(y).at(k) >= height){
      good = true;
      break;
    }
  }
  if(!good){
    return true;
  }
  good = false;
  for(k = y-1; k >= 0; k--){
    if(data.at(k).at(x) >= height){
      good = true;
      break;
    }
  }
  if(!good){
    return true;
  }
  good = false;
  for(k = y+1; k < data.size(); k++){
    if(data.at(k).at(x) >= height){
      good = true;
      break;
    }
  }
  if(!good){
    return true;
  }
  return false;
}

int main(){
  ifstream fp("Inputs/Day8.txt");
  string input;
  vector<string> row;
  int i = 0;

  while(getline (fp, input)){

    row = split(input);
    data.push_back(vectorStoi(row));
    i++;
  }

  bool visible[data.size()][data.at(0).size()];

  int total = 0;

  for(i = 0; i < data.size(); i++){
    for(int j = 0; j < data.at(0).size(); j++){
      visible[i][j] = isVisible(i, j)? 1:0;
      total += visible[i][j]? 1:0;
      if(visible[i][j]){
        cout << data.at(i).at(j);
      } else {
        cout << "~";
      }
    }
    cout << endl;
  }

  printf("Total: %d\n", total);

  fp.close();
}
