#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Globals.h"
#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament: public Event{
	bool major; // = True -> major Tournament , = False -> small Tournament
    unsigned int rank;
    std::vector< std::pair<unsigned int, unsigned int> > results;
public:
    ~Tournament();
	Tournament();
	Tournament(Date date);
    
	void eventOutput(std::ofstream &out) const;


};

#endif 
