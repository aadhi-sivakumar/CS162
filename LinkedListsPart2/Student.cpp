#include "Student.h"
#include <cstring>

//constructor
Student::~Student() 
{

}

//sets student's information
Student::Student(char* newFirstName, char* newLastName, int newStudID, float newStudGPA) 
{
  firstName = new char[50];
  strcpy(firstName, newFirstName);
  lastName = new char[50];
  strcpy(lastName, newLastName);
  studID = newStudID;
  studGPA = newStudGPA;
}

//gets first name of student
char* Student::getFirstName() 
{
  return firstName;
}

//gets last name of student
char* Student::getLastName() 
{
  return lastName;
}

//gets student ID
int Student::getStudID() 
{
  return studID;
}

//gets students GPA
float Student::getGPA() 
{
  return studGPA;
}
