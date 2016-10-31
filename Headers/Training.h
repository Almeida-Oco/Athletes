#ifndef TRAINING_H
#define TRAINING_H
#include "Globals.h"
#include "Event.h"


class Training: public Event{
	bool game; // True -> jogo-treino , False -> normal training


public:
	~Training();
	void eventOutput(std::ofstream &out) const;

};

#endif
