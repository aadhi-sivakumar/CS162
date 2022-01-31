/*
Name: Aadhi Sivakumar
Date: 1/30/22
Description: //Second part of Linked Lists, using code for node.h and node.o from Nihal Parthasarathy
*/

#include "Node.h"
#include <cstring>
#include <iomanip>
#include "Student.h"
using namespace std;

//Function Prototypes
void add(Node* curr, Node* next, Student* Student);
void print(Node* head);
void average(Node* head, int counter);
void Delete (Node* curr, Node* prev, int studID);
void displayMenu();

int main() 
{
  bool finish = false;
  char option[10];
  //declaring first head as NULL
  Node* head = NULL;
  //number of nodes in linked list
  int ctNode = 0; 

  do
	{
		displayMenu();
		cin.getline(option, 10);
	  
    // convert the input to upper case	
		for (int i=0; i < strlen(option); i++)
		{		
   			option[i] = toupper(option[i]);
		}	

		// options based on users input for option
		if (strcmp(option, "ADD") == 0)
		{
      

		}
		else if (strcmp(option, "PRINT") == 0)
		{
			
		}
		else if (strcmp(option, "DELETE") == 0)
		{

		}
		else if (strcmp(option, "QUIT") == 0)
		{
	
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
  cout << "AVERAGE--->Type 'AVERAGE' to print the GPA average of all students:" << endl;
}

void add(Node* curr, Node* next, Student* Student)
{
	Node* temp = new Node(Student);
    // find where it should go based on ID number
  if (next == NULL)
  {
    curr->setNext(temp);
  }
  else if (Student->getStudID < next->getStudent()->getStudID()) 
  {
    curr->setNext(temp);
    temp->setNext(next);
  }
  else 
  {
    add(next, next->getNext(), Student);
  }
}

void print(Node* head)
{
  Node* currNode = head;
  if (currNode == NULL) 
  {
      cout << "List is empty, you have to add students first to print" << endl;
    }
    else 
    {
      cout << "Printing students:" << endl;
      while (currNode != NULL) 
      {
        cout << currNode->getStudent()->getFirstName() << " ";
        cout << currNode->getStudent()->getLastName() << ", ";
        cout << "ID: " << currNode->getStudent()->getStudID() << ", ";
        cout << "GPA: " << fixed << setprecision(2) << currNode->getStudent()->getGPA() << endl;
        currNode = currNode->getNext();
        }
    }
}

void Delete (Node* curr, Node* prev, int studID)
{
  if (curr == NULL) 
  {
    // reached end of list
    cout << "There's no student with that ID. Nothing has been deleted." << endl;
  }
  else if (curr->getStudent()->getStudID() != studID) 
  {
    // check next student in list
    Delete(curr, curr->getNext(), studID);
  }
  else 
  {
    prev->setNext(curr->getNext());
    delete curr;
    cout << "Student deleted." << endl;
  }
}

void average(Node* head, int nodeCount)
{
  Node* current = head;
  float sum = 0;

  if (head == NULL) 
  { 
      cout << endl << "Cannot average 0 students GPA's, Student's have to be added first." << endl;
      return;
  }
  else 
  {
    sum += current->getStudent()->getGPA(); 
    while (current->getNext() != NULL) 
    { 
      sum += current->getNext()->getStudent()->getGPA();
      current = current->getNext();
    }
  }
  cout << "Average GPA: " << fixed << setprecision(2) << (sum/ nodeCount) << endl;
}