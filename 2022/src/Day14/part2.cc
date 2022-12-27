#include <fstream>
#include <set>
#include "../utils/utils.cc"

set< pair<int,int> > walls;
int maxY = 0;

void makeWall(string from, string to){
  int x = stoi(split(from, ',').at(0));
  int y = stoi(split(from, ',').at(1));
  int x2 = stoi(split(to, ',').at(0));
  int y2 = stoi(split(to, ',').at(1));

  if (max(y, y2) > maxY){
    maxY = max(y, y2);
  }

  if(y == y2){
    for(int i = min(x, x2); i <= max(x, x2); i++){
      //printf("adding wall at (%d, %d)\n", i, y);
      walls.insert(make_pair(i, y));
    }
  } else if(x == x2){
    for(int i = min(y, y2); i <= max(y, y2); i++){
      //printf("adding wall at (%d, %d)\n", x, i);
      walls.insert(make_pair(x, i));
    }
  } else{
    printf("ERROR: non horizontal line? From (%d, %d) to (%d, %d)\n", x, y, x2, y2);
  }

}

int main(){
  ifstream fp("Inputs/Day14.txt");
  string input;
  vector<string> temps;

  while(getline (fp, input)) {
    temps = split(input, ' ');

    for(int i = 0; i < temps.size()-1; i += 2){
      // printf("from %s to %s\n", temps.at(i).c_str(), temps.at(i+2).c_str());
      makeWall(temps.at(i), temps.at(i+2));
    }
  }
  fp.close();

  // printf("maxY = %d\n", maxY); // 167 is maxY for my input, so 169 is the floor


  int grains = 0;
  int x;
  int y;
  bool done = false;
  while (walls.count(make_pair(500, 0)) == 0){
    x = 500; y = 0;
    while(true){
      if(walls.count(make_pair(x, y+1)) == 0){
        y++;
      } else if(walls.count(make_pair(x-1, y+1)) == 0){
          y++;
          x--;
      } else if(walls.count(make_pair(x+1, y+1)) == 0){
        y++;
        x++;
      } else {
        walls.insert(make_pair(x, y));
        grains++;
        break;
      }

      if(y == maxY + 1){
        walls.insert(make_pair(x, y));
        grains++;
        break;
      }
    }
  }

  printf("Grains of sand: %d\n", grains);
}
