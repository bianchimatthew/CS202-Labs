//Matthew Bianchi Part 3 of Lab6
//Uses a map and a caching system to store all prime numbers between the max value and 2

#include <iostream>
#include <cmath>
#include <map>

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
  std::map<int, bool> primes; //Map with integer key which is the val of prime number and bool which tells if the val at that key is true.
  
  //Loops while there is still input
  while(std::cin >> val){
    //Checks if there is a new max value
    if(val > max){
      //Loops between new max value and old max value to create a caching system
      for(int i = max + 1; i <= val; i++){
        if(isPrime(i)){
          primes[i] = isPrime(i);//Stores true bool into map at correct val
        }
      }
      //Sets old max to new max
      max = val;
    }
    //Checks if val is prime or not
    if(primes[val]){
      printf("prime\n");
    } else if(!primes[val]){
      printf("not prime\n");
    }
  }
  printf("\n");
  return 0;
}

