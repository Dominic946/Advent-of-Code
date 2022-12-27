#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<string> split(string text, char splitter){
  vector<string> result;
  string temp = "";
  for(int i = 0; i < text.length(); i++){
    if(text.at(i) == splitter){
      result.push_back(temp);
      temp = "";
    } else {
      temp += text.at(i);
    }
  }
  result.push_back(temp);
  return result;
}

vector<string> split(string text){
  string temp;
  vector<string> result;
  for(int i = 0; i < text.length(); i++){
    temp = text.at(i);
    result.push_back(temp);
  }
  return result;
}

template<typename T>
void printVector(vector<T> vec){
  cout << "[";
  for(int i = 0; i < vec.size(); i++){
    cout << vec.at(i);
    if(i < vec.size() - 1){
      cout << ", ";
    }
  }
  cout << "]\n";
}

template<typename T>
void printPairVector(vector< pair<T, T> > vec){
  cout << "[";
  for(int i = 0; i < vec.size(); i++){
    cout << '<';
    cout << vec.at(i).first;
    cout << ", ";
    cout << vec.at(i).second;
    cout << '>';
    if(i < vec.size() - 1){
      cout << ", ";
    }
  }
  cout << "]\n";
}

vector<int> vectorStoi(vector<string> vec){
  vector<int> result;
  for(int i = 0; i < vec.size(); i++){
    result.push_back(stoi(vec.at(i)));
  }
  return result;
}

// int main(){}
