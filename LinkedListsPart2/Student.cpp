#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

Student::Student() 
{

}

//Destructor
Student::~Student() 
{ 
	
}

//Takes in onformation
char* Student::getFirstName() {
	return firstName;
}

char* Student::getLastName() {
	return lastName;
}

int Student::getStudID()
{
	return studID;
}

float Student::getGPA() {
	return GPA;
}

void Student::setInfo() {

}
