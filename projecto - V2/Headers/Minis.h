#ifndef MINIS_H
#define MINIS_H
#include "Level.h"

class Minis:public Level{
    const unsigned int age_min = 4 , age_max = 8;//minimum and maximum age to be on the team
public:
    Minis(){};//default constructor
    ~Minis(){};//destructor
	Minis(const Minis & minis) :Level(minis) {};//copy constructor
	Minis & operator=(const Minis & minis) { Level::operator=(minis); };//assignment operator
  virtual unsigned int getMaxAge() {return this->age_max;}
	virtual bool addPlayer(Player * player);//adds player to the vector of players
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;
	virtual vector<string> getCall( unsigned int size);//returns vector of string with the names of the players called for a tournament
};



#endif
