#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int val){
  for(int i = sqrt(val); i > 1; i--){
    if(val % i == 0){
        return false;
    }
  }
  if(val == 0 || val == 1){
    return false;
  }
  return true;
}


int main(int argc, char *argv[]){  
  int val = 0;
  int max = 0;
  //int loadFactor = 0;
  //int count = 0;
  std::vector<int> primes;
  
  while(std::cin >> val){
    bool primeNum = false;
    if(val > max){
      //count = 0;
      for(int i = max + 1; i <= val; i++){
        if(isPrime(i)){
          primes.push_back(1);
          //count++;
        } else if (!isPrime(i)) {
          primes.push_back(0);
        }
      }
      max = val;
      if(primes[val - 1] == 1){
        primeNum = true;
      }
      //loadFactor += count;
    } else {
      if(primes[val - 1] == 1){
        primeNum = true;
      }
    }
    if(primeNum){
      printf("prime\n");
    } else if(!primeNum){
      printf("not prime\n");
    }
  }
  printf("\n");
  return 0;
}

