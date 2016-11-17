#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>


class Seniors: public Level{
    const unsigned int age_min = 19 , age_max = 200;
public:
    ~Seniors() {};
	bool addPlayer(Player * player);
	virtual void showPlayers() const;//shows the players on the screen
	virtual void showTrainings() const;//shows the trainings on the screen
	virtual void showTournaments() const;//shows the tournaments on the screen;
};

#endif
