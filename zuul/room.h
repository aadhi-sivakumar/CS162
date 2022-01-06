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
 public:
  //function prototypes
  char* getName();
  void setName(char* newName);
  vector<char*>* getItems();
  void addItem(char* itemName);
  char* getDescription();
  void setDescription(char* newDesc);
  map<const char*, room*>* getMap();
  void setExit(const char* direction, room* newRoom);
 private:
  //room variables
  map<const char*, room*> exits;
  char name[80];
  vector<char*> items;
  char description[1000];
};
#endif

