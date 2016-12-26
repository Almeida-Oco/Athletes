#ifndef LEVEL_H
#define LEVEL_H
#include "Player.h"
#include "Date.h"
#include "Tournament.h"
#include "Training.h"
#include "BST.h"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

class Event;

class Level {
	vector <Player *> players;//players of this team
    vector <Event *> events;//events of the level
	BST<Player_node> players_tree;//tree with the players that will be used to distribute the monthly prizes
	string coach;//level coach
public:
	Level():players_tree(Player_node()){};//default constructor
	virtual ~Level();//destructor
	Level(const Level & level);//copy constructor
	Level & operator=(const Level & level);//copy assignement operator
	virtual unsigned int getMaxAge()  = 0;
	inline vector<Player *> getPlayers() const{return this->players;};//gets vector of players
	inline vector<Event *> getEvents() const{return this->events;};//gets vector of events
	inline string getCoach() const { return this->coach; };//gets coach
	inline BST<Player_node> getPlayers_tree() const { return this->players_tree; };//gets players_tree
	vector<Event *> getTrainings() const;//gets vector with the trainings
	vector<Event *> getTournaments() const;//gets vector with the tournaments
	virtual bool addPlayer(Player * player);//adds player to the vector
	void addEvent(Event * event);//adds event to the vector
	void setCoach(std::string coach){this->coach=coach;};//sets a new coach
	virtual void showplayers() const;//shows the players on the screen
	virtual void showtrainings() const;//shows the trainings on the screen
	virtual void showtournaments() const;//shows the tournaments on the screen
	virtual void showevents() const;//shows next events on the calendar on the screen
	void removeplayer(unsigned int id);//removes player from vector
	void removeEvent(unsigned int id);//removes event from the vector
	vector<Event*>getFutureEvents();//shows events scheduled for a posterior date
	void raiseassiduity(vector<string> players);//raises assiduity for the players in the vector
	void lowerassiduity(vector<string> players);//lowers assiduity for the players in the vector
	void raisepgames(vector<string> players);//raises presences in games for the players in the vector
	void lowerpgames(vector<string> players);//lowers presences in games for the players in the vector
	void raiseptournaments(vector<string> players);//raises the presences in small tournaments for the players in the vector
	void lowerptournaments(vector<string> players);//lowers presences in small tournaments for the players in the vector
	void raisegames_won(vector<string> players, int value, vector<pair<pair<unsigned int, unsigned int>, string >> results);//raises the number of games won by value for the players in the vector
	void raiseassiduity_curr(vector<string> player, int value);//raises the current assiduity of the players by value
	virtual vector<string> getCall(unsigned int size)=0;//returns vector of string with the names of the players called for a tournament
	void actualize_curr_parameters();//actualizes the current assiduity and the number of games won for all the players in this level
	void makeTree();//constructs the players_tree
	void remove_Tree(Player_node pl) { players_tree.remove(pl);};//removes a player from the tree
};

#endif
