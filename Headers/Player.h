#ifndef PLAYER_H
#define PLAYER_H

#include "Date.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>

class Player{
    std::string name;
    Date birth;
    Date last_eletro;
    unsigned int height;
    unsigned int assiduity;//this parameter gives the assiduity of a player in the trainings
    unsigned int presences_games;//this parameter gives the assiduity of a player in the training games
    unsigned int presences_stournaments;////this parameter gives the assiduity of a player in the small tournaments
public:
	Player():birth(Date(0,0,0)),last_eletro(Date(0,0,0)){};//default constructor
	Player(std::string name, Date birth_date, Date eletro, unsigned int height) :birth(birth_date), last_eletro(eletro) { this->name = name; this->height = height; this->assiduity = 0; this->presences_games = 0; this->presences_stournaments = 0; };

	inline std::string getName() const {return this->name;}
	inline Date getBirth() const {return this->birth;}
	inline Date getLast_Eletro() const {return this->last_eletro;}
	inline unsigned int getHeight() const {return this->height;}
	inline unsigned int getAssiduity() const { return this->assiduity; };
	inline unsigned int getPresences_games() const { return this->presences_games; };
	inline unsigned int getPresences_stournaments() const { return this->presences_stournaments;};

	void setAssiduity(unsigned int assiduity) { this->assiduity = assiduity; };
	void setPresences_games(unsigned int presences_games) { this->presences_games = presences_games; };
	void setPresences_stournaments(unsigned int presences_stournaments) { this->presences_stournaments = presences_stournaments; };
	void setLast_Eletro(Date last_eletro) { this->last_eletro = last_eletro; };
	void setHeight(unsigned int height) { this->height = height; };

	bool operator<(const Player & p1) const { return name < p1.name; };//compares players
	friend std::ostream& operator<<(std::ostream& out, const Player & player);//writes date in ostream out
	friend std::istream& operator>>(std::istream& in, Player & player);//gets date from instream in

	void show() const;//prints the player on the screen
};

#endif
