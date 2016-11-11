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
	virtual void playerOutput(std::ofstream &out) const;
	bool addPlayer(Player * player);

};
#endif
