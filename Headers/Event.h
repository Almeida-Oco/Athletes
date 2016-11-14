#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>
#include <iostream>
#include <fstream>

class Event{
	Date day;
	std::vector<Player *> presence;
public:
	virtual ~Event(){};

	virtual bool Istraining() const = 0;

	inline Date getDay() const {return this->day;}
	inline std::vector<Player *> getPresence() const {return this->presence;}

	void setDay(Date day){this->day=day;};

	void addPlayer(Player *p);

	virtual void fileOutput(std::ofstream &out) const = 0;
	void outputNames(std::ofstream &fout) const;

};

#endif
