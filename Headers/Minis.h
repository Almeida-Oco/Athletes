#ifndef MINIS_H
#define MINIS_H
#include "Level.h"

class Minis:public Level{
    const uint age_min = 4 , age_max = 8;
public:
    ~Minis();
	bool addPlayer(Player player);
	virtual void playerOutput(std::ofstream &out) const;
};

#endif
