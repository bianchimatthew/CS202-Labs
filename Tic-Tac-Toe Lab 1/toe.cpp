// Matthew Bianchi COSC 202
// Lab 1:  Interactive Tic-Tac-Toe Game
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
  //Initializes grid for game and prints a blank grid
  int gridSize;
  cin >> gridSize;
  char grid[gridSize][gridSize];
  for(int i = 0; i < gridSize; i++){
    for(int j = 0; j < gridSize; j++){
      grid[i][j] = '-';
      if(((j + 1) % gridSize) != 0){
        cout << grid[i][j] << " ";
      } else {
        cout << grid[i][j] << endl;
      }  
    }
  }





  //Initializes player, turn count, and row and col variables for user input
  char player;
  int turn = 0;
  int row;
  int col;

  //Runs a while loop as long as the turn count is less than the total number of spaces
  while(turn < (gridSize*gridSize)){
    //User input for where to place an 'X' or 'O'
    cout << "Enter Row: ";
    cin >> row;
    cout << "Enter Col: ";
    cin >> col;
    //Checks for valid input I.E. cannot place an 'X' or 'O' if the location is not populated with a '-'
    if(grid[row-1][col-1] != '-'){
      cout << "Error Invalid Input -- Space Already Taken" << endl;
    } else {
      //Keeps track of turns and whether to place an 'X' or 'O' in the specified row and col
      if (turn % 2 == 0){
        player = 'X';
        grid[row-1][col-1] = player;
      } else {
        player = 'O';
        grid[row-1][col-1] = player;
      }
      //Prints grid with updated user input
      for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
          if(((j + 1) % gridSize) != 0){
            cout << grid[i][j] << " ";
          } else {
            cout << grid[i][j] << endl;
          }  
        }
      }
      
      //Initializes the check counters
      int diagCheck = 0;
      int backCheck = 0;
      int colCheck;
      int rowCheck;
      //Loops through each individual grid space counting how many 'X' and 'O's are in a row.
      for(int i = 0; i < gridSize; i++){
        colCheck = 0;
        rowCheck = 0;
        //Checks Top Left to Bottom Right Diagonal
        if(grid[0][0] == grid[i][i] && grid[0][0] != '-'){
          diagCheck++;
        }
        //Checks Top Right to Bottom Left Diagonal
        if(grid[0][gridSize - 1] == grid[i][gridSize - 1 - i] && grid[0][gridSize - 1] != '-'){
          backCheck++;
        }
        for(int j = 0; j < gridSize; j++){
          //Checks every column in the grid
          if(grid[0][i] == grid[j][i] && grid[0][i] != '-'){
            colCheck++;
          }
          //Checks every row in the grid
          if(grid[i][0] == grid[i][j] && grid[i][0] != '-'){
            rowCheck++;
          }
          //If any of the check counters reach the size of the grid game ends with a winner
          if(rowCheck == gridSize || colCheck == gridSize || diagCheck == gridSize || backCheck == gridSize){
            cout << player << " Wins" << endl;
            return 0;
          }
        }
      }
      turn++;
    }
  }
  //If while loops breaks the game ends in a tie
  cout << "Tie" << endl;
  return 0;
}

