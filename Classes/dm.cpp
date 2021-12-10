#include <iostream>
#include <string.h>
#include "dm.h"

dm::~dm(){};

char* dm::getMtype()
{
 return mtype;
}

void dm::setMtype(char* ty)
{
 strcpy(mtype, ty);
}
void dm::setTitle(char*  t)
{
 strcpy(title, t);
}
char* dm::getTitle()
{
	return title;
}
void dm:: setyear(int y)
{
 year = y;
}

int dm::getyear()
{
 return year;
}
