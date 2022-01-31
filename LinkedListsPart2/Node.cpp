#include <iostream>
#include "Node.h"
using namespace std;
Node::Node(Student* newstudent) {//Sets next to null and student to either s1 or s2
  next = NULL;
  student = newstudent;
}

Node* Node::getNext() {//Gets next
  return next;
}

Student* Node::getStudent() {//Gets the student
  return student;
}

void Node::setNext(Node* newnext) {//Sets next to newnext
  next = newnext;
}
Node::~Node() {//Sets next to null and deletes student pointer
  delete student;
  next = NULL;
}
