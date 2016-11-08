#ifndef JUVENILES_H
#define JUVENILES_H

#include "Level.h"

class Juveniles : public Level{
    const uint age_min = 14 , age_max = 18;
public:
    ~Juveniles();
	bool addPlayer(Player player);
	virtual void playerOutput(std::ofstream &out) const;
};

#endif
