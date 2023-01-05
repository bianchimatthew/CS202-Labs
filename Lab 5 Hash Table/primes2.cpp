//Matthew Bianchi Part 2 of Lab6
//Uses a vector and a caching system to store all prime numbers between a max value and 2

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

//Finds if input val is prime
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
  
  //Loops while there is still input
  while(std::cin >> val){
    bool primeNum = false;
    //Checks if there is a new max value
    if(val > max){
      //Loops between new max value and old max value to create a caching system
      for(int i = max + 1; i <= val; i++){
        //Adds number to vector if it is prime
        if(isPrime(i)){
          primes.push_back(i);
        }
      }
      //Sets old max to new max
      max = val;
      //Sets primeNum to true if the val is prime
      if(isPrime(val)){
        primeNum = true;
      }
    } else {
      //Uses find() to find if the value was stored in the vector
      if(std::find(primes.begin(), primes.end(), val) != primes.end()){
		    primeNum = true;
      }
    }
    //Checks if number is prime or not
    if(primeNum){
      printf("prime\n");
    } else if(!primeNum){
      printf("not prime\n");
    }
  }
  printf("\n");
  return 0;
}

