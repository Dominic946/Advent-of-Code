#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

/*
 By Dominic Deiman

 My own functions that I regularly use when solving Advent of Code problems.
 All my C++ Advent of Code solutions probably #include this file.
*/

/*
  split(string, char)
  Returns a vector of strings

  Splits a string into a vector of strings, splitting at each instance of char.

  This is probably a built in function somewhere in C++, but I couldn't find it.
  And I know it is a built in function in other languages, but I wanted to write
  it myself for practice anyway.

  Example: if the string grocery_list is "bread-milk-egg-pie",
           calling split(grocery_list, '-');
           will return a string vector containing {"bread", "milk", "egg", "pie"}
*/
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


/*
  split(string)
  Returns a vector of one character long strings

  Splits a string into a vector of strings,
  where each character of the string is its own element of the vector.

  Example: if the string grocery is "bread",
           calling split(grocery);
           will return a string vector containing {"b", "r", "e", "a", "d"}
*/
vector<string> split(string text){
  string temp;
  vector<string> result;
  for(int i = 0; i < text.length(); i++){
    temp = text.at(i);
    result.push_back(temp);
  }
  return result;
}

/*
  printVector(vector)
  Returns nothing

  Prints every element in a vector, in a readable way.
  Example: if you have a string vector grocery_list that contains {"bread", "milk", "egg", "pie"}
           calling printVector(grocery_list);
           will print to the terminal: [bread, milk, egg, pie]
*/
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

/*
  printPairVector(vector)
  Returns nothing

  Prints every element in a vector in a readable way, where the vector contains pairs.
  Example: if you have a vector< pair<int, int> > called coordinates that contains {(0,0), (1,2), (3,4)}
           calling printPairVector(coordinates);
           will print to the terminal: [<0, 0>, <1, 2>, <3, 4>]
*/
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

/*
  vectorStoi(vector of strings)
  Returns a vector of ints

  Calls the stoi function on all strings in a vector.
  Example: if you have a vector of strings that contains {"31", "41", "592", "65"}
           calling vectorStoi(numbers);
           will return a vector of integers containing: {31, 41, 592, 65}
*/
vector<int> vectorStoi(vector<string> vec){
  vector<int> result;
  for(int i = 0; i < vec.size(); i++){
    result.push_back(stoi(vec.at(i)));
  }
  return result;
}

// int main(){}
