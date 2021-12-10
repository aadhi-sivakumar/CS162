#ifndef VG_H
#define VG_H
#include <iostream>
using namespace std;
#include "dm.h"

class vg: public dm
{
public:
   void setRating(int r);
   int getRating();
   void setPublisher(char* pub);
   char* getPublisher();
   ~vg();
protected:
 int rating;
 char publisher[255];


};
#endif
