#ifndef LEVEL_H
#define LEVEL_H
#include "Globals.h"
#include "Player.h"
#include "Event.h"
#include "Date.h"
#include <vector>
#include <fstream>
#include <string>

class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	Level();
	virtual ~Level();
	bool addPlayer(Player *player);
	bool removePlayer(std::string &name);
	bool addEvent(Event * Event);
	bool removeEvent(const Date &day);
	virtual void playerOutput(std::ofstream &out) const;
	bool setCoach(std::string coach);
	std::string getCoach();
};

#endif
