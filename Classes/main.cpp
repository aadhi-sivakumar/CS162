#include <iostream>
#include <string.h>
#include <vector>
#include "vg.h"
#include "music.h"
#include "movies.h"

int main()
{
//Add
 vg* objvg = new vg();
 objvg->setyear(1975);
 objvg->setTitle("Aadhi Biography");
 objvg->setRating(5);
 objvg->setPublisher("poorani");
 
 vector<dm*> storage;
 storage.push_back(objvg);

music* objmusic = new music();
 objmusic->setyear(1976);
 objmusic->setTitle("Poorani music");
 objmusic->setArtist("Boss");
 objmusic->setPublisher("poorani");
 objmusic->setDuration(10);

 storage.push_back(objmusic);

movies* objmovies = new movies();
 objmovies->setyear(1977);
 objmovies->setTitle("Siva's movies");
 objmovies->setDirector("Siva");
 objmovies->setRating(9);
 objmovies->setDuration(20);

 storage.push_back(objmovies);

 vg* objvg2 = (vg*)storage[0]; 
 cout << "Title = " << objvg2->getTitle() << endl <<  "Year = " <<  objvg2->getyear() <<  endl << "Publisher = " << objvg2->getPublisher() << endl << "Rating = " << objvg2->getRating() << endl << endl;

 music* objmusic2 = (music*)storage[1]; 
 cout << "Title = " << objmusic2->getTitle() << endl <<  "Year = " <<  objmusic2->getyear() <<  endl << "Publisher = " << objmusic2->getPublisher() << endl << "Artist = " << objmusic2->getArtist() << endl <<  "Duration = " << objmusic2->getDuration() << endl << endl;

 movies* objmovies2 = (movies*)storage[2]; 
 cout << "Title = " << objmovies2->getTitle() << endl <<  "Year = " <<  objmovies2->getyear() <<  endl << "Director = " << objmovies2->getDirector() << endl << "Rating = " << objmovies2->getRating() << endl <<  "Duration = " << objmusic2->getDuration() << endl << endl;

//Search
int searchYear = 1975;
char searchTitle[255] = "Aadhi Biography";
int i;
bool found = false;
for(i = 0; i < storage.size(); i++)
{
	if ( (storage[i]->getyear() == searchYear) && (strcmp(storage[i]->getTitle(), searchTitle) == 0)) 
	{
	  found = true;		
	  vg* objvg2 = (vg*)storage[0]; 
	  cout << "Title = " << objvg2->getTitle() << endl <<  "Year = " <<  objvg2->getyear() <<  endl << "Publisher = " << objvg2->getPublisher() << endl << "Rating = " << objvg2->getRating() << endl << endl;
	}

}
if (!found)
{
	cout << "Title and Year is not found";
}
return 0;
}
