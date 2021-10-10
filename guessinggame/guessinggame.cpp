//*********************************************************
//Author:       Aadhi Sivakumar
//Assignment:   Guessing Game
//Date:         9/19/2021
//Description:  The program will randomly generate a number between 0 and 100, inclusive. The program will prompt the user to guess a number. will tell you if it is too high, too low, or correct. If it is correct, it will display how many guesses it took you, and ask if you want to play again.
//Input: user's guess an the charcter 'y' or 'n' to play again    
//Output: if the guess was too high, low, or correct and the number of trys to guess the number
//Sources: none
//***********************************************************

#include <iostream>
#include <ctime>
#include <ctype.h>

using namespace std;

int main() 
{
 int computerNum,tries = 0;
 int guess = 0;
 char playAgain = 'y';

// creates a random number
 srand(time(0));
 // variable that holds a random number between 1-100.
 computerNum = rand() % 100 + 1;

// welcome message
  cout << "Welcome to my Guessing Game!" << endl << endl;

// loops when the first time and when the user wants to play again.
 while (tolower(playAgain) == 'y')
 {
   cout << "Enter a guess between 1 and 100: ";
   cin >> guess;
   tries++;

  // answer for code from Stack Overflow for the cin.clear and cin.ignore components, user: Ryan Hallberg
  // https://stackoverflow.com/questions/11523569/how-can-i-avoid-char-input-for-an-int-variable
  // loop that accounts for non-integer guesses
   if (cin.fail())
   {
     cout << "Invalid guess. Enter a numeric value between 1-100. " << endl << endl;
     cin.clear();
     cin.ignore();
   }
   // loop that accounts for interger guesses not in the range of the computer number's random number.
   else if (guess > 100 || guess < 1)
   {
      cout << "Invalid guess. You have to enter a number between 1-100" << endl << endl;
   }
   else if (guess > computerNum)
   {
     cout << "The number you guessed was too high. Try again." << endl << endl;
   }
   else if (guess < computerNum)
   {
     cout << "The number you guessed is too low. Try again." << endl << endl;
   }
   else
   {
     cout << "The number you guessed is correct. You guessed the number in " << tries << " tries." << endl << endl;
     cout << "Do you want to play again y/n?";
     cin >> playAgain;
     // reset the random number
     srand(time(0));
     computerNum = rand() % 100 + 1;
     // reset number of tries
     tries = 0;

   }
   if (playAgain == 'n')
   {
     cout << endl << "Thanks for playing!";
   }
 }

}
