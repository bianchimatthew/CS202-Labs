//Matthew Bianchi
//Connect4 Board Constructor and game functions
#include "C4Board.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//Board constructor
C4Board::C4Board(){
}

//Displays the board in a Connect4 Format
void C4Board::display(){
	//Cosmetic Loop that displays the value of the column above the board
	cout << " ";
	for(int i = 0; i < numCols; i++){
		cout << " " << i << "  ";
	}
	cout << endl;

	//Loops through the 2D array and displays the board as a matrix
    for(int i = board[0].getMaxDiscs() - 1; i >= 0; i--){
        for(int j = 0; j < numCols; j++){
			
            cout << "| " << board[j].getDisc(i) << " ";
        }
        cout << "|" << endl; 
    }
    return;
}

//Runs the game with a turn count and optional AI
void C4Board::play(){
    int turn = 0;
    char player;
    int col;
    int playerCount;
	//1 Player == Player vs AI and 2 Player == Player vs Player
    cout << "1 or 2 player? "; 
    cin >> playerCount;
	//Keeps the game running as long as the board as spaces left
    while(turn < board[0].getMaxDiscs() * numCols){
		//Player vs Player
		if(playerCount == 2){
			display();
			cout << "Enter Column: ";
			cin >> col;
			//Keeps track of which player is making a move based on the turn count
			if(turn % 2 == 0){
				player = 'X';
			} else {
				player = 'O';
			}
		//Player vs AI
		} else if (playerCount == 1){
			display();
			if(turn % 2 == 0){
				cout << "Enter Column: ";
				cin >> col;
				player = 'X';
			} else {
				col = rand() % numCols; //AI chooses a random number between 0 and one less than the number of columns
				cout << "Enter Column: " << col << endl;
				player = 'O';
			}
		//Checks if the user input for playerCount is 1 or 2
		} else {
			cout << "Invalid Input: Please select 1 or 2 players: ";
			cin >> playerCount;
		}
		//Checks if the input value is an existing column or out of bounds
		if(col >= numCols || col < 0){
			cout << "Invalid Input: Column does not exist" << endl;
		} else if (col < numCols && col > 0) {
			//Checks if the column is full if not places the players disc in the board
			if(board[col].isFull() == 0){
				board[col].addDisc(player);
				turn++;
			} else {
				cout << "Invalid Input: Column is full" << endl;
			}
			//Checks for a win
			if(gameWin(player) == 1){
				display();
                cout << player << " Wins" << endl;
                return;
            }
        }	
    }
	//If loop ends game ends in a tie
	cout << "Tie" << endl;
    return;
}
