#include <fstream>
#include <set>
#include "../utils/utils.cc"

set< pair<int,int> > walls;
set< pair<int,int> > sand;
int minX = 500;
int maxX = 500;
int minY = 0;
int maxY = 0;


void makeWall(string from, string to){
  int x = stoi(split(from, ',').at(0));
  int y = stoi(split(from, ',').at(1));
  int x2 = stoi(split(to, ',').at(0));
  int y2 = stoi(split(to, ',').at(1));

  if (min(x, x2) < minX){
    minX = min(x, x2);
  }
  if (max(x, x2) > maxX){
    maxX = max(x, x2);
  }
  if (min(y, y2) < minY){
    minY = min(y, y2);
  }
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

  int grains = 0;
  int x;
  int y;
  bool done = false;
  while (!done){
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
        sand.insert(make_pair(x, y));
        grains++;
        break;
      }

      if(y > 10000){
        done = true;
        break;
      }
    }
  }

  for(y = minY; y < maxY + 2; y++){
    for(x = minX - 1; x < maxX + 2; x++){
       if(sand.count(make_pair(x,y)) == 1){
         cout << "o";
       } else if(walls.count(make_pair(x,y)) == 1){
         cout << "#";
       } else if(y == 0 && x == 500){
          cout << "+";
       } else {
         cout << ".";
       }
    }
    cout << endl;
  }
  printf("X range: [%d, %d]\nY range: [%d, %d]\n", minX, maxX, minY, maxY);
  printf("Grains of sand: %d\n", grains);


}
