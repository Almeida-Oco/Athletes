#ifndef TRAINING_H
#define TRAINING_H
#include "Globals.h"
#include "Event.h"


class Training: public Event{
	bool game; // True -> jogo-treino , False -> normal training


public:
	Training(){};//default constructor
	virtual ~Training() {};//destructor
	Training(const Training & training);//copy constructor
	Training & operator=(const Training & training);//copy assignment operator
	Training(Event * ev);//constructor with pointer to event
	Training(Date day, bool game) : Event(day) { this->game = game; };//constructor with day and game parameters
	virtual bool getGame() const{ return game; };//gets game
	virtual bool Istraining() const{return true;};//returns true as this event is a training
	virtual void show() const;//prints training on the screen
	virtual unsigned int getRank() const { return 0; };//returns 0, this event has no parameter rank
	virtual bool getMajor() const { return false; };//returns false, this event has no parameter major
	virtual vector<pair<unsigned int, unsigned int>> getResults() { return vector<pair<unsigned int, unsigned int>>(); };//gets empty vector as this event has no parameter results
	virtual void setResults(vector<pair<unsigned int, unsigned int>> results) {};//does nothing has this event has no parameter results
	virtual void setRank(unsigned int rank) {};//does nothing as this event has no parameter rank
	friend ostream& operator<<(ostream& out, const Training & training);//writes training in ostream out
	friend istream& operator>>(istream& in, Training & training);//gets training from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};//writes training data to file

};

#endif
