#ifndef PLAYER_H
#define PLAYER_H

#include "Date.h"
#include "Globals.h"
#include <string>
#include <fstream>

class Player{
    string name;//name of the player
    Date birth;//date when the player was born
	vector<Date> ecg;//vector of dates when the player had an ecg
    unsigned int height;//height of the player in cm
    unsigned int assiduity;//this parameter gives the assiduity of a player in the trainings
    unsigned int presences_games;//this parameter gives the assiduity of a player in the training games
    unsigned int presences_stournaments;////this parameter gives the assiduity of a player in the small tournaments
public:
	Player():birth(Date(0,0,0)){};//default constructor
	Player(string name, Date birth_date, unsigned int height) :birth(birth_date) { this->name = name; this->height = height; this->assiduity = 0; this->presences_games = 0; this->presences_stournaments = 0; };//constructor with parameters
	inline string getName() const {return this->name;}//gets name
	inline Date getBirth() const {return this->birth;}//gets birth
	inline vector<Date> getECG() const {return this->ecg;}//gets ecg
	inline unsigned int getHeight() const {return this->height;}//gets height
	inline unsigned int getAssiduity() const { return this->assiduity; };//gets assiduity
	inline unsigned int getPresences_games() const { return this->presences_games; };//gets presences in games
	inline unsigned int getPresences_stournaments() const { return this->presences_stournaments;};//gets presences in s_tournaments
	void setAssiduity(unsigned int assiduity) { this->assiduity = assiduity; };//sets assiduity
	void setPresences_games(unsigned int presences_games) { this->presences_games = presences_games; };//sets presences in games
	void setPresences_stournaments(unsigned int presences_stournaments) { this->presences_stournaments = presences_stournaments; };//sets presences in small tournaments
	void setHeight(unsigned int height) { this->height = height; };//sets height
	void addECG(Date last_eletro);//adds ecg to the list
	void show() const;//prints the player on the screen
	Date getLast_Eletro() const;//gets the date when the player had his last ecg
	bool checkECG(Date & d) const;//checks if the player had his ecg in order on the date d
	bool operator<(const Player & p1) const { return name < p1.name; };//compares players
	friend ostream& operator<<(ostream& out, const Player & player);//writes date in ostream out
	friend istream& operator>>(istream& in, Player & player);//gets date from instream in
};

#endif
