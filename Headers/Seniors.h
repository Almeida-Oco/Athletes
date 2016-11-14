#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>
#include <fstream>


class Seniors: public Level{
    const unsigned int age_min = 19 , age_max = 200;
public:
    ~Seniors(){};
	bool addPlayer(Player *player);
};

#endif
