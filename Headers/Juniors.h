#ifndef JUNIORS_H
#define JUNIORS_H
#include "Level.h"

#include <fstream>

class Juniors : public Level{
    const unsigned int age_min = 14 , age_max = 18;
public:
    ~Juniors() {};
	bool addPlayer(Player * player);
	virtual void showPlayers() const;//shows the players on the screen
	virtual void showTrainings() const;//shows the trainings on the screen
	virtual void showTournaments() const;//shows the tournaments on the screen;
};
#endif
