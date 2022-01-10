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
 Aadhi->setLastName("Martinez");
 Aadhi->setStudID(432657);
 Aadhi->setGPA(1.0);
 add(Jose);
 print(head);
 Student* Martin = new Student();
 Aadhi->setFirstName("Martin");
 Aadhi->setLastName("Luther");
 Aadhi->setStudID(456789);
 Aadhi->setGPA(2.5);
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
