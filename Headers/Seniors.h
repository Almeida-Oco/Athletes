#ifndef SENIORS_H
#define SENIORS_H
#include "Level.h"
#include <iostream>


class Seniors: public Level{
    const uint age_min = 19 , age_max = 35;
public:
    ~Seniors();
	virtual void playerOutput(std::ofstream &out) const;
};

#endif
