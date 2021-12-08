#include <iostream>
#include <string.h>
#include <vector>
#include "videogames.h"

int main() 
{
  vg* objvg = new vg();
  objvg->setYear(1975);
  objvg->setTitle("Aadhi's Biography");
  objvg->setRating(5);

  vector<dm*> storage;
  storage.push_back(objvg);

  vg* rtnvg = (vg*)storage[0];
  cout << "Title = " << rtnvg->getTitle() << endl;
  return 0;
}
