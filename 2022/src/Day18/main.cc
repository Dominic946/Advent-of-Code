#include <fstream>
#include "../utils/utils.cc"

int maxX = 0;
int maxY = 0;
int maxZ = 0;

class Coordinate {
 public:
  // Constructor that initializes the member variables x, y, and z
  Coordinate(int x, int y, int z, bool real = false) : x_(x), y_(y), z_(z) {
    if(real){
      maxX = max(maxX, x);
      maxY = max(maxY, y);
      maxZ = max(maxZ, z);
    }
  }

  // Equality operator that checks if all three coordinates are equal
  bool operator==(const Coordinate& other) {
    return x_ == other.x_ && y_ == other.y_ && z_ == other.z_;
  }

  bool operator<(const Coordinate& other) {
    return (x_*x_ + y_*y_ + z_*z_) < (other.x_*other.x_ + other.y_*other.y_ + other.z_*other.z_);
  }

  Coordinate operator+(const Coordinate& other){
    return Coordinate(x_ + other.x_, y_ + other.y_, z_ + other.z_);
  }

  void print(){
    printf("(%d, %d, %d)\n", x_, y_, z_);
  }

 private:
  int x_;
  int y_;
  int z_;
};

vector<Coordinate> lava;
vector<Coordinate> sides;

int main(){
  ifstream fp("Inputs/Day18.txt");
  string input;
  vector<string> temp;
  Coordinate tempCoord(0,0,0);

  sides.push_back(Coordinate(1, 0, 0));
  sides.push_back(Coordinate(-1, 0, 0));
  sides.push_back(Coordinate(0, 1, 0));
  sides.push_back(Coordinate(0, -1, 0));
  sides.push_back(Coordinate(0, 0, 1));
  sides.push_back(Coordinate(0, 0, -1));

  while(getline (fp, input)) {
    temp = split(input, ',');
    tempCoord = Coordinate(stoi(temp.at(0)), stoi(temp.at(1)), stoi(temp.at(2)), true);
    lava.push_back(tempCoord);
  }

  fp.close();

  int size = lava.size();
  int ans = 6 * size;

  for(int i = 0; i < size - 1; i++){
    for(int j = i+1; j < size; j++){
      for(int k = 0; k < sides.size(); k++){
        if(lava.at(j) == (lava.at(i) + sides.at(k))){
          ans -= 2;
          break;
        }
      }
    }
  }

  printf("Part 1 answer: %d\n", ans);

  //printf("maxX: %d, maxY: %d, maxZ: %d\n", maxX, maxY, maxZ);

  // 3402 is too high for my part 2.

 // Part 2 fail:
/*
  printf("Part 2 answer: %d\n", ans);

  int match;
  for(int x = 0; x < maxX; x++){
    for(int y = 0; y < maxY; y++){
      for(int z = 0; z < maxZ; z++){
        match = 0;
        for(int k = 0; k < sides.size(); k++){
          for(int i = 0; i < size; i++){
            if(Coordinate(x,y,z) + sides.at(k) == lava.at(i)){
              match++;
              break;
            }
          }
        }
        if(match > 5){
          match = 0;
          for(int i = 0; i < size; i++){
            if(Coordinate(x,y,z) == lava.at(i)){
              match = 1;
            }
          }
          if(match == 0){
            ans -= 6;
          }
        }
      }
    }
  }
*/
}
