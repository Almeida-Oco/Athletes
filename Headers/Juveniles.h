#ifndef JUVENILES_H
#define JUVENILES_H

#include "Level.h"

class Juveniles : public Level{
    const uint age_min = 9 , age_max = 13;
public:
    Juveniles(){};
    ~Juveniles(){};
	bool addPlayer(Player player);
	virtual void playerOutput(std::ofstream &out) const;
	bool addPlayer(Player * player);
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen;
};

#endif
