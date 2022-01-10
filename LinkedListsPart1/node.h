#include "student.h"

#ifndef NODE_H
#define NODE_H

class Node 
{
  private:
    Student* student;
    Node* next;

  public:
    ~Node();
    Node(Student*);
    Student* getStudent();
    Node* getNext();
    void setNext(Node*);    
};
#endif