#include<iostream>
#include<string.h>
#include "dm.h"
using namespace std;

  char* dm::getTitle()
  {
    return title;
  }
  void dm::setTitle(char* t)
  {
    strcpy(title, t);
  }
  int dm::getYear()
  {
    return year;
  }
  void dm::setYear(int y)
  {
    year = y;
  }


