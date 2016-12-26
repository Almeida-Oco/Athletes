#ifndef JUVENILES_H
#define JUVENILES_H

#include "Level.h"

class Juveniles : public Level{
    const unsigned int age_min = 9 , age_max = 13;//minimum and maximum age to be on the team
public:
    Juveniles(){};//default constructor
    ~Juveniles(){};//destructor
	Juveniles(const Juveniles & juveniles) :Level(juveniles) {};//copy constructor
	Juveniles & operator=(const Juveniles & juveniles) { Level::operator=(juveniles); };//assignment operator
  virtual unsigned int getMaxAge() {return this->age_max;}
  virtual unsigned int getMinAge() {return this->age_min;}
	virtual bool addPlayer(Player * player);//adds Player to the team
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;
	virtual vector<string> getCall(unsigned int size);//returns vector of string with the names of the players called for a tournament
};

#endif
