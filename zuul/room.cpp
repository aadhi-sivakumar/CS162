#include "room.h"
using namespace std;

char* room::getName()
{
  return roomName;
}
void room::setName(char* newName)
{
  strcpy(roomName,newName);
}
vector<char*>* room::getItems()
{
  return &items;
}
void room::addItem(char* itemName)
{
  items.push_back(itemName);
}
char* room::getRoomDescription()
{
  return roomDescription;
}
void room::setRoomDescription(char* newDescription)
{
  strcpy(roomDescription, newDescription);
}
map<const char*, room*>* room::getMap()
{
  return &exits;
}
void room::setExit(const char* direction, room* newRoom)
{
  exits.insert(pair<const char*, room*>(direction, newRoom));
}

  