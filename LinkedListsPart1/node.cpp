#include "student.h"
#include "node.h"

Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

Node::~Node()
{
  delete &student;
  next = NULL;
}

Student* Node::getStudent()
{
  return student;
}
Node* Node::getNext()
{
  return next;
}
void Node::setNext(Node* nextNode)
{
  nextNode = nextNode;
}
