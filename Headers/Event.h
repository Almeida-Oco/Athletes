#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;
	std::vector<std::string> presences;
public:
	Event(){};
	virtual ~Event(){};
	virtual bool Istraining() const = 0;
	virtual bool getGame() const = 0;
	virtual void writetofile(std::ostream & out) const = 0;
	inline Date getDay() const {return this->day;}

	inline void setDay(Date day){this->day=day;};
	virtual inline std::vector<std::string> getPresences() const { return presences; };//gets vector of presences
	inline void setPresences(std::vector<std::string> presences) { this->presences = presences; };//sets new vector of presences
	inline void addPresence(const std::string &presence) { presences.push_back(presence); };
	virtual void show() const = 0;
	bool operator< (const Event & ev1) const { return day < ev1.day; };

	void outputNames(std::ofstream &out) const;
	virtual unsigned int score()=0;

};

#endif
