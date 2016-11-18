#ifndef JUNIORS_H
#define JUNIORS_H
#include "Level.h"
#include "Globals.h"

#include <fstream>

class Juniors : public Level{
    const uint age_min = 14 , age_max = 18;
public:
    Juniors(){};
    ~Juniors(){};
	bool addPlayer(Player * player);
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;
	virtual vector<string> getCall(unsigned int size) ;//returns vector of string with the names of the players called for a tournament

};
#endif
