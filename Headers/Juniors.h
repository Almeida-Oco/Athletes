#ifndef JUNIORS_H
#define JUNIORS_H
#include "Level.h"

#include <fstream>

class Juniors : public Level{
    const unsigned int age_min = 14 , age_max = 18;
public:
    ~Juniors(){};
	bool addPlayer(Player * player);

};
#endif
