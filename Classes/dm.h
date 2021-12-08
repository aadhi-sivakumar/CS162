#include <iostream>
#include <string.h>
using namespace std;

class dm
{
  public:
  char* getTitle();
  void setTitle(char* t);
  int getYear();
  void setYear(int y);
  
  protected:
  char title[250];
  int year;
};