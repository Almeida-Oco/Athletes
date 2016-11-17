#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Date.h"
#include "Tournament.h"
#include "Training.h"
#include "utilities.h"
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>

class Event;

class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	virtual ~Level();

	virtual unsigned int countTrainings(const std::vector<Event *> &ev) const;

	inline vector<Player *> getPlayers() const{return this->players;};//gets vector of players
	inline vector<Event *> getEvents() const{return this->events;};//gets vector of events
	inline string getCoach() const { return this->coach; };//gets coach
	vector<Event *> getTrainings() const;//gets vector with the trainings
	vector<Event *> getTournaments() const;//gets vector with the tournaments

	virtual bool addPlayer(Player * player);//adds player to the vector
	void addEvent(Event * event);//adds event to the vector

	void setCoach(std::string coach){this->coach=coach;};//sets a new coach

	virtual void showPlayers() const;//shows the players on the screen
	virtual void showTrainings() const;//shows the trainings on the screen
	virtual void showTournaments() const;//shows the tournaments on the screen


	bool removePlayer(const string &name);//removes player from the database, including events
	bool removeEvent(const Date &day); //removes event on that day

	void raiseAssiduity(const vector<string> &players, unsigned int type);//raises assiduity for the players in the vector
	void lowerAssiduity(const vector<string> &players, unsigned int type);//lowers assiduity for the players in the vector

	virtual void playerOutput(std::ofstream &out) const;
	Player *findPlayer(const std::string &name) const;
};

#endif
