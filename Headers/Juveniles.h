#ifndef JUVENILES_H
#define JUVENILES_H

#include "Level.h"
#include <iostream>

class Juveniles : public Level{
    const unsigned int age_min = 9 , age_max = 13;
public:
    ~Juveniles() {};
	bool addPlayer(Player * player);
	void showPlayers() const;//shows the players on the screen
	void showTrainings() const;//shows the trainings on the screen
	void showTournaments() const;//shows the tournaments on the screen;
};

#endif
