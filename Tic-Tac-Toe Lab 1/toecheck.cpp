// Matthew Bianchi COSC 202
// Lab 1:  Tic-tac-toe solver using preset boards
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {

  char move;
  int gridSize;
  int index = 0;

  //Reads gridSize from file and initalizes grid
  cin >> move; 
  gridSize = (move - 48);
  char grid[gridSize][gridSize];

  //Loops until no more input from file and sets the input to the correct spaces in the grid
  while(cin >> move){
    if(move == 'X' || move == 'O' || move == '-'){ //Checks for valid input from file
      grid[(index) / gridSize][(index) % gridSize] = move; 
      index++;
    }
  }
  
  int diagCheck = 0;
  int backCheck = 0;
  int colCheck;
  int rowCheck;
  char player;

  //Loops through each individual grid space counting how many 'X' and 'O's are in a row.
  for(int i = 0; i < gridSize; i++){
    colCheck = 0;
    rowCheck = 0;
    //Checks Top Left to Bottom Right Diagonal
    if(grid[0][0] == grid[i][i] && grid[0][0] != '-'){
      diagCheck++;
      if(grid[0][0] == 'X'){
        player = 'X';
      } else {
        player = 'O';
      }
      if(diagCheck == gridSize){
        cout << player << " wins" << endl;
        return 0;
      }
    }
    //Checks Top Right to Bottom Left Diagonal
    if(grid[0][gridSize - 1] == grid[i][gridSize - 1 - i] && grid[0][gridSize - 1] != '-'){
      backCheck++;
      if(grid[0][gridSize - 1] == 'X'){
        player = 'X';
      } else {
        player = 'O';
      }
      if(backCheck == gridSize){
        cout << player << " wins" << endl;
        return 0;
      }
    }
    for(int j = 0; j < gridSize; j++){
      //Checks every column in the grid
      if(grid[0][i] == grid[j][i] && grid[0][i] != '-'){
        colCheck++;
        if(grid[0][i] == 'X'){
          player = 'X';
        } else {
          player = 'O';
        }
        if(colCheck == gridSize){
          cout << player << " wins" << endl;
          return 0;
        }
      }
      //Checks every row in the grid
      if(grid[i][0] == grid[i][j] && grid[i][0] != '-'){
        rowCheck++;
        if(grid[i][0] == 'X'){
          player = 'X';
        } else {
          player = 'O';
        }
        if(rowCheck == gridSize){
          cout << player << " wins" << endl;
          return 0;
        }
      }
    }
  }
  //If for loops breaks the game ends in a tie
  cout << "Tie" << endl;  
  return 0;
}

