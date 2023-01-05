// Lab 7:  N-queens using backtracking 
// Matthew Bianchi COSC202
// Takes an integer n in to create a board size and finds total number of solutions using recursive backtracking where n number of queens on the board are not attacking eachother
// while using constraints to find solutions much faster than checking every single full board.

#include <iostream>
using namespace std;

//Global variables that keep track of count of boards checked and number of solutions
int count = 0;
int solutions = 0;

//Checks if board passed is a valid solution
bool isValid(int board[], int size){
  for(int i = 0; i < size; i++){
    for(int j = i + 1; j < size; j++){
      if(board[i] == board[j] || abs(i-j) == abs(board[i] - board[j])){
        return false;
      }
    }
  }
  return true;
}

//Recursive function that finds possible solutions to the nqueens problem
void nqueens(int *board, int col, int size){
  if(col < size){
    //Creates different boards
    for(int i = 0; i < size; i++){
      board[col] = i;
      //Checks if the current board is valid and stops if the board cannot be valid
      if(isValid(board,col)){
        //Recursive function call
        nqueens(board, col + 1, size);
      }
    }  
  } else if (col == size){
    count = count + 1;
    //If board is valid prints
    if(isValid(board, size)){
      solutions++;
      int i = 0;
      for(i = 0; i < size - 1; i++){
        printf("%d, ", board[i]);
      }
      printf("%d\n", board[i]);      
    }
  }

  return;
}

int main(int argc, char *argv[]) {

  int size = atoi(argv[1]);
  int board[size];
  
  //Calls Function
  nqueens(board, 0, size);

  //Displays Board count and solution count to stderr
  cerr << count  << " Boards counted"<< endl;
  cerr << solutions << " Solutions" << endl;
  return 0;
}

