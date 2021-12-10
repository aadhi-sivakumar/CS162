#include <iostream>
#include "movies.h"
#include <string.h>

movies::~movies(){};

char* movies::getDirector()
{
	return director;
}
void movies::setDirector(char* d)
{
	 strcpy(director, d);
}

int movies::getDuration()
{
	 return duration;
}

void movies::setDuration(int d)
{
	 duration = d;
}

int movies::getRating()
{
	 return rating;
}
void movies::setRating(int r)
{
	rating = r;
}


