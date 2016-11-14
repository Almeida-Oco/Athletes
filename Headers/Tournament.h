#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament:public Event{
	bool major; // = True -> major Tournament , = False -> small Tournament
    unsigned int rank;
    std::vector< std::pair<unsigned int, unsigned int> > results;
public:
    virtual ~Tournament(){};
	inline bool Istraining() const{return false;};
	void fileOutput(std::ofstream &out) const {out << *this << std::endl;}

	friend std::ostream& operator<<(std::ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend std::istream& operator>>(std::istream& in, Tournament & tournament);//gets tournament from instream in

};

#endif 
