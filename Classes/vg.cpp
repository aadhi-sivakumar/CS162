#include <iostream>
#include "vg.h"
#include <string.h>

vg::~vg(){};
void vg::setRating(int r)
{
  rating = r;
}

int vg::getRating()
{
  return rating;
}

char* vg::getPublisher()
{
  return publisher;
}

void vg::setPublisher(char* pub)
{
 strcpy(publisher, pub);
}


