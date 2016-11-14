#ifndef TRAINING_H
#define TRAINING_H
#include "Event.h"


class Training: public Event{
	bool game; // True -> jogo-treino , False -> normal training

public:
	virtual ~Training(){};
	virtual bool Istraining() const{return true;};
	void fileOutput(std::ofstream &out) const {out << *this << std::endl;}
	friend std::ostream& operator<<(std::ostream& out, const Training & training);//writes training in ostream out
	friend std::istream& operator>>(std::istream& in, Training & training);//gets training from instream in

};

#endif
