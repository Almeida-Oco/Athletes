#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>


class Seniors: public Level{
    const uint age_min = 19 , age_max = 200;
public:
    ~Seniors(){};
	bool addPlayer(Player *player);
	virtual void playerOutput(std::ofstream &out) const;
};

#endif
