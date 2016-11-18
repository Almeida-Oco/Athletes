#ifndef TRAINING_H
#define TRAINING_H
#include "Globals.h"
#include "Event.h"


class Training: public Event{
	bool game; // True -> jogo-treino , False -> normal training


public:
	Training(){};
	Training(Date day, bool game) : Event(day) { this->game = game; };
	virtual ~Training(){};
	virtual bool getGame() const{ return game; };
	virtual bool Istraining() const{return true;};
	virtual void show() const;
	virtual unsigned int getRank() const { return 0; };
	virtual bool getMajor() const { return false; };
	virtual vector<pair<unsigned int, unsigned int>> getResults() { return vector<pair<unsigned int, unsigned int>>(); };
	virtual void setResults(vector<pair<unsigned int, unsigned int>> results) {};
	virtual void setRank(unsigned int rank) {};
	friend ostream& operator<<(ostream& out, const Training & training);//writes training in ostream out
	friend istream& operator>>(istream& in, Training & training);//gets training from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};//writes training data to file

};

#endif
