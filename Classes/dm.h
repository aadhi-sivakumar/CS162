
#ifndef DM_H
#define DM_H
#include <iostream>
#include <string.h>
using namespace std; 
class dm
{
	public:
		char* getMtype();
                void setMtype(char* ty);
		void setTitle(char* t);
                char*  getTitle();                
		void setyear(int yr);
  		int getyear();

	protected:
 	        char mtype[10];
		int year;
                char title[255];

};
#endif

