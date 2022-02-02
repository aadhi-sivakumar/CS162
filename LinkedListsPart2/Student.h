#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

class Student 
{
 public:
  ~Student();
  Student(char* newFirstName, char* newLastName, int newStudID, float newStudGPA);
  char* getFirstName();
  char* getLastName();
  int getStudID();
  float getGPA();
  float studGPA;
  
 private:
  char* firstName;
  char* lastName;
  int studID;
};
#endif