#ifndef TRAINING_H
#define TRAINING_H

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
	friend std::ostream& operator<<(std::ostream& out, const Training & training);//writes training in ostream out
	friend std::istream& operator>>(std::istream& in, Training & training);//gets training from instream in
	virtual void writetofile(std::ostream & out) const {out<<*this;};//writes training data to file

	inline unsigned int score() {return 1+this->game;}
};

#endif
