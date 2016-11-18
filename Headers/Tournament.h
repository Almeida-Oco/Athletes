#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Globals.h"
#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament:public Event{
	bool major; // = True -> major Tournament , = False -> small Tournament
    unsigned int rank;//rank of the team
   vector< std::pair<unsigned int, unsigned int> > results;//results of the team
public:
    Tournament(){};//default constructor
    virtual ~Tournament(){};//destructor
	Tournament(const Tournament & tournament);//copy constructor
	Tournament & operator=(const Tournament & tournament);//copy assignment
	Tournament(Event * ev);//constructor with pointer
	Tournament(Date day, bool major) : Event(day) { this->major = major; };//constructor with day and major parameter
	virtual bool Istraining() const{return false;};//returns false as the event is not a training
	virtual void show() const;//prints tournament on the screen
	virtual bool getGame() const { return false; };//gets game
	virtual unsigned int getRank() const { return rank;}//gets rank
	virtual bool getMajor() const { return major; };//gets major
	virtual vector<pair<unsigned int, unsigned int>> getResults() { return results;};//gets results
	virtual void setResults(vector<pair<unsigned int, unsigned int>> results) { this->results = results; };//sets results
	virtual void setRank(unsigned int rank) { this->rank = rank; };//sets rank
	friend ostream& operator<<(ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend istream& operator>>(istream& in, Tournament & tournament);//gets tournament from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};//writes tournament to file

};

#endif 
