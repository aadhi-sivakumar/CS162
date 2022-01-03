#include <iostream>
#include <cstring>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class room
{
  private:
    char roomName[50];
    //string that describes the room
    char roomDescription[200]; 
    //stores exits of this room
    map <const char*, room*> exits;
    vector <char*> items;

  public:
    char* getName();
    void setName(char* newName);
    vector <char*>* getItems();
    void addItem(char* itemName);
    char* getRoomDescription();
    void setRoomDescription(char* newDescription);
    map<const char*, room*>* getMap();
    void setExit(const char* direction, room* newRoom);
    
};
#endif