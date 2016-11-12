#ifndef MINIS_H
#define MINIS_H
#include "Level.h"

class Minis:public Level{
    const uint age_min = 4 , age_max = 8;
public:
    ~Minis(){};
	virtual void playerOutput(std::ofstream &out) const;
	bool addPlayer(Player *player);
};

#endif
