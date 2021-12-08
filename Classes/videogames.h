#include <iostream>
using namespace std;
#include "dm.h"

class vg : public dm
{
  public:
  int getRating();
  void setRating(int r);
  
  protected:
  int rating;
};