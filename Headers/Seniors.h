#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>


class Seniors: public Level{
    const uint age_min = 19 , age_max = 200;//minimum and maximum age to be on the team
public:
    Seniors(){};//default constructor
    ~Seniors(){};//destructor
	Seniors(const Seniors & seniors) :Level(seniors) {};//copy constructor
	Seniors & operator=(const Seniors & seniors) { Level::operator=(seniors); };//assignment operator
	virtual bool addPlayer(Player * player);//adds player to the team
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;
	virtual vector<string> getCall(unsigned int size) ;//returns vector of string with the names of the players called for a tournament

	
};

#endif
