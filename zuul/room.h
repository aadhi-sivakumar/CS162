#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>

#ifndef ROOM_H
#define ROOM_H

using namespace std;

class room
{
 private:
  //room variables
  char description[100];
  char name[20];
  map<const char*, room*> exits;
  vector<char*> items;

 public:
  //function prototypes
  char* getName();
  void setName(char* newName);
  vector<char*>* getItems();
  void addItem(char* itemName);
  char* getDescription();
  void setDescription(char* newDescription);
  map<const char*, room*>* getMap();
  void setExit(const char* direction, room* neighbor);
};
#endif

