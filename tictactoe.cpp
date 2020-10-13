#include <iostream>
#include "tictactoe.h"
#include <stdlib.h>
using namespace std;
 
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "};
string player1, player2;
int player = 1; //refers to player 1!
char ply1 = 'X';
char ply2 = 'O';
 
void introduction() {
 
 cout<< "Press [ENTER] to begin: ";
 cin.ignore();
 cout<< "\n";
 cout<< "This is TIC TAC TOE!\n";
 cout<< "Enter name of player1: \n";
 cin>> player1;
 cout<< "Enter name of player2: \n";
 cin>> player2;
 cout<< "Welcome " <<player1 << " and "<< player2<<"!\n\n";
 
 cout<< "Here's a 3x3 grid!\n";
 cout << "     |     |      \n";
 cout << "  1  |  2  |  3   \n";
 cout << "_____|_____|_____ \n";
 cout << "     |     |      \n";
 cout << "  4  |  5  |  6   \n";
 cout << "_____|_____|_____ \n";
 cout << "     |     |      \n";
 cout << "  7  |  8  |  9   \n";
 cout << "     |     |      \n\n";
 
 cout<< player1<< " will start with X!\n";
 cout<< player2<< " will then continue with O!\n";
}
 
bool full_board() {
 //needs to be set true and then false! Other way won't work.
 bool filled = true;
 for(int i = 0; i < 9; i++) {
   if(board[i] == " ") {
     filled = false;
   }
 }
 return filled;
}
 
void set_position() {
 
 while(!full_board() && !isWinner()) {
   int position;
   cout<< "Please choose a number between 1 and 9: \n";
   cin>> position;
   while(position <1 || position >9) {
     cout<<"Please enter a valid number: \n";
     cin>> position;
   }
   while(board[position-1] != " ") {
     cout<< "This position is occupied!\n";
     cout<< "Choose another position.\n";      
     cin>> position;
   }
   //PLAYER ONE TURN!
   if(player == 1 && !isWinner()) {
     if(board[position-1] == " ") {
       board[position-1] = ply1;
       draw();
       player = 0;
     }
   }
   //PLAYER TWO TURN!
   if(player == 0 && !isWinner()) {
     if(board[position-1] == " ") {
       board[position-1] = ply2;
       draw();
       player = 1;
     }
   }
 }
}
 
void draw() {
 cout << "     |     |      \n";
 cout <<"  "<<board[0]<<"  |  "<<board[1]<<"  |  "<<" "<<board[2]<<"\n";
 cout << "_____|_____|_____ \n";
 cout << "     |     |      \n";
 cout <<"  "<<board[3]<<"  |  "<<board[4]<<"  |  "<<" "<<board[5]<<"\n";
 cout << "_____|_____|_____ \n";
 cout << "     |     |      \n";
 cout <<"  "<<board[6]<<"  |  "<<board[7]<<"  |  "<<" "<<board[8]<<"\n";
 cout << "     |     |      \n\n";
}
 
bool isWinner() {
 bool winner = false;
 //rows:
 if((board[0] == board[1]) && (board[0] == board[2]) && board[0] != " ") {
   winner = true;
 }
 else if((board[3] == board[4]) && (board[3] == board[5]) && board[3] != " ") {
   winner = true;
 }
 if((board[6] == board[7]) && (board[6] == board[8]) && board[6] != " ") {
   winner = true;
 }
 //columns:
 else if((board[0] == board[3]) && (board[0] == board[6]) && board[0] != " ") {
   winner = true;
 }
 else if((board[1] == board[4]) && (board[1] == board[7]) && board[1] != " ") {
   winner = true;
 }
 else if((board[2] == board[5]) && (board[2] == board[8]) && board[2] != " ") {
   winner = true;
 }
 //diagonals:
 else if((board[0] == board[4]) && (board[0] == board[8]) && board[0] != " ") {
   winner = true;
 }
 else if((board[2] == board[4]) && (board[2] == board[6]) && board[2] != " ") {
   winner = true;
 }
 return winner;
}
 
void end_game() {
 
 if(isWinner() && player == 1) {
   cout<< player2<< " you won the game!\n";
 }
 else if(isWinner() && player == 0) {
   cout<< player1<< " you won the game!\n";
 }
 else if(!isWinner()) {
   cout<< "It is a tie!\n You both suck!\n";
 }
}
