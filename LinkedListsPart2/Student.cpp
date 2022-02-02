#include "Student.h"
#include <cstring>

Student::~Student() 
{

}

Student::Student(char* newFirstName, char* newLastName, int newStudID, float newStudGPA) 
{
  firstName = new char[50];
  strcpy(firstName, newFirstName);
  lastName = new char[50];
  strcpy(lastName, newLastName);
  studID = newStudID;
  studGPA = newStudGPA;
}

char* Student::getFirstName() 
{
  return firstName;
}

char* Student::getLastName() 
{
  return lastName;
}

int Student::getStudID() 
{
  return studID;
}

float Student::getGPA() 
{
  return studGPA;
}