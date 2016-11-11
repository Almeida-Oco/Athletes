#ifndef LEVEL_H
#define LEVEL_H
#include "Globals.h"
#include "Player.h"
#include "Date.h"
#include "Tournament.h"
#include "Training.h"
#include <vector>
#include <fstream>
#include <string>

class Event;

class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	Level(){};
	virtual ~Level();
	inline vector<Player *> getPlayers() const{return this->players;};
	inline vector<Event *> getEvents() const{return this->events;};
	virtual bool addPlayer(Player * player){players.push_back(player);return true;};
	void addEvent(Event * event){events.push_back(event);}
	virtual void playerOutput(std::ofstream &out) const;
	void setCoach(std::string coach){this->coach=coach;};
	inline string getCoach() const {return this->coach;};
};

#endif
