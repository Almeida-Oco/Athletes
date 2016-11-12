#ifndef JUNIORS_H
#define JUNIORS_H
#include "Level.h"
#include "Globals.h"

#include <fstream>

class Juniors : public Level{
    const uint age_min = 9 , age_max = 13;
public:
    ~Juniors();
	virtual void playerOutput(std::ofstream &out) const;

};
#endif
