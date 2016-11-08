#ifndef LEVEL_H
#define LEVEL_H
#include "Globals.h"
#include "Player.h"
#include "Date.h"
#include <vector>
#include <fstream>
#include <string>

class Event;

class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	Level();
	virtual ~Level();
	virtual bool addPlayer(Player player)=0;
	bool addEvent(Event * Event);
	virtual void playerOutput(std::ofstream &out) const;
	bool setCoach(std::string coach);
	std::string getCoach();
};

#endif
