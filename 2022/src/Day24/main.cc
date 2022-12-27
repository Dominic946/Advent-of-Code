#include <fstream>
#include "../utils/utils.cc"

set< pair<int,int> > positions;
set< pair<int,int> > walls;
vector< pair<int,int> > could;
set< pair<int,int> > couldSet;
int wrapX = 0;
int wrapY = 0;

class Blizzard {
public:
  int x;
  int y;
  char dir;

  Blizzard(int x, int y, char dir) {
    this->x = x;
    this->y = y;
    this->dir = dir;
    positions.insert(make_pair(this->x, this->y));
  }

  void move() {
    switch (dir) {
      case '^':
        y--;
        if(walls.count(make_pair(this->x, this->y)) == 1){
          this->y = wrapY;
        }
        break;
      case 'v':
        y++;
        if(walls.count(make_pair(this->x, this->y)) == 1){
          this->y = 1;
        }
        break;
      case '<':
        x--;
        if(walls.count(make_pair(this->x, this->y)) == 1){
          this->x = wrapX;
        }
        break;
      case '>':
        x++;
        if(walls.count(make_pair(this->x, this->y)) == 1){
          this->x = 1;
        }
        break;
      default:
        printf("ERROR dir not one of {^, v, <, >}");
        break;
    }
  positions.insert(make_pair(this->x, this->y));
  }
};

vector<Blizzard*> Blizzard_List;

void display(int maxX, int maxY){
  for(int y_ = -1; y_ <= maxY; y_++){
    for(int x_ = 0; x_ <= maxX; x_++){
      if(walls.count(make_pair(x_, y_)) == 1){
        printf("#");
      } else if(positions.count(make_pair(x_, y_)) == 1){
        printf("B");
      } else if(couldSet.count(make_pair(x_, y_)) == 1){
        printf("C");
      } else {
        printf(".");
      }
    }
    cout << endl;
  }
  cout << endl;
}

void addCould(pair<int, int> pos){
  if(couldSet.count(pos) == 0){
    could.push_back(pos);
    couldSet.insert(pos);
  }
}

int trip(pair<int, int> start, pair<int, int> goal){
  int steps = 0;
  could.clear();
  couldSet.clear();

  addCould(make_pair(start.first, start.second));

  while(true){
    positions.clear();
    for(int k = 0; k < Blizzard_List.size(); k++){
      Blizzard_List.at(k)->move();
    }
    vector< pair<int,int> > temp = could;
    could.clear();
    couldSet.clear();

    for(int k = 0; k < temp.size(); k++){
      int x_ = temp.at(k).first;
      int y_ = temp.at(k).second;
      pair<int, int> pos = make_pair(x_, y_);

      if(pos == goal){
        return steps + 1;
      }
      if(positions.count(pos) == 0 && walls.count(pos) == 0){
        addCould(make_pair(x_, y_));
        addCould(make_pair(x_ - 1, y_));
        addCould(make_pair(x_ + 1, y_));
        addCould(make_pair(x_, y_ - 1));
        addCould(make_pair(x_, y_ + 1));
      }
    }

    steps++;
    if(false && steps%20 == 0){
      printf("Step %d\n", steps);
    }
    assert(steps < 2000);
  }
}


int main(){
  ifstream fp("Inputs/Day24.txt");
  string input;
  int y = 0;
  int maxX = 0;
  walls.insert(make_pair(0, -1));
  walls.insert(make_pair(1, -1));
  walls.insert(make_pair(2, -1));

  while(getline (fp, input)) {
    maxX = max(maxX, (int)input.size()-1);
    for(int x = 0; x < input.size(); x++){
      switch(input.at(x)){
        case '^': case 'v': case '<': case '>':
          Blizzard_List.push_back(new Blizzard(x, y, input.at(x)));
          break;
        case '#':
          walls.insert(make_pair(x, y));

          break;
        default:
          break;
      }
    }
    y++;
  }

  walls.insert(make_pair(maxX, y));
  walls.insert(make_pair(maxX - 1, y));
  walls.insert(make_pair(maxX - 2, y));
  wrapX = maxX - 1;
  wrapY = y - 2;

  fp.close();

  //display(maxX, y);

  int ans;
  ans = trip(make_pair(1,0), make_pair(wrapX, wrapY + 1));

  printf("Part 1 answer: %d\n", ans);

  ans += trip(make_pair(wrapX, wrapY + 1), make_pair(1,0));
  ans += trip(make_pair(1,0), make_pair(wrapX, wrapY + 1));

  printf("Part 2 answer: %d\n", ans);

}
