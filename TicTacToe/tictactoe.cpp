#include <iostream>
#include <string.h>
#include <string>
using namespace std;

char board[4][4] = {{' ', '1', '2', '3'},{'a',' ' ,' ' ,' '},{'b',' ' ,' ' ,' '},{'c',' ' ,' ' ,' '}};

void drawBoard();
int checkwin();
bool isGameProgress();

int main() 
{
   int player = 1;
   string choice;
   char mark;
   int r, c;
   do
   {  
     drawBoard();
     cout << "Player " << player << ", enter a slot: " << endl; 
     getline(cin, choice);
     mark = (player == 1) ? 'X' : 'O';

     if (choice.compare("a1")  == 0 )
     {
	  r = 1; c = 1; 
     }


     if (board[r][c] != 'X' && board[r][c] != '0')
     {
	 board[r][c] = mark;
	 player = (player==1)? 2 : 1;
     }
     else 
     {
	 cout << "Invalid Input. Please try again." << endl;
     	 cout << "Player " << player << ", enter an avaialable slot: ";
	 getline(cin, choice);
     }     
	
  }while (checkwin() != 1);
}

int checkwin()
{
  if (board[1][1] == board[1][2] && board[1][2] == board[1][3])
  {
    return 1;
  }
  else if (board[2][1] == board[2][2] && board[2][2] == board[2][3])
  {
    return 1;
  }
  else if (board[3][1] == board[3][2] && board[3][2] == board[3][3])
  {
    return 1;
  }
  else if (board[1][1] == board[2][1] && board[2][1] == board[3][1])
  {
    return 1;
  }
  else if (board[1][1] == board [2][2] && board [2][2] == board [3][3])
  {
    return 1;
  }
  else if (board[1][2] == board[2][2] && board[2][2] == board[3][2])
  {
    return 1;
  }
  else if (board[1][3] == board[2][3] && board[2][3] == board[3][3])
  {
    return 1;
  }
  else if (board[1][3] == board[2][2] && board[2][2] == board[3][1])
  {
    return 1;
  }
  else if (isGameProgress() == true)
  {
    return -1;
  }
  else
  {
    return 0;	  
  }
}

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
/*void placeMarker(int slot) 
{
  int row;
  int col;

  if(slot % 3 == 0)
  {
    row = row - 1;
    col = 2;
  }
  else
  {
    col = (slot % 3) - 1;
  }
  board[row][col] = marker;
}*/
