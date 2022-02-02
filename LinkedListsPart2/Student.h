#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student 
{
 public:
//constructor
  ~Student();
  //function prottypes
  Student(char* newFirstName, char* newLastName, int newStudID, float newStudGPA);
  char* getFirstName();
  char* getLastName();
  int getStudID();
  float getGPA();
  float studGPA;
  
 private:
  //initialization
  char* firstName;
  char* lastName;
  int studID;
};
#endif
