
#ifndef DM_H
#define DM_H
#include <iostream>
#include <string.h>
using namespace std; 
class dm
{
	public:
		void setTitle(char* t);
                char*  getTitle();                
		void setyear(int yr);
  		int getyear();

	protected:
 		int year;
                char title[255];

};
#endif

