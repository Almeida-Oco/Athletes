#ifndef TRAINING_H
#define TRAINING_H
#include "Globals.h"
#include "Event.h"


class Training: public Event{
	bool game; // True -> jogo-treino , False -> normal training


public:
	Training(){};
	virtual ~Training(){};
	virtual bool getGame() const{ return game; };
	virtual bool Istraining() const{return true;};
	//void eventOutput(std::ofstream &out) const;
	virtual void show() const;
	friend ostream& operator<<(ostream& out, const Training & training);//writes training in ostream out
	friend istream& operator>>(istream& in, Training & training);//gets training from instream in
	virtual void writetofile(ostream & out) const {out<<*this;};//writes training data to file

};

#endif
