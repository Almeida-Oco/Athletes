#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>


class Seniors: public Level{
    const uint age_min = 19 , age_max = 200;
public:
    Seniors(){};
    ~Seniors(){};
	bool addPlayer(Player player);
	bool addPlayer(Player * player);
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;

	virtual void playerOutput(std::ofstream &out) const;
};

#endif
