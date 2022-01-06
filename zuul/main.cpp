/*
Map of Zuul Can be found here: https://github.com/aadhisivakumar/CS162/blob/main/zuul/IMG_8951.jpg
Sources: Aaron and my dad helped me with the map and the looping within the map along with the website: https://www.geeksforgeeks.org/map-associative-containers-the-c-standard-template-library-stl/. Dad also helped me with the convertToUpper function.
*/

#include "room.h"

using namespace std;

void printWelcome();
char* convertToUpper(char* str);
int main()
{
  char noYes[5];
  int i;
  bool notFinished = true;
  vector<char*> inventory;
  char command[20];
  int curPos = -1;
  char response[2];

  //welcome message
  printWelcome();

  //confirmation if you want to play or not
  cin >> noYes;

 //exits game if user doesn't want to play
  if (strcmp(convertToUpper(noYes), "NO") == 0)
  {
    cout << "Bad Idea. Your parents are going to be mad." << endl;
    cout << "Exiting Zuul: School Edition." << endl;
    exit(0);
  }
  //initializes game if user wants to play
  else if (strcmp(convertToUpper(noYes), "YES") == 0)
  {
    //room initialization
    room* english = new room();
    english->setName((char*)"English Class");
    english->setDescription((char*)"This is your least favorite class because you were caught plagarizing.");
    room* cafeteria = new room();
    cafeteria->setName((char*)"Cafeteria");
    cafeteria->addItem((char*)"lunchbox");
    cafeteria->setDescription((char*)"This is your favorite time because you get to eat lunch.");
    room* history = new room();
    history->setName((char*)"History Class");
    history->setDescription((char*)"This is the class where you learn historical events");
    room* math = new room();
    math->setName((char*)"Math Class");
    math->addItem((char*)"calculator");
    math->setDescription((char*)"This is your most confusing class. Numbers...");
    room* robotics = new room();
    robotics->setName((char*)"Robotics class");
    robotics->setDescription((char*)"This is your favorite class because you get to build robots!");
    room* theatre = new room();
    theatre->setName((char*)"Theatre");
    theatre->setDescription((char*)"This is the place where people perform:)");
    theatre->addItem((char*)"microphone");
    room* office = new room();
    office->setName((char*)"Principals office");
    office->setDescription((char*)"You do not want to end up here");
    room* science = new room();
    science->setName((char*)"Science Class");
    science->addItem((char*)"beaker");
    science->setDescription((char*)"This is the class where you mix chemicals together");
    room* gym = new room();
    gym->setName((char*)"Gym");
    gym->setDescription((char*)"Exercise Place");
    room* compLab = new room();
    compLab->setName((char*)"Computer Lab");
    compLab->setDescription((char*)"Coding Area");
    room* spanish = new room();
    spanish->setName((char*)"Spanish Class");
    spanish->setDescription((char*)"This is the class where you learn spanish");
    room* health = new room();
    health->setName((char*)"Health Class");
    health->setDescription((char*)"You dispise this class because you think it's gross");
    room* band = new room();
    band->setName((char*)"Band Class");
    band->addItem((char*)"instrument");
    band->setDescription((char*)"This is the class where you play your clarinet");
    room* french = new room();
    french->setName((char*)"French Class");
    french->setDescription((char*)"People's least favorite class");
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

   //keep looping while the user hasn't quit the game or won
    while(notFinished)
    {

      //print the room you are located in and the items in the room
      cout << endl << "You are located in: " << currentRoom->getName() << endl;

      //loop through the items in the current room and print them
      for(vector<char*>::iterator it = currentRoom->getItems()->begin();it < currentRoom->getItems()->end();it++)
      {
        cout << "The item in the room is a: ";
        cout << (*it) << " " << endl;
      }
      cout << "Room Description: " << currentRoom->getDescription() << endl;

      //loop through the items in the room and asks the use if they would like to pick it up
      for(vector<char*>::iterator it = currentRoom->getItems()->begin();it < currentRoom->getItems()->end();it++)
      {
        curPos++;
        cout << "Would you like to pick up the " << (*it) << "? (Y/N)" << endl;
        cin >> response;
        if(strcmp(convertToUpper(response), "Y") == 0)
        {//put it in the inventory and remove it from the room
          inventory.push_back((*it));
          currentRoom->getItems()->erase(it);
          break;
        }
        else if(strcmp(convertToUpper(response), "N") == 0)
        {
          continue;
        }
        else
        {
          cout << "That is not a valid response, please type in 'Y' or 'N'" << endl;
          cout << "Exit the room and come back to the room to attempt to pick up the item again" << endl;
        }
      }

      //statement to check if the user wants to drop an item
      if(inventory.size() > 0)
      {
        curPos = -1;
        //loops through invetory of items
        for(vector<char*>::iterator itr = inventory.begin(); itr != inventory.end(); itr++)
        {
          curPos++;
          cout << "Would you like to drop your "  << *itr << " in this room?(Y/N)" << endl;
          cin >> response;
          if(strcmp(convertToUpper(response), "Y") == 0)
          {
            currentRoom->getItems()->push_back(*itr);
            inventory.erase(itr);
            break;
          }
          else if(strcmp(convertToUpper(response), "N") == 0)
          {
            continue;
          }
          else
          {
          cout << "That is not a valid response. Please type in 'Y' or 'N'" << endl;
          }
        }
      }

      //prints out the exits of the room
      cout << endl << "Exits are: " << endl;
      for(map<const char*, room*>::iterator it  = currentRoom->getMap()->begin(); it != currentRoom->getMap()->end(); it++)
      {
        cout <<it->first << ", " << it->second->getName() << endl;
      }

      //win condition
      if(inventory.size() == 5)
      {
        cout << "Good job on finding all of your missing school supplies!" << endl;
        cout << "Congratulations you have won Zuul: School Edition" << endl;
        break;
      }

      //prompts the user if they want to quit the game
      cout << "You have the option to type 'QUIT' to leave the game." << endl;
      
      //prompts the user for the direction in which they want to move in
      cout << "Which direction would you like to go in?" << endl;
      cin >> command;
    // convertToUpper(command);
      for(map<const char*, room*>::iterator it = currentRoom->getMap()->begin(); it != currentRoom->getMap()->end(); it++)
      {
        if(strcmp(it->first, convertToUpper(command))== 0)
        {
          currentRoom = it->second;
          break;
        }
      }
      //statement which will execute if user wants to quit. It exits the game
      if(strcmp(convertToUpper(command), "QUIT") == 0)
      {
        notFinished = false;
        cout << "Your parent's will not be happy about this" << endl;
        cout << "Exiting Zuul: School Edition" << endl;
      }
  } 
  }
  return 0;
}

//print welcome function
void printWelcome()
{
  cout << "Welcome to Zuul, an adventure game where you must collect items scattered through over a dozen rooms!" << endl << endl;
  cout << "You are located at Sunset High School's english class waiting for the bell to ring. The time finally comes when it does." << endl << endl;
  cout << "You are about to head home when you realize you've lost five of your school supplies. Your parents will kill you if they figure out you lost them." << endl << endl;
  cout << "It's your task to navigate through the 15 classrooms to find these school supplies, or you will be grounded once you come home." << endl<< endl ;
  cout << "The school supplies you are searching for are: a calculator, a beaker, a lunchbox, a instument, a lunch box, and finally a lunch box." << endl << endl;
  cout << "Are you planning on finding your missing school supplies?" << endl;
}

//converts char* to uppercase letters, dad helped me with this function
char* convertToUpper(char* str)
{
  int i = 0;
  while(str[i])
  {
    str[i] = toupper(str[i]);
    i++;
  }
  return str;
}
