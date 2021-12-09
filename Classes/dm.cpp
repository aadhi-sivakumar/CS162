#include <iostream>
#include <string.h>
#include "dm.h"
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
