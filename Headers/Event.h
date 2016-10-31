#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;
	std::vector <Player *> presence;
public:
	virtual ~Event();
	virtual void eventOutput(std::ofstream &out) const = 0;

	inline Date getDay() const {return this->day;}
	inline std::vector<Player *> getPresence() const {return this->presence;}

};

#endif
