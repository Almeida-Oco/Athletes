#ifndef JUNIORS_H
#define JUNIORS_H
#include "Level.h"
#include "Globals.h"

#include <fstream>

class Juniors : public Level{
    const uint age_min = 14 , age_max = 18;//minimum and maximum age to be on the team
public:
    Juniors(){};//default constructor
    ~Juniors(){};//destructor
	Juniors(const Juniors & juniors) :Level(juniors) {};//copy constructor
	Juniors & operator=(const Juniors & juniors) { Level::operator=(juniors); };//assignment operator
	virtual bool addPlayer(Player * player);//adds Player to the team
	virtual void showplayers() const;//shows players on the screen
	virtual void showtrainings() const;//shows trainings on the screen
	virtual void showtournaments() const;//shows tournaments on the screen;
	virtual vector<string> getCall(unsigned int size) ;//returns vector of string with the names of the players called for a tournament

};
#endif
