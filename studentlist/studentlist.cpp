//**********************************************
//Author:	Aadhi Sivakumar
//Assignment: 	Student List
//Date:		11/7/2021
//Description; This will have a vector of students in which the user can add students, print the vector, delete a student by typing the id number, and quit the program by typing an option from the display menu.
//Sources: My dad helped me with part of the logic of the delete function. 
//***********************************************
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <vector>
using namespace std;

struct student
{	
	char firstName[50];
	char lastName[50];
	int studID;
	float GPA;
};
void add(vector<student> &v1);
void print(vector<student> &v1);
void del(vector<student> &v1);
void displayMenu();

int main()
{
	
	vector <student> v1;
	char option[10];
        do
	{
		displayMenu();
		cin.getline(option, 50);
	        // convert the input to upper case	
		for (int i=0; i < strlen(option); i++)
		{		
   			option[i] = toupper(option[i]);
		}	
		// options based on users input for option
		if (strcmp(option, "ADD") == 0)
		{
			add(v1);
			cin.ignore();
		}
		else if (strcmp(option, "PRINT") == 0)
		{
			print(v1);
		}
		else if (strcmp(option, "DELETE") == 0)
		{
		        del(v1);
			cin.ignore();
		}
		else if (strcmp(option, "QUIT") == 0)
		{
		   break;
		}
		else
		{
		   cout << "Invalid Input, please enter a valid option" << endl; 
		}

	}
	while(strcmp(option, "QUIT") != 0);
	return 0;				
}
// displays options user can do
void displayMenu()
{
        cout << endl; 
	cout << "Select an option:" << endl << endl; 
	cout << "ADD--->Type 'ADD' to add a new student record: " << endl;
        cout << "PRINT--->Type 'PRINT' to print out all the students currently stored: " << endl;
	cout << "DELETE--->Type 'DELETE' to delete a student ID number from the record: " << endl;
	cout << "QUIT--->Type 'QUIT' to exit the program: " << endl;
}

// option if user wants to add student record
void add(vector<student> &v1)
{
	
	student st; 

	cout << endl;

	cout << "Enter Entry for student" << endl;
	cout << "Enter student's first name" << endl;
	cin.getline(st.firstName,50);
	cout << "Enter student's last name" << endl;
	cin.getline(st.lastName, 50);
	cout << "Enter student's ID" << endl;
	cin >> st.studID;
	cout << "Enter student's GPA" << endl;
	cin >> st.GPA;
	v1.push_back(st);
}
// prints the vector of students
void print(vector<student> &v1)
{	
	student st;

	for (int i = 0; i < v1.size(); i++)
	{
		st = v1[i];
		cout << st.firstName << ", " << st.lastName << ", " << fixed << setprecision(2) << st.studID << ", " << st.GPA << endl;
	}

}
//deletes the student struct given id number
void del(vector<student> &v1)
{
	student st;
        bool del = false;
        int idToDelete;
        int pos = 0;  
        cout << endl;
	cout << "Enter student ID number to delete from the records: " << endl;
	cin >> idToDelete;
	
	for (int i = 0; i < v1.size(); i++)
	{
		st = v1[i];
		if (st.studID == idToDelete)
		{
			v1.erase(v1.begin() + i);
			del = true;
		}
	}
	if (del != true)
	{
		cout << "Entered Student Id not found!"; 
	}
	else
	{
		cout << "Student record for ID = " << idToDelete << " is successfuly deleted";
	}
}

