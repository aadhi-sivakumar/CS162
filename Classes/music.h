#ifndef MUSIC_H
#define MUSIC_H
#include <iostream>
using namespace std;
#include "dm.h"
class music: public dm
{
public:
   void setArtist(char* a);
   char* getArtist();
   void setPublisher(char* pub);
   char* getPublisher();
   void setDuration(int duration);
   int getDuration();
   ~music();
protected:
 char artist[255];
 int duration;
 char publisher[255];
};
#endif

