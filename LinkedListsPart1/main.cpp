/*
Name: Aadhi Sivakumar
Date: 1/16/2021
Description: Practicing Linked Lists and prints out elements of linked list to show it works
*/

#include "node.h"
#include "student.h"

//creating head node
Node* head = NULL;

void add(Student* newStudent);
void print(Node* next);
int main() 
{
 //making the students
 Student* Aadhi = new Student();
 Aadhi->setFirstName("Aadhi");
 Aadhi->setLastName("Sivakumar");
 Aadhi->setStudID(468615);
 Aadhi->setGPA(4.5);
 add(Aadhi);
 print(head);
 Student* Jose = new Student();
 Jose->setFirstName("Jose");
 Jose->setLastName("Martinez");
 Jose->setStudID(432657);
 Jose->setGPA(1.0);
 add(Jose);
 print(head);
 Student* Martin = new Student();
 Martin->setFirstName("Martin");
 Martin->setLastName("Luther");
 Martin->setStudID(456789);
 Martin->setGPA(2.5);
 add(Martin);
 print(head);
}

void add(Student* newStudent)
{
  Node* current = head;
  if(current == NULL) 
  {
    head = new Node(newStudent);
  }
  else
  {
    while(current->getNext() != NULL)
    {
      current = current->getNext();
    }
    current->setNext(new Node(newStudent));
  }
}

void print(Node* next)
{
  if(next == head)
  {
    cout << "List: " << endl;
  }
  if(next != NULL)
  {
    cout << next->getStudent()->getFirstName() << " " << next->getStudent()->getLastName() << " " << next->getStudent()->getStudID() << " " << next->getStudent()->getGPA() << endl;
    print(next->getNext());
  }
}
