
#include <iostream>
#include "music.h"
#include <string.h>

music::~music(){};
char* music::getArtist()
{
	return artist;
}
void music::setArtist(char* a)
{
	 strcpy(artist, a);
}

int music::getDuration()
{
	 return duration;
}

void music::setDuration(int d)
{
	 duration = d;
}

char* music::getPublisher()
{
	 return publisher;
}
void music::setPublisher(char* pub)
{
	strcpy(publisher, pub);
}


