#include <iostream>
#include <map>
#include <iterator>
#include <cstring>
#include <vector>
#include "room.h"

using namespace std;

void printWelcome();

int main()
{
  char noYes[5];

  //welcome message
  printWelcome();

  //confirmation if you want to play or not
  cin >> noYes;

 //exits game if user doesn't want to play
  if (strcmp(noYes, "no") == 0)
  {
    cout << "Bad Idea. Your parents are going to be mad." << endl;
    cout << "Exiting Zuul: School Edition." << endl;
    exit(0);
  }
  //initializes game if user wants to play
  else if (strcmp(noYes, "yes") == 0)
  {
    //room initialization
    room* english = new room();
    english->setName((char*)"English Class");
    english->setDescription((char*)"It's your least favorite class cause you got caught cheating");
    room* cafeteria = new room();
    cafeteria->setName((char*)"Cafeteria");
    cafeteria->addItem((char*)"lunchbox");
    cafeteria->setDescription((char*)"Place where you eat lunch");
    room* history = new room();
    history->setName((char*)"History Class");
    history->setDescription((char*)"Class where you learn historical events");
    room* math = new room();
    math->setName((char*)"Math Class");
    math->addItem((char*)"calculator");
    math->setDescription((char*)"Most confusing class");
    room* robotics = new room();
    robotics->setName((char*)"Robotics class");
    robotics->setDescription((char*)"This is your favorite class");
    room* theatre = new room();
    theatre->setName((char*)"Theatre");
    theatre->setDescription((char*)"Place where people perform");
    theatre->addItem((char*)"microphone");
    room* office = new room();
    office->setName((char*)"Principals office");
    office->setDescription((char*)"You do not want to end up here");
    room* science = new room();
    science->setName((char*)"Science Class");
    science->addItem((char*)"beaker");
    science->setDescription((char*)"Class where you mix chemicals together");
    room* gym = new room();
    gym->setName((char*)"Gym");
    gym->setDescription((char*)"Exercise Place");
    room* compLab = new room();
    compLab->setName((char*)"Computer Lab");
    compLab->setDescription((char*)"Coding Area");
    room* spanish = new room();
    spanish->setName((char*)"Spanish Class");
    spanish->setDescription((char*)"Learn Spanish Here");
    room* health = new room();
    health->setName((char*)"health class");
    health->setDescription((char*)"Health");
    room* band = new room();
    band->setName((char*)"Band Class");
    band->addItem((char*)"instrument");
    band->setDescription((char*)"Class where I play my clarinet");
    room* french = new room();
    french->setName((char*)"French Class");
    french->setDescription((char*)"People's least facorite class");
    room* counsler = new room();
    counsler->setName((char*)"Counsling Office");
    counsler->setDescription((char*)"Place where you can talk about your problems");

    //exit iniatization
    english->setExit("NORTH", math);
    english->setExit("SOUTH", science);
    english->setExit("EAST", theatre);
    english->setExit("WEST", cafeteria);
    cafeteria->setExit("NORTH", history);
    cafeteria->setExit("SOUTH", gym);
    cafeteria->setExit("EAST", english);
    history->setExit("SOUTH", cafeteria);
    history->setExit("EAST", math);
    math->setExit("SOUTH", english);
    math->setExit("EAST", robotics);
    math->setExit("WEST", history);
    robotics->setExit("SOUTH", theatre);
    robotics->setExit("WEST", math);
    theatre->setExit("NORTH", robotics);
    theatre->setExit("SOUTH", office);
    theatre->setExit("WEST", english);
    office->setExit("NORTH", theatre);
    office->setExit("SOUTH", health);
    office->setExit("WEST", science);
    science->setExit("NORTH", english);
    science->setExit("SOUTH", spanish);
    science->setExit("EAST",office);
    science->setExit("WEST", gym);
    gym->setExit("NORTH", cafeteria);
    gym->setExit("SOUTH", compLab);
    gym->setExit("EAST", science);
    compLab->setExit("NORTH", gym);
    compLab->setExit("SOUTH", counsler);
    compLab->setExit("WEST", spanish);
    spanish->setExit("NORTH", science);
    spanish->setExit("SOUTH", french);
    spanish->setExit("EAST", health);
    spanish->setExit("WEST", compLab);
    health->setExit("NORTH", office);
    health->setExit("SOUTH", band);
    health->setExit("WEST", spanish);
    band->setExit("NORTH", health);
    band->setExit("WEST", french);
    french->setExit("NORTH", spanish);
    french->setExit("EAST", band);
    french->setExit("WEST", counsler);
    counsler->setExit("NORTH", compLab);
    counsler->setExit("EAST", french);

    //setting starting room to english classroom.
    room* currentRoom = english;

  
    bool keepGoing = true;
    vector<char*> inventory;
    char nextDir[80];
    while(keepGoing)
    {//keep going while the user hasn't quit or won the game

      //print the room and items in the room
      cout << "You are in: " << currentRoom->getName() << endl;
      cout << "Items in the room: ";
      for(vector<char*>::iterator it = currentRoom->getItems()->begin();it < currentRoom->getItems()->end();it++)
      {//loop through the items in the current room and print them
        cout << (*it) << " " << endl;
      }
      cout << currentRoom->getDescription() << endl;//print the description
      int curPos = -1;
      
      for(vector<char*>::iterator it = currentRoom->getItems()->begin();it < currentRoom->getItems()->end();it++)
      {//loop through the items in the room and ask if they would like to pick it up
        curPos++;
        char answer[80];
        cout << "would you like to pick up: " << (*it) << "(Y/N)" << endl;
        cin >> answer;
        if(strcmp(answer, "Y") == 0)
        {//put it in the inventory and remove it from the room
          inventory.push_back((*it));
                currentRoom->getItems()->erase(it);
          break;
        }
        else if(strcmp(answer, "N") == 0)
        {
          continue;
        }
        else
        {
          cout << "That is not a valid command, make sure you typed 'Y' or 'N'" << endl;
          cout << "Leave the room and come back to attempt to pick it up again" << endl;
        }
      }

      if(inventory.size() == 5)
      {//win condition
      cout << "Good job on finding all of your missing school supplies!" << endl;
        cout << "Congratulations you have won Zuul: School Edition" << endl;
        break;
      }
      if(inventory.size() > 0)
      {//checking if the user would like to drop their items
       
      }
      //printing out the exits of the room
      cout << "Exits are: " << endl;
      for(map<const char*, room*>::iterator it  = currentRoom->getMap()->begin(); it != currentRoom->getMap()->end(); it++)
      {
        cout <<it->first << ", " << it->second->getName() << endl;
      }
      cout << "you can type QUIT to quit as well" << endl;
      cout << "Which direction would you like to go in?" << endl;
      cin >> nextDir;
      //prompt the user for what direction they'd like to go in or if they'd like to quit
      for(map<const char*, room*>::iterator it = currentRoom->getMap()->begin(); it != currentRoom->getMap()->end(); it++)
      {
        if(strcmp(it->first, nextDir) == 0)
        {
          currentRoom = it->second;
          break;
        }
      }
      if(strcmp(nextDir, "QUIT") == 0)
      {
        keepGoing = false;
        cout << "Your parent's will not be happy about this" << endl;
        cout << "Exiting Zuul: School Edition" << endl;
      }
  } 
  }
  return 0;
}
void printWelcome()
{
  cout << "Welcome to Zuul, an adventure game where you must collect items scattered through over a dozen rooms!" << endl << endl;
  cout << "You are located at Sunset High School's english class waiting for the bell to ring. The time finally comes when it does." << endl;
  cout << "You are about to head home when you realize you've lost five of your school supplies. Your parents will kill you if they figure out you lost them." << endl;
  cout << "It's your task to navigate through the 15 classrooms to find these school supplies, or you will be grounded once you come home." << endl;
  cout << "The school supplies you are searching for are: a calculator, a beaker, a lunchbox, a instument, a lunch box, and finally a lunch box." << endl;
  cout << "Are you planning on finding your missing school supplies?" << endl;
}