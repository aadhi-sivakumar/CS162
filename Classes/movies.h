#ifndef MOVIES_H
#define MOVIES_H
#include <iostream>
using namespace std;
#include "dm.h"

class movies: public dm
{
public:
   void setRating(int r);
   int getRating();
   void setDirector(char* d);
   char* getDirector();
   void setDuration(int d);
   int getDuration();

protected:
 int rating;
 char director[255];
 int duration;
};
#endif
