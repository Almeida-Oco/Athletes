#ifndef PLAYER_H
#define PLAYER_H

#include "Date.h"
#include "Globals.h"
#include <string>
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
	Player(std::string name, Date birth_date, float height);
	inline std::string getName() const {return this->name;}
	inline Date getBirth() const {return this->birth;}
	inline Date getLast_Eletro() const {return this->last_eletro;}
	inline unsigned int getHeight() const {return this->height;}
	void setEletro(bool eletro);
	void setCheck(bool check);
	void output(std::ofstream &out) const;
	friend ostream& operator<<(ostream& out, const Player & player);//writes date in ostream out
	friend istream& operator>>(istream& in, Player & player);//gets date from instream in


};

#endif
