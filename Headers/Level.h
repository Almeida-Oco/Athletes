#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Event.h"
#include "Date.h"
#include "Tournament.h"
#include "Training.h"
#include <vector>
#include <fstream>
#include <string>


class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	virtual ~Level();

	virtual bool addPlayer(Player *player) = 0;
	bool removePlayer(std::string &name);
	bool addEvent(Event * Event);
	bool removeEvent(const Date &day);


	inline std::vector<Player *> getPlayers() const{return this->players;};
	inline std::vector<Event *> getEvents() const{return this->events;};

	virtual unsigned int countTrainings(const std::vector<Event *> &ev)const;
	void setCoach(std::string coach){this->coach=coach;};
	inline std::string getCoach() const {return this->coach;};

	Player *findPlayer(const std::string &name) const;
};

#endif
