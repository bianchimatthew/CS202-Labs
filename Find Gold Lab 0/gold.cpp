//Matthew Bianchi
//Lab 0 Review over CS102 Topics
//Uses cin to take data of a map and finds how much gold there is
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  char c;
  int val;
  int gold;
  while(cin >> c) {
    val = c;
    if(val > 64 && val < 91){
      gold += (val - 64);
    }
  }  
  cout << gold << endl;
  return 0;
}

