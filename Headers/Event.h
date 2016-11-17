#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;
	vector<string> presences;
public:
	Event(){};
	virtual ~Event(){};
	virtual bool Istraining() const = 0;
	virtual bool getGame() const = 0;
	virtual void writetofile(ostream & out) const = 0;
	//virtual void eventOutput(std::ofstream &out) const = 0;
	inline Date getDay() const {return this->day;}

	inline void setDay(Date day){this->day=day;};
	inline vector<string> getPresences() const { return presences; };//gets vector of presences
	inline void setPresences(vector<string> presences) { this->presences = presences; };//sets new vector of presences
	inline void addPresence(const string &presence) { presences.push_back(presence); };
	virtual void show() const = 0;
	bool operator< (const Event & ev1) const { return day < ev1.day; };

	void outputNames(std::ofstream &out) const;

};

#endif
