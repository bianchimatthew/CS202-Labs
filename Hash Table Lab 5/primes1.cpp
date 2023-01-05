//Matthew Bianchi Part 2 of Lab6
//Takes a value as input and prints all prime numbers starting from 2 to that value

#include <iostream>
#include <cmath>


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
    int count = 1;
    int val = atoi(argv[1]);
    //Loops from 2 to val and prints all prime numbers
    for(int i = 2; i <= val; i++){
        //if prime prints value
        if(isPrime(i)){
            printf("%d, ", i);
            //New line count for 20 numbers
            count++;
            if(count % 21 == 0){
                printf("\b\b \n");
            }   
        }
    }
    printf("\b\b \n");
    return 0;
}

