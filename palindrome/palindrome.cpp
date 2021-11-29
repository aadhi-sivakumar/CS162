//*********************************************************
//Author:       Aadhi Sivakumar
//Assignment:   Palindrome
//Date:         10/10/2021
//Description:  This program will read in an array of up to 80 charcters and remove the spaces and punctuation. It will then check to see if the input is the same backwards as it is forwards. If it is a palindrome, it will print "Palindrome. If not, it will print "Not a palindrome."
//Input: palindromeArr
//Output:isPalindrome
//Sources: none
//***********************************************************

#include <iostream>
#include<cstring>
#include<ctype.h>
using namespace std;

const int CAP = 80;

int main() 
{
 //declaration of variables

 char palindromeArr[CAP];
 char palindromeArr2[CAP];
 int k = 0;
 // prompt the user for the input
 cout << "Enter a word/phrase 1-80 chacters to determine if it is a palindrome or not." << endl;
 cin.getline(palindromeArr, CAP);
 
 //remove all spaces and punction from input and copy the result to new array
 for (int i = 0; i <= strlen(palindromeArr) - 1; i++)
 {
 
   if ((tolower(palindromeArr[i]) != ' ' ) && (ispunct(tolower(palindromeArr[i]))== 0))
   {
     palindromeArr2[k] = tolower(palindromeArr[i]);
     k++;
   }
 }
 palindromeArr2[k] = '\0';

 //Find the length after removing spaces and punction
 int length = strlen(palindromeArr2);

 //Find the middle point 
 int midpoint = length / 2;

 //palindrome or not variable
 bool ispalindrome = true;

 //check whether the input is polidrom or not by comparing the character from the begining and from the end until the middle point

 //index to traverse the string from end 
 int y = length - 1;
 for (int x = 0; x < midpoint; x++)
 {

   if (palindromeArr2[x] != palindromeArr2[y])
   {
     ispalindrome = false;
     break;
   }
   y--;
 }

  if (ispalindrome)
  {
    cout << "Palindrome." << endl;
  }
  else
  {
    cout << "Not a palindrome." << endl;
  }
  return 0; 

}
