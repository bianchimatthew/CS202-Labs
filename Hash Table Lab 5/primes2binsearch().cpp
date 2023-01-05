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
  return true;
}


int main(int argc, char *argv[]){  
  int val = 0;
  int max = 1;
  std::vector<int> primes;
  
  while(std::cin >> val){
    bool primeNum = false;
    if(val > max){
      for(int i = max + 1; i <= val; i++){
        if(isPrime(i)){
          primes.push_back(i);
        }
      }
      max = val;
      if(isPrime(val)){
        primeNum = true;
      }
    } else {
      if(std::binary_search(primes.begin(), primes.end(), val)){
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

