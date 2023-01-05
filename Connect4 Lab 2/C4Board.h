//Matthew Bianchi
//Connect4 Board Class Header File

#include <iostream>
#include "C4Col.h"

class C4Board {
    private:
        int numCols = 7;
        C4Col board[7];
        int winCount = 4;
		//Private Member Function that keeps determines when the game is over
        int gameWin(char player){
			//Loops through the board using nested for loops
            for(int i = 0; i < board[0].getMaxDiscs(); i++){
                for(int j = 0; j < numCols; j++){
					//Only runs after the last move was placed
                    if(board[j].getDisc(i) == player){
                        int rowCount = 0;
                        int colCount = 0;
                        int diagCount = 0;
                        int backCount = 0;
                        //Check's Row
                        for(int k = 0; k < winCount; k++){
                            if((j + k < numCols) && (board[j + k].getDisc(i) == player)){
                                rowCount++;
                            }
                        }
                        //Check's Column
                        for(int k = 0; k < winCount; k++){
                            if((i + k < board[0].getMaxDiscs()) && (board[j].getDisc(i + k) == player)){
                                colCount++;
                            }
                        }
                        //Check's Diagonal
                        for (int k = 0; k < winCount; k++){
                            if ((j + k < numCols) && (i + k < board[0].getMaxDiscs()) && (board[j + k].getDisc(i + k) == player)){
                                diagCount++;
                            }
                        }       
                        //Check's Backwards Diagonal
                        for (int k = 0; k < winCount; k++){
                            if ((j - k >= 0) && (i + k < board[0].getMaxDiscs()) && (board[j - k].getDisc(i + k) == player)){
                                backCount++;
                            }
                        }
                        //If any of the checks equal the winCount returns 1 to signify a winner
                        if(rowCount == winCount || colCount == winCount || diagCount == winCount || backCount == winCount){
                            return 1;
                        }
                    }
                }
            }
            return 0;
        }    
    public:
        C4Board();
        void display();
        void play();
};
