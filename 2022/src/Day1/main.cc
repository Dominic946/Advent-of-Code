#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int* check(int cals, int* maxCals){
  if (cals > maxCals[0]){
    maxCals[2] = maxCals[1];
    maxCals[1] = maxCals[0];
    maxCals[0] = cals;

  } else if (cals > maxCals[1]){
    maxCals[2] = maxCals[1];
    maxCals[1] = cals;

  } else if (cals > maxCals[2]){
    maxCals[2] = cals;

  }
  return maxCals;
}


int main(){ //int argc, char** argc){
  ifstream fp("Inputs/Day1.txt");
  string input;
  int elfNum = 1;
  int calories = 0;
  int maxCalories[] = {0,0,0};

  while(getline (fp, input)) {
    if (input == ""){
      check(calories, maxCalories);
      calories = 0;
      elfNum++;

    } else {
      calories += stoi(input);
    }
  }

  printf("Highest: [%d, %d, %d]\n", maxCalories[0], maxCalories[1], maxCalories[2]);
  printf("Sum: %d\n", maxCalories[0] + maxCalories[1] + maxCalories[2]);
  fp.close();
}
