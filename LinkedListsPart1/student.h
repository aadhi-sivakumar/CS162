#include <iostream>
#include <cstring>
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
  private:
  //initializing variables
  char firstName[50];
  char lastName[50];
  int studID;
  float GPA;

  public:
  //function prototypes
  char* getFirstName();
  void setFirstName(const char* newFirst);
  char* getLastName();
  void setLastName(const char* newLast);
  int getStudID();
  void setStudID(int newID);
  float getGPA();
  void setGPA(float newGPA);
};
#endif
