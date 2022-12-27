#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
ifstream fp("Inputs/Day7.txt");
string input;

class directory{
  public:
    vector<int> files;
    vector<string> fileNames;
    vector<directory*> subDirs;
    string name;
    directory* parent;

    int totalSize(){
      int total = 0;
      for(int i = 0; i < files.size(); i++){
        total += files.at(i);
      }
      for(int i = 0; i < subDirs.size(); i++){
        total += subDirs.at(i)->totalSize();
      }
      return total;
    }
    directory(string name_, directory* parent_){
      this->name = name_;
      this->parent = parent_;
    }

    void print(string spacing){
      printf("%s~ %s (dir)\n", spacing.c_str(), name.c_str());

      for(int i = 0; i < fileNames.size(); i++){
        printf("%s   - %s (file size = %d)\n", spacing.c_str(), fileNames.at(i).c_str(), files.at(i));
      }

      for(int i = 0; i < subDirs.size(); i++){
        subDirs.at(i)->print(spacing + "   ");
      }
    }

    int sumSmalls(int n = 100000){
      int total = 0;
      int mySize = this->totalSize();
      if(mySize <= n){
        total += mySize;
      }
      for(int i = 0; i < subDirs.size(); i++){
        total += subDirs.at(i)->sumSmalls();
      }
      return total;
    }

    directory* smallestDir(int minSize){
      directory* candidate;
      int smallest = this->totalSize();
      directory* smallestPtr = NULL;
      if(smallest < minSize){
        smallest = -1;
      } else {
        smallestPtr = this;
      }
      for(int i = 0; i < subDirs.size(); i++){
        candidate = subDirs.at(i)->smallestDir(minSize);
        if(candidate == NULL){
          continue;
        } else if(candidate->totalSize() < smallest){
          smallest = candidate->totalSize();
          smallestPtr = candidate;
        }
      }
      return smallestPtr;
    }

    ~directory(){
      for(int i = 0; i < subDirs.size(); i++){
        delete subDirs.at(i);
      }
    }
};

directory* cwd;
directory* root;

void handleCD(string arg){
  if (arg == "/"){
    cwd = root;
    return;
  }
  if (arg == ".."){
    cwd = cwd->parent;
    return;
  }
  for(int i = 0; i < cwd->subDirs.size(); i++){
    if(cwd->subDirs.at(i)->name == arg){
      cwd = cwd->subDirs.at(i);
      return;
    }
  }
  directory* newDir = new directory(arg, cwd);
  cwd->subDirs.push_back(newDir);
  cwd = newDir;
  return;
}

void handleLS(int size, string name){
  for(int i = 0; i < cwd->fileNames.size(); i++){
    if(cwd->fileNames.at(i) == name){
      return;
    }
  }
  cwd->fileNames.push_back(name);
  cwd->files.push_back(size);
  return;
}

void handleLSDir(string name){
  for(int i = 0; i < cwd->subDirs.size(); i++){
    if(cwd->subDirs.at(i)->name == name){
      return;
    }
  }
  directory* newDir = new directory(name, cwd);
  cwd->subDirs.push_back(newDir);
  return;
}

int main(){
  root = new directory("/", NULL);

  ifstream fp("Inputs/Day7.txt");
  string input;
  string temp;
  int size;

  while(getline (fp, input)) {
    if(input.at(0) == '$'){
      if(input.at(2) == 'c'){
        temp = "";
        int i = 5;
        do{
          temp += input.at(i);
          i++;
        } while (i < input.length());
        handleCD(temp);
      } else
      if(input.at(2) == 'l'){
        continue;
      }
    } else {
      temp = "";
      int i = 0;
      while(input.at(i) != ' '){
        temp += input.at(i);
        i++;
      }
      if(temp == "dir"){
        size = -1;
      } else {
        size = stoi(temp);
      }
      temp = "";
      i++;
      while(i < input.length()){
        temp += input.at(i);
        i++;
      }
      size == -1? handleLSDir(temp):handleLS(size, temp);
    }
  }

  root->print("");
  printf("\nFile system total size is: %d\n", root->totalSize());
  printf("Total sum of dirs less than 100000: %d\n", root->sumSmalls());
  int needed = 70000000 - root->totalSize();
  needed = 30000000 - needed;
  directory* best = root->smallestDir(needed);
  printf("Smallest directory greater than %d has size: %d\n", needed, best->totalSize());
  fp.close();
  delete root;
}
