#ifndef EVENT_H
#define EVENT_H

#include "Player.h"

#include <vector>

class Event{
	Date day;//day when the event was realized
	vector<string> presences;//players that participated in the tournament
public:
	Event(){};//default constructor
	virtual ~Event() {};//destructor
	Event(const Event & ev) { day = ev.day; presences = ev.presences; };//copy constructor
	Event & operator=(const Event & ev) { day = ev.day; presences = ev.presences; return *this; };//copy assignement
	Event(Date day): day(day){};//constructor with parameter day
	vector<string> getPresences() const { return presences; };//gets vector of presences
	inline Date getDay() const { return this->day; };//gets day
	void setDay(Date day) { this->day = day;};//sets day
	void setPresences(vector<string> presences) { this->presences = presences; };//sets new vector of presences
	void addPresence(string presence) { presences.push_back(presence); };//adds the name of a player to presences
	bool operator< (const Event & ev1) const { return day < ev1.day; };//returns true if event obj. happened before ev1
	virtual bool Istraining() const = 0;//returns true if event is training, false otherwise
	virtual bool getGame() const = 0;//gets game, if event does not have this parameter returns false
	virtual unsigned int getRank() const = 0;//gets rank, if event does not have this parameter returns 0
	virtual bool getMajor() const = 0;//gets major, if event does not have this parameter returns false
	virtual vector<pair<pair<unsigned int, unsigned int>, string >> getResults() const = 0;//gets results, if event does not have this parameter returns empty vector
	virtual void setResults(vector<pair<pair<unsigned int, unsigned int>, string >> results)=0;//sets results, if event does not have this parameter does nothing
	virtual void setRank(unsigned int rank)=0;//sets rank, if event does not have this parameter does nothing
	virtual void show() const = 0;//prints event on the screen
	virtual void writetofile(ostream & out) const = 0;//writes event information to file


};

#endif
