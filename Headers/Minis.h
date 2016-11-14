#ifndef MINIS_H
#define MINIS_H
#include "Level.h"

class Minis:public Level{
    const unsigned int age_min = 4 , age_max = 8;
public:
    ~Minis(){};
	bool addPlayer(Player *player);
};

#endif
