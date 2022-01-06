#include "room.h"

using namespace std;

//initializing all the room functions 
char* room::getName()
{//returns the name of a room
  return name;
}

void room::setName(char* newName)
{//sets the name of the room
  strcpy(name, newName);
}

vector<char*>* room::getItems()
{//returns a vector of items for a room
  return &items;
}

void room::addItem(char* itemName)
{//adds items to a room
  items.push_back(itemName);
}

char* room::getDescription()
{//returns the description
  return description;
}

void room::setDescription(char* newDesc)
{//sets the description of a room
  strcpy(description, newDesc);
}

map<const char*, room*>* room::getMap()
{//returns the exits of a room
  return &exits;
}

void room::setExit(const char* direction, room* newRoom){//adds an exit to a room
  exits.insert(pair<const char*, room*>(direction, newRoom));
}