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
	inline vector<Player *> getPlayers() const{return this->players;};//gets vector of players
	inline vector<Event *> getEvents() const{return this->events;};//gets vector of events
	inline string getCoach() const { return this->coach; };//gets coach
	vector<Event *> getTrainings() const;//gets vector with the trainings
	vector<Event *> getTournaments() const;//gets vector with the tournaments
	virtual bool addPlayer(Player * player);//adds player to the vector
	void addEvent(Event * event);//adds event to the vector
	void setCoach(std::string coach){this->coach=coach;};//sets a new coach
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen
	virtual void showevents() const;//shows next events on the calendar on the screen
	void removeplayer(unsigned int id) { if (id <= players.size()) { players.erase(players.begin() + id - 1); } };//removes player from vector
	void removeEvent(unsigned int id);//removes event from the vector
	vector<Event*>getFutureEvents();//shows events scheduled for a posterior date
	void raiseassiduity(vector<string> players);//raises assiduity for the players in the vector
	void lowerassiduity(vector<string> players);//lowers assiduity for the players in the vector
	void raisepgames(vector<string> players);//raises presences in games for the players in the vector
	void lowerpgames(vector<string> players);//lowers presences in games for the players in the vector
	void raiseptournaments(vector<string> players);//raises the presences in small tournaments for the players in the vector
	void lowerptournaments(vector<string> players);//lowers presences in small tournaments for the players in the vector
	virtual vector<string> getCall(unsigned int size)=0;//returns vector of string with the names of the players called for a tournament
};

#endif
