#include "room.h"
using namespace std;

//gets room name
char* room::getName()
{
  return name;
}

//sets the room name
void room::setName(char* newName)
{
  strcpy(name, newName);
}

//returns the vector of items for the room
vector<char*>* room::getItems()
{
  return &items;
}

//adds items to the room
void room::addItem(char* itemName)
{
  items.push_back(itemName);
}

//returns the description
char* room::getDescription()
{
  return description;
}

//sets the room description
void room::setDescription(char* newDescription)
{
  strcpy(description, newDescription);
}

//returns the exits of a room based on map
map<const char*, room*>* room::getMap()
{
  return &exits;
}
///adds exits to room
void room::setExit(const char* direction, room* neighbor)
{
  exits.insert(pair<const char*, room*>(direction, neighbor));
}