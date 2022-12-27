#include <fstream>
#include <queue>
#include "../utils/utils.cc"
//define MAP_X 8
//define MAP_Y 5
#define MAP_X 181
#define MAP_Y 41

// 520 too low, 529 too high

vector< vector<int> > map;
const string alphabet = "SabcdefghijklmnopqrstuvwxyzE";

int bfs(int Sx, int Sy, int goal){
  bool visited[MAP_Y][MAP_X];
  int x;
  int y;
  int d;
  queue< pair<int, int> > next;
  queue<int> depths;

  for(int i = 0; i < MAP_Y; i++){
    for(int j = 0; j < MAP_X; j++){
      visited[i][j] = false;
    }
  }

  next.push(make_pair(Sx, Sy));
  depths.push(0);
  visited[Sy][Sx] = true;
  int maxd = 0;

  while (!next.empty()){
    x = next.front().first;
    y = next.front().second;
    d = depths.front();

    if(d > maxd){
      maxd = d;
    }
    if(d < maxd){
      printf("WARNING: lower d than expected");
    }

    next.pop();
    depths.pop();


    //printf("Visited (%d, %d)\n", x, y);
    if(map[y][x] == goal){
      return d;
    }
    if(x > 0 && map[y][x-1] >= map[y][x] - 1 && !visited[y][x-1]){
      next.push(make_pair(x-1, y));
      depths.push(d + 1);
      visited[y][x-1] = true;
    }
    if(y > 0 && map[y-1][x] >= map[y][x] - 1 && !visited[y-1][x]){
      next.push(make_pair(x, y-1));
      depths.push(d + 1);
      visited[y-1][x] = true;
    }
    if(x < MAP_X - 1 && map[y][x+1] >= map[y][x] - 1 && !visited[y][x+1]){
      next.push(make_pair(x+1, y));
      depths.push(d + 1);
      visited[y][x+1] = true;
    }
    if(y < MAP_Y - 1 && map[y+1][x] >= map[y][x] - 1 && !visited[y+1][x]){
      next.push(make_pair(x, y+1));
      depths.push(d + 1);
      visited[y+1][x] = true;
    }
  }
  return -1;
}

int main(){
  ifstream fp("Inputs/Day12.txt");
  string input;
  vector<int> temp;
  int Sx;
  int Sy;
  int y = 0;

  while(getline (fp, input)) {
    temp.clear();
    for(int x = 0; x < input.length(); x++){
      temp.push_back(alphabet.find(input.at(x)));
      if (alphabet.find(input.at(x)) == 27){
        Sx = x;
        Sy = y;
      }
    }
    map.push_back(temp);
    y++;
  }
  fp.close();

  if(map.size() != MAP_Y){
    printf("ERROR: Dims don't match, map.size() = %lu, MAP_Y = %d\n", map.size(), MAP_Y);
    printf("Modify MAP_Y to match map.size()\n");
    abort();
  }
  if(map.at(0).size() != MAP_X){
    printf("ERROR: Dims don't match, map.at(0).size() = %lu, MAP_X = %d\n", map.at(0).size(), MAP_X);
    printf("Modify MAP_X to match map.at(0).size()\n");
    abort();
  }

  int ans;
  ans = bfs(Sx, Sy, 0);
  printf("Part 1 answer (may be incorrect): %d\n", ans);

  ans = bfs(Sx, Sy, 1);
  printf("Part 2 answer (may be incorrect): %d\n", ans);
  /*
  for(int i = 0; i < map.size(); i++){
    printVector(map.at(i));
  }
  printf("Start x: %d, Start y: %d\n", Sx, Sy);
  */

}
