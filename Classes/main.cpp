#include <iostream>
#include <string.h>
#include <vector>
#include "vg.h"
#include "music.h"
#include "movies.h"

void displayMenu();
int getMediaType();
void getStoreVg();
void getStoreMusic();
void getStoreMovies();
void searchAndPrintMedia();
void deleteMedia();
vector<dm*> storage;

int main() 
{
    char choice[10];
    do
    {
      displayMenu();
      cin.getline(choice, 10);

      for (int i = 0; i < strlen(choice); i++)
      {
        choice[i] = toupper(choice[i]);
      }

      if (strcmp(choice, "ADD") == 0)
      {
        int  mediaType = getMediaType();
        switch(mediaType)
        {
         case 1: getStoreVg();
         case 2: getStoreMusic();
         case 3: getStoreMovies();
        }
      }
      else if(strcmp(choice, "SEARCH") == 0)
      { 
         searchAndPrintMedia();

      }
      else if (strcmp(choice, "DELETE") == 0)
      {
         deleteMedia();
      }
      else if (strcmp( choice, "QUIT") == 0)
      {
        cout << "You have exited the program." << endl;
        break;
      }
    else
    {
       cout << "Invalid Input, please enter a valid option" << endl; 
    }
  }
  while(strcmp(choice, "QUIT") != 0);

  return 0;
} 
void displayMenu()
{
    cout << "Welcome to the Digital Media Database!" << endl << endl;
    cout << "Type 'ADD' if you want to add media or information in each field" << endl;
    cout << "Type 'Search' to search for and print objects currently in the media database by the title or the year" << endl;
    cout << "Type 'Delete' to delete an item by the title or the year"<< endl;
    cout << "Type 'Quit' to quit the program" << endl;
}

int getMediaType()
{
   int Mtype; 
   cout << endl << endl;
   cout << "Type '1' to add Video Games" << endl;
   cout << "Type '2' to add Music" << endl;
   cout << "Type '3' to add Movies" << endl;
   cin >> Mtype;
   return Mtype;
}

void getStoreVg()
{
 
 int year;
 char title[255];
 int rating;
 char pub[255];

 cout << endl << "Enter Video Game details" << endl;
 cout << "Enter Year: " ; 
 cin >> year;
 cout << "Enter Title: " ; 
 cin.ignore();
 cin.getline(title,255);
 cout << "Enter Rating: ";
 cin >> rating;
 cout <<  "Enter Publisher: "; 
 cin.ignore();
 cin.getline(pub,255);
 
 
 vg* objvg = new vg();
 objvg->setMtype("vg");
 objvg->setyear(year);
 objvg->setTitle(title);
 objvg->setRating(rating);
 objvg->setPublisher(pub);
 storage.push_back(objvg);
 
}

void getStoreMusic()
{
 int year;
 char title[255];
 char artist[255];
 int duration;  
 char pub[255];

 cout << endl << "Enter Music  details" << endl;
 cout << "Enter Year: " ; 
 cin >> year;
 cout << "Enter Title: " ; 
 cin.ignore();
 cin.getline(title,255);
 cout << "Enter Duration: ";
 cin >> duration;
 cout << "Enter Artist: ";
 cin.ignore();
 cin.getline(artist,255);
 cout <<  "Enter Publisher: "; 
 cin.ignore();
 cin.getline(pub,255);
 
 music* objmusic = new music();
 objmusic->setMtype("music");
 objmusic->setyear(year);
 objmusic->setTitle(title);
 objmusic->setArtist(artist);
 objmusic->setPublisher(pub);
 objmusic->setDuration(duration);
 storage.push_back(objmusic);

}

void getStoreMovies()
{
 int year;
 char title[255];
 int duration;  
 int rating;
 char director[255];

 cout << endl << "Enter Movies  details" << endl;
 cout << "Enter Year: " ; 
 cin >> year;
 cout << "Enter Title: " ; 
 cin.ignore();
 cin.getline(title,255);
 cout << "Enter Duration: ";
 cin >> duration;
 cout << "Enter rating: ";
 cin >> rating; 
cout <<  "Enter Director: "; 
 cin.ignore();
 cin.getline(director,255);

 movies* objmovies = new movies();
 objmovies->setMtype("movies");
 objmovies->setyear(year);
 objmovies->setTitle(title);
 objmovies->setDirector(director);
 objmovies->setRating(rating);
 objmovies->setDuration(duration);
 storage.push_back(objmovies);
}

void searchAndPrintMedia()
{
         int searchType;
         int year;
         char title[255];
         cout << endl;
         cout << "Type 1 to search by Year" << endl;
         cout << "Type 2 to search by Title" << endl;
         cout << "Type 3 to search by Year and Title" << endl;
         cin >> searchType;
         switch(searchType)
         {
          case 1:{
		  cout << "Enter the year to search media database:";
                  cin >> year;
 		 } break;
 
         		
          case 2:{
		  cout << "Enter the title to search media database:";
                  cin.ignore();
                  cin.getline(title, 255);
 		 } break;
          
          case 3:{
		  cout << "Enter the year and title(separated by space) to search media database:";
                  cin >> year;
                  cin.ignore();
                  cin.getline(title, 255);
 		 } break;
         }
	bool found = false;
        dm* objfound; 
	for(int i = 0; i < storage.size(); i++)
	{
		if ((searchType == 1) &&  (storage[i]->getyear() == year)) 
		{
	  		found = true;
		        objfound = (dm*)storage[i];
                }	
                else if ((searchType == 2) && (strcmp(storage[i]->getTitle(),title)==0))
		{
	  		found = true;
		        objfound = (dm*)storage[i];
                }	
		else if ((searchType == 3) &&  (storage[i]->getyear() == year) && (strcmp(storage[i]->getTitle(), title) == 0)) 
		{
	  		found = true;
		        objfound = (dm*)storage[i];
                }
	
               if (strcmp(objfound->getMtype(), "vg")==0)
               {	
	  		vg* objvg2 = (vg*)objfound; 
	  		cout << "Title = " << objvg2->getTitle() << endl <<  "Year = " <<  objvg2->getyear() <<  endl << "Publisher = " << objvg2->getPublisher() << endl << "Rating = " << objvg2->getRating() << endl << endl;
               }
     
               if (strcmp(objfound->getMtype(), "music")==0)
               {
 			music* objmusic2 = (music*)objfound; 
 			cout << "Title = " << objmusic2->getTitle() << endl <<  "Year = " <<  objmusic2->getyear() <<  endl << "Publisher = " << objmusic2->getPublisher() << endl << "Artist = " << objmusic2->getArtist() << endl <<  "Duration = " << objmusic2->getDuration() << endl << endl;
          	}
	
          	if (strcmp(objfound->getMtype(), "movies")==0)
          	{
 			movies* objmovies2 = (movies*)objfound; 
 			cout << "Title = " << objmovies2->getTitle() << endl <<  "Year = " <<  objmovies2->getyear() <<  endl << "Director = " << objmovies2->getDirector() << endl << "Rating = " << objmovies2->getRating() << endl <<  "Duration = " << objmovies2->getDuration() << endl << endl;
         	 }	
	}
       //check found or not
       if (!found)
       {
           cout << endl << "The media that you searched is not found! Try again" << endl;
       }
}
void deleteMedia()
{
}

