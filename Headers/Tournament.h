#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Globals.h"
#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament:public Event{
	bool major; // = True -> major Tournament , = False -> small Tournament
    unsigned int rank;
    std::vector< std::pair<unsigned int, unsigned int> > results;
public:
    virtual ~Tournament(){};
	//Tournament(Date date);
	virtual bool Istraining() const{return false;};
	//void eventOutput(std::ofstream &out) const;
	friend std::ostream& operator<<(std::ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend std::istream& operator>>(std::istream& in, Tournament & tournament);//gets tournament from instream in
	virtual void writetofile(std::ostream & out) const {out<<*this;};

};

#endif 
