//Matthew Bianchi
//Column Class Functions
#include "C4Col.h"
#include <iostream>
using namespace std;

//Column Constructor
C4Col::C4Col(){
        numDiscs = 0;
        maxDiscs = 6;
        for(int i = 0; i < maxDiscs; i++){
            discs[i] = '-';
        }
}
//Checks if the column is full
int C4Col::isFull(){
    if(numDiscs == getMaxDiscs()){
        return 1;
    } else {
        return 0;
    }
}

//Gets the disc at the specified index of the column
char C4Col::getDisc(int index){
    if(index < maxDiscs || index >= 0){
        return discs[index];
    } else {
        return 'E';
    }
}

//Finds the max amount of Discs set in the column constructor
int C4Col::getMaxDiscs(){
    return maxDiscs;
}

//Adds the correct disc into the column starting from bottum up
void C4Col::addDisc(char player){
	if(player == 'X' || player == 'O'){	
		for(int i = 0; i < getMaxDiscs(); i++){
			if(discs[i] == '-'){
				discs[i] = player;
				numDiscs++;
				return;   
			}
		}
	}
}
