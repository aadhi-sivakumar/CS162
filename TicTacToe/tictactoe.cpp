//**************************************************
//Author: Aadhi Sivakumar
//Assignment: Tic Tac Toe
//Date: 10/23/21
//Description: Like a normal tic tac toe game, a board will be drawn. Two players will altenrate turns filling slots and the program will keep count of the number of wins each player has. 
//Sources: Dad helped me with part of the code
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

//declaring array to create tic tac toe board
char board[4][4] = {{' ', '1', '2', '3'},{'a',' ' ,' ' ,' '},{'b',' ' ,' ' ,' '},{'c',' ' ,' ' ,' '}};

//function prototpes
void drawBoard();
void cleanBoard();
int checkwin();
bool isGameProgress();


int main() 
{
   //variables	
   int P1Count = 0;
   int P2Count = 0;
   char repeatGame = tolower('N');
   int player = 1;
   string choice;
   char mark;
   int r, c;
   int result = -1;

   do
   {
	   do
	   {  
	  
		     drawBoard();
		     //asks user to enter a slot 
		     cout << "Player " << player << ", enter a slot: " << endl; 
		     getline(cin, choice);
		     //Marks X or O in user slot for each palyer
		     mark = (player == 1) ? 'X' : 'O';
                     // sets row and column to slot options
		     if (choice.compare("a1")  == 0 )
		     {
			     r = 1; c = 1; 
		     }

		     else if (choice.compare("a2")  == 0 )
		     {
			     r = 1; c = 2; 
		     }
		     
		     else if (choice.compare("a3")  == 0 )
		     {
			     r = 1; c = 3; 
		     }

		     else if (choice.compare("b1")  == 0 )
		     {
			     r = 2; c = 1; 
		     }

		     else if (choice.compare("b2")  == 0 )
		     {
			     r = 2; c = 2; 
		     }

		     else if (choice.compare("b3")  == 0 )
		     {
			     r = 2; c = 3; 
		     }

		     else if (choice.compare("c1")  == 0 )
		     {
			     r = 3; c = 1; 
		     }

		     else if (choice.compare("c2")  == 0 )
		     {
			     r = 3; c = 2; 
		     }

		     else if (choice.compare("c3")  == 0 )
		     {
			     r = 3 ; c = 3; 
		     }
		     // Checks that slot option is calid and not taken	
		     if (board[r][c] != 'X' && board[r][c] != 'O')
		     {
			 board[r][c] = mark;
			 player = (player==1)? 2 : 1;
		     }
		     else 
		     {
			 cout << "Invalid Input. Please try again." << endl;
			 continue;
		     } 
		     result = checkwin();		     
	  }
	  while (result == -1);
	  player = (player==1)? 2 : 1;
	  drawBoard();
	  // counts player wins
	  if (result == 1)
	  {
	     cout << "player: "  << player << " Won!" << endl;
	     if (player == 1)
	     {
		 P1Count = P1Count + 1;
                 cout << "Player 1 (X) total win so far  - " << P1Count  << endl;
	     }
	     else
	     {
		 P2Count = P2Count + 1;
                 cout << "Player 2 (O) total win so far  - " << P2Count  << endl;
	     }

	  }
	  else
	  {

	     cout << "Draw!"  << endl;
	  }
	  //Asks user if they want to play again
	  cout << "Do you want to play again <Y/N>?" ;
	  cin >> repeatGame;
	  if (tolower(repeatGame) == 'y')
	  {
	     cleanBoard();
	  }
	  cin.ignore();

  }while(tolower(repeatGame) == 'y'); 
  
  cout << "Player 1 (X) wins - " << P1Count << " rounds" << endl;
  cout << "Player 2 (0) wins - " << P2Count << " rounds" << endl;
}

// checks if a player got a win
// return 0 = game is a draw, return 1 = game won, return -1 = game is still in progress. 
int checkwin()
{
  
  if (board[1][1] != ' ' && board[1][1] == board[1][2] && board[1][2] == board[1][3])
  {
    return 1;
  }
  else if (board[2][1] != ' ' && board[2][1] == board[2][2] && board[2][2] == board[2][3])
  {
    return 1;
  }
  else if (board[3][1] != ' ' && board[3][1] == board[3][2] && board[3][2] == board[3][3])
  {
    return 1;
  }
  else if (board[1][1] != ' ' && board[1][1] == board[2][1] && board[2][1] == board[3][1])
  {
    return 1;
  }
  else if (board[1][1] != ' ' && board[1][1] == board [2][2] && board [2][2] == board [3][3])
  {
    return 1;
  }
  else if (board[1][2] != ' ' && board[1][2] == board[2][2] && board[2][2] == board[3][2])
  {
    return 1;
  }
  else if (board[1][3] != ' ' && board[1][3] == board[2][3] && board[2][3] == board[3][3])
  {
    return 1;
  }
  else if (board[1][3] != ' ' && board[1][3] == board[2][2] && board[2][2] == board[3][1])
  {
    return 1;
  }
  if (isGameProgress() == true)
  {
    return -1;
  }
  else
  {
    return 0;	  
  }

}

// Cleans board after game
void cleanBoard()
{
   int i, j;
   for (i= 1; i<4; i++)
   {
     for(j=1; j<4; j++)
     {
	board[i][j] = ' ';
     }
   }
}

//draws the board
void drawBoard()
{
   int i, j;
   for (i= 0; i<4; i++)
   {
     for(j=0; j<4; j++)
     {  
	cout << board[i][j] <<  ' ';
        if (j != 3)
	{
	  cout << "|" ;
        }
       
     }

       	cout << endl;
   }
 }

//Checks if game is still in progress
bool isGameProgress()
{
   int i, j;
   for (i= 1; i<4; i++)
   {
     for(j=1; j<4; j++)
     {
	if (board[i][j] != 'X' && board[i][j] != 'O')
	{
  	   return true;
	}	
     }
   }
   return false;
}
