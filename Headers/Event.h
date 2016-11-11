#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;
public:
	Event(){};
	virtual ~Event(){};
	virtual bool Istraining() const = 0;
	virtual void writetofile(ostream & out) const = 0;
	//virtual void eventOutput(std::ofstream &out) const = 0;
	inline Date getDay() const {return this->day;}
	void setDay(Date day){this->day=day;};
	//inline std::vector<Player *> getPresence() const {return this->presence;}

};

#endif
