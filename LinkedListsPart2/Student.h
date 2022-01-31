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
  Student();
  ~Student();
  char* getFirstName();
  char* getLastName();
  int getStudID();
  float getGPA();
  void setInfo();
};
#endif