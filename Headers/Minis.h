#ifndef MINIS_H
#define MINIS_H
#include "Level.h"
#include <iostream>

class Minis:public Level{
    const unsigned int age_min = 4 , age_max = 8;
public:
    ~Minis() {};
	bool addPlayer(Player * player);//adds player to the vector of players
	virtual void showPlayers() const;//shows the players on the screen
	virtual void showTrainings() const;//shows the trainings on the screen
	virtual void showTournaments() const;//shows the tournaments on the screen;
};

#endif
