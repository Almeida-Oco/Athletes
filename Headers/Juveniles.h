#ifndef JUVENILES_H
#define JUVENILES_H

#include "Level.h"

class Juveniles : public Level{
    const unsigned int age_min = 9 , age_max = 13;
public:
    ~Juveniles(){};
    bool addPlayer(Player *player);
};

#endif
