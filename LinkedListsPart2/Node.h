//Nihal Parthasarathy
//1/12/2022
//This code shows that the Node.cpp and the Node.h file work


//Defitions
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
using namespace std;
class Node {//Node class
public:
  //Declerations
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newNext);
  Node(Student*);
  
private:
  Student* student;
  Node* next;
  
};

#endif