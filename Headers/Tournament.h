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
    Tournament(){};
    virtual ~Tournament(){};
	//Tournament(Date date);
	virtual bool Istraining() const{return false;};
	//void eventOutput(std::ofstream &out) const;
	friend ostream& operator<<(ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend istream& operator>>(istream& in, Tournament & tournament);//gets tournament from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};

};

#endif 
