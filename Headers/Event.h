#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;
	vector<string> presences;
public:
	Event(){};
	Event(Date day): day(day){};
	virtual ~Event(){};
	virtual bool Istraining() const = 0;
	virtual bool getGame() const = 0;
	virtual void writetofile(ostream & out) const = 0;
	virtual unsigned int getRank() const = 0;
	virtual bool getMajor() const = 0;
	virtual vector<pair<unsigned int, unsigned int>> getResults() = 0;
	virtual void setResults(vector<pair<unsigned int, unsigned int>> results)=0;
	inline Date getDay() const {return this->day;}
	void setDay(Date day){this->day=day;};
	vector<string> getPresences() const { return presences; };//gets vector of presences
	void setPresences(vector<string> presences) { this->presences = presences; };//sets new vector of presences
	virtual void setRank(unsigned int rank) {};
	void addPresence(string presence) { presences.push_back(presence); };
	virtual void show() const = 0;
	bool operator< (const Event & ev1) const { return day < ev1.day; };


};

#endif
