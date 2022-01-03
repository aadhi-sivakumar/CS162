#include "room.h"
using namespace std;

//function protypes
void printWelcome();
void printHelp();

int main() 
{
  //introduction of game
  printWelcome();

//room initialization
  room* english = new room();
  english->setName((char*)"English Class");
  english->setRoomDescription((char*)"It's your least favorite class cause you got caught cheating");
  room* cafeteria = new room();
  cafeteria->setName((char*)"Cafeteria");
  cafeteria->addItem((char*)"lunchbox");
  cafeteria->setRoomDescription((char*)"Place where you eat lunch");
  room* history = new room();
  history->setName((char*)"History Class");
  history->setRoomDescription((char*)"Class where you learn historical events");
  room* math = new room();
  math->setName((char*)"Math Class");
  math->addItem((char*)"calculator");
  math->setRoomDescription((char*)"Most confusing class");
  room* robotics = new room();
  robotics->setName((char*)"Robotics class");
  robotics->setRoomDescription((char*)"This is your favorite class");
  room* theatre = new room();
  theatre->setName((char*)"Theatre");
  theatre->setRoomDescription((char*)"Place where people perform");
  room* office = new room();
  office->setName((char*)"Principals office");
  office->setRoomDescription((char*)"You do not want to end up here");
  room* science = new room();
  science->setName((char*)"Science Class");
  science->addItem((char*)"beaker");
  science->setRoomDescription((char*)"Class where you mix chemicals together");
  room* gym = new room();
  gym->setName((char*)"Gym");
  gym->setRoomDescription((char*)"Exercise Place");
  room* compLab = new room();
  compLab->setName((char*)"Computer Lab");
  compLab->setRoomDescription((char*)"Coding Area");
  room* spanish = new room();
  spanish->setName((char*)"Spanish Class");
  spanish->setRoomDescription((char*)"Learn Spanish Here");
  room* health = new room();
  health->setName((char*)"health class");
  health->setRoomDescription((char*)"Health");
  room* band = new room();
  band->setName((char*)"Band Class");
  band->addItem((char*)"instrument");
  band->setRoomDescription((char*)"Class where I play my clarinet");
  room* french = new room();
  french->setName((char*)"French Class");
  french->setRoomDescription((char*)"People's least facorite class");
  room* counsler = new room();
  counsler->setName((char*)"Counsling Office");
  counsler->setRoomDescription((char*)"Place where you can talk about your problems");

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
  theatre->setExit("EAST", english);
  office->setExit("NORTH", theatre);
  office->setExit("SOUTH", health);
  office->setExit("WEST", science);
  science->setExit("NORTH", english);
  science->setExit("NORTH", english);
  science->setExit("SOUTH", spanish);
  science->setExit("EAST",office);
  science->setExit("WEST", gym);
  gym->setExit("NORTH", cafeteria);
  gym->setExit("SOUTH", compLab);
  gym->setExit("EAST", spanish);
  compLab->setExit("NORTH", gym);
  compLab->setExit("SOUTH", counsler);
  compLab->setExit("WEST", spanish);
  spanish->setExit("NORTH", science);
  spanish->setExit("SOUTH", french);
  spanish->setExit("EAST", compLab);
  spanish->setExit("WEST", health);
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
 
 room* currentRoom = english;
 bool win = false;
 vector<char*> inventory;
 char command[25];

  while(!win)
  {
    cout << "The room you are in is " << currentRoom->getName() << endl;
    cout << "The items located in the room are: ";
    for(vector<char*>::iterator itr = currentRoom->getItems()->begin();itr < currentRoom->getItems()->end();itr++)
    {
      cout << (*itr) << " , ";
    }
    cout << endl;
    cout << currentRoom->getRoomDescription() << endl;
    int currPos = -1;
    
    for(vector<char*>::iterator itr = currentRoom->getItems()->begin();itr < currentRoom->getItems()->end();itr++)
    {
      currPos++;
      char answer[15];
      cout << "Would you like to pick up the item: " << (*itr) << " (Y/N)" << endl;
      cin >> answer;
      if(strcmp(answer, "Y") == 0)
      {//put it in the inventory and remove it from the room
	      inventory.push_back((*itr));
        currentRoom->getItems()->erase(itr);
	      break;
      }
      else if(strcmp(answer, "N") == 0)
      {
	      continue;
      }
      else
      {
        cout << "That is not a valid option. Please make sure you typed 'Y' or 'N'" << endl;
      }
    }
    if(inventory.size() == 5)
    {//win condition
      cout << "Congratulations! You have found all your school supplies scattered throughout the school. You can now return home without your parents being angry." << endl;
      cout << "You've won Zuul: School Edition. Thanks for playing!" << endl;
      break;
    }
    if(inventory.size() > 0)
    {//checking if the user would like to drop their items
      char drop[25];
      currPos = -1;
      for(vector<char*>::iterator itr = inventory.begin(); itr != inventory.end(); itr++)
      {
        currPos++;
        cout << "Would you like to drop your"  << *itr << "(Y/N)" << endl;
        cin>> drop;
        if(strcmp(drop, "Y") == 0){
          currentRoom->getItems()->push_back(*itr);
          inventory.erase(itr);
          break;
	    }
      else if(strcmp(drop, "N") == 0)
      {
	      continue;
	    }
      else
      {
	      cout << "That is not a valid option. Please make sure you type 'Y' or 'N'" << endl;
	    }
    }
    cout << "Exits are: " << endl;
    for(map<const char*, room*>::iterator itr  = currentRoom->getMap()->begin(); itr != currentRoom->getMap()->end(); itr++){
      cout <<itr->first << ", " << itr->second->getName() << endl;
    }
    cout << "You can Type 'quit' to quit the game" << endl;
    cout << "Which direction would you like to go?" << endl;
    cin >> command;
    //prompt the user for what direction they'd like to go in or if they'd like to quit
    for(map<const char*, room*>::iterator itr = currentRoom->getMap()->begin(); itr != currentRoom->getMap()->end(); itr++){
      if(strcmp(itr->first, command) == 0){
	currentRoom = itr->second;
	break;
      }
    }
    if(strcmp(command, "HELP") == 0)
    {
      printHelp();
    }
    if(strcmp(command, "QUIT") == 0)
    {
      win = true;
      cout << "Quitting Zuul: School Edition." << endl;
      break;
    }
  }
  return 0;
  }
}


void printWelcome()
{
  cout << "Welcome to Zuul: School Version" << endl << endl;
  cout << "You have been caught plagarizing your english essay by your teacher. You spent the last three hours redoing your english essay and finally complete it." << endl;
  cout << "You are about to head home after turning it in until the thought shocks you. You realize you've lost all your school supplies. Your parents will kill you if they figure out you lost them." << endl;
  cout << "It's your task to navigate through the 15 classrooms to find these school supplies, or you will be grounded once you come home." << endl;
}

void printHelp()
{
  cout << "This is the help center" << endl;
  cout << "Type: go or quit" << endl;
}