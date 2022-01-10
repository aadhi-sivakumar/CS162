#include "student.h"

char* Student::getFirstName()
{
  //returns the first name of a student
  return firstName;
}

void Student::setFirstName(const char* newFirst)
{
  //sets the first name of a student
  strcpy(firstName, newFirst);
}

char* Student::getLastName()
{
  //returns the last name of a student
  return lastName;
}

void Student::setLastName(const char *newLast)
{
  //sets the last name of a student
  strcpy(lastName, newLast);
}

int Student::getStudID()
{
  //return student's ID
  return studID;
}

void Student::setStudID(int newID)
{
  //sets the student ID
  studID = newID;
}

float Student::getGPA()
{
  //returns the student's GPA
  return GPA;
}

void Student::setGPA(float newGPA)
{
  //sets the student's GPA
  GPA = newGPA;
}