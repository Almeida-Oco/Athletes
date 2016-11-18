#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Globals.h"
#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament:public Event{
	bool major; // = True -> major Tournament , = False -> small Tournament
    unsigned int rank;
   vector< std::pair<unsigned int, unsigned int> > results;
public:
    Tournament(){};
    virtual ~Tournament(){};
	Tournament(Date day, bool major) : Event(day) { this->major = major; };
	virtual bool Istraining() const{return false;};
	virtual void show() const;
	virtual bool getGame() const { return false; };
	virtual unsigned int getRank() const { return rank; }
	virtual bool getMajor() const { return major; };
	virtual vector<pair<unsigned int, unsigned int>> getResults() { return results; };
	virtual void setResults(vector<pair<unsigned int, unsigned int>> results) { this->results = results; };
	virtual void setRank(unsigned int rank) { this->rank = rank; };
	friend ostream& operator<<(ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend istream& operator>>(istream& in, Tournament & tournament);//gets tournament from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};

};

#endif 
