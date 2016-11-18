#ifndef LEVEL_H
#define LEVEL_H

#include "Player.h"
#include "Date.h"
#include "utilities.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include<iomanip>

class Event;


struct sortByScore{
	bool operator() (const std::pair<unsigned int , std::string> P1 , const std::pair<unsigned int , std::string> P2);
	//Used to help calculate which players to call for an event
};

class Level {
	std::vector <Player *> players;
	std::vector <Event *> events;
	std::string coach;
public:
	virtual ~Level();

	virtual unsigned int countTrainings(const std::vector<Event *> &ev) const;

	inline std::vector<Player *> getPlayers() const{return this->players;};//gets vector of players
	inline std::vector<Event *> getEvents() const{return this->events;};//gets vector of events
	inline std::string getCoach() const { return this->coach; };//gets coach
	std::vector<Event *> getTrainings() const;//gets vector with the trainings
	std::vector<Event *> getTournaments() const;//gets vector with the tournaments

	virtual bool addPlayer(Player * player);//adds player to the vector
	void addEvent(Event * event);//adds event to the vector

	void setCoach(std::string coach){this->coach=coach;};//sets a new coach

	virtual void showPlayers() const;//shows the players on the screen
	virtual void showTrainings() const;//shows the trainings on the screen
	virtual void showTournaments() const;//shows the tournaments on the screen
	void showScores(std::vector< std::pair<unsigned int , std::string> > &scores, unsigned int n);

	bool removePlayer(const std::string &name);//removes player from the database, including events
	bool removeEvent(const Date &day); //removes event on that day

	void raiseAssiduity(const std::vector<std::string> &players, unsigned int type);//raises assiduity for the players in the vector
	void lowerAssiduity(const std::vector<std::string> &players, unsigned int type);//lowers assiduity for the players in the vector

	Player *findPlayer(const std::string &name) const;

	std::vector< std::pair<unsigned int,std::string> > calcScores();
	unsigned int calcScorePlayer(const std::string &name);
};
#endif
