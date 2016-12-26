#ifndef CLUB_H
#define CLUB_H

#include "utilities.h"
#include "exceptions.h"
#include "Player.h"
#include "Date.h"
#include "Level.h"
#include "Minis.h"
#include "Juveniles.h"
#include "Juniors.h"
#include "Seniors.h"
#include "Event.h"
#include "Tournament.h"
#include "Training.h"

#include <algorithm>
#include <list>
#include <stdlib.h>
#include <iomanip>
#include <tr1/unordered_set>

struct hashFuncs{
  /**
    @brief Computates the difference in days between the birthday date and current date
    @param p1
    Used has hash function
    @return If birthday > current date returns number of days, else returns -1
  */
  size_t operator()(const Player *p1) const{
    //cout << *p1 << endl;
    //cout << p1->getBirth().diffDays() << endl << endl;
    return p1->getBirth().diffDays();
  }
  /**
    @brief Compares two pointer to players to see if the Players they are pointing is the same (needed for hash table)
    @param p1 Pointer to Player 1
    @param p2 Pointer to Player 2
    Used as compare function for hash table used.
    We are only interested if the day and month are equal, the year may be different
    @return 1 if Players are the same , 0 if not
  */
  bool operator()(const Player *p1 ,const Player *p2) const{
    return ( (p1->getBirth().getDay() == p2->getBirth().getDay()) && (p1->getBirth().getMonth() == p2->getBirth().getMonth()) );
  }
};



class Club{

	string name;//name of the club
	Level *  minis;//pointer to level minis
	Level *  juveniles;//pointer to level juveniles
	Level *  juniors ;//pointer to level juniors
	Level *  seniors;//pointer to level seniors
	bool leaveprogram;//boolean that will tell the program when to leave
	static Club * singleton_instance;//pointer to instance of class Club
	string filename_players;//players filename
	string filename_trainings;//trainings filename
	string filename_tournaments;//tournaments filename
	priority_queue<Player_queue> ECG_queue;//queue with the players that haven't yet delivered the ECG
	tr1::unordered_multiset<Player *,hashFuncs , hashFuncs> future_birthdays = tr1::unordered_multiset<Player *,hashFuncs , hashFuncs>(367);

	Club();//constructor
	~Club();//destructor
public:
	static Club * getinstance();//gets instance of class Club
	string getname() const { return name;};//gets name of the club
	bool getleaveprogram() const{return leaveprogram;};//gets leaveprogram
	void setleaveprogram(bool leaveprogram){this->leaveprogram=leaveprogram;}//sets leaveprogram
	string getfilename_players() const{return this->filename_players;}//gets filename_players
	string getfilename_trainings() const{return this->filename_trainings;}//gets filename_trainings
	string getfilename_tournaments() const{return this->filename_tournaments;}//gets filename_tournaments
	void setfilename_players(string filename_players){this->filename_players=filename_players;}//sets filename_players
	void setfilename_trainings(string filename_trainings){this->filename_trainings=filename_trainings;}//sets filename_trainings
	void setfilename_tournaments(string filename_tournaments){this->filename_tournaments=filename_tournaments;}//sets filename_tournaments
	void readplayers(istream &in);//reads players from an istream
	void readtrainings(istream &in);//reads players from an istream
	void readtournaments(istream & in);//reads tournaments from an istream
	void writeplayers();//writes players in a file
	void writetrainings();//writes trainings in a file
	void writetournaments();//writes tournaments in a file
	vector<Level *> getLevels() const { return vector<Level *>{minis,juveniles,juniors,seniors}; };//return a vector with minis, juveniles, juniors...
	vector<string> getPlayers() const;//returns a vector with thes name of all the players in the club. It also includes players that participated in certain events and were later removed
	void makeTree();//constructs the binary tree
	void makeQueue();//constructs the priority queue
	void addPlayerQueue(Player * pl);//adds a player to the queue
	void removePlayerQueue(Player * pl);//adds a player to the queue
	/**
		@brief Adds the player to the hash table for future birthdays
		@param p1 Pointer to player to be added
		@detail Player can only be inserted if he is older than team maximum age (defined in seniors.h)
		@detail if not it cannot be added to the future birthday list

		@return true if insert successful , false if it cannot insert player
	*/
	bool addBirthday(Player *p1);
	/**
		@brief Removes the given Player from the future birthday list
		@param p1 Pointer to player to be removed
		@detail Compares the players by name

		@return true if removed successfuly, false if player not found
	*/
	bool removeBirthday(Player *p1);
	/**
		@brief Gets a list of players whose birthday is within parameter days
		@param days Number of days to use

		@detail Iterates all possible dates from the current day to (current_day + days) it iterates it from
		@detail end day to current day so that list is ordered by the closest birthday to the farthest birthdays
		@return List of pointer to those players
	*/
	list<Player *> nextBirthdays(unsigned int days) const;

	/**
		@brief Tries to find p1 in the future_birthdays hash table
		@param p1 Pointer to player to be found
		@return 1 if player found , 0 if player not found
	*/
	bool findOldPlayer(Player *p1);
	void ECG_notify() { ECG_queue.pop(); };//sends a notification to the first player in the queue
	void showQueue();//prints the ecg queue on the screen
};


#endif
