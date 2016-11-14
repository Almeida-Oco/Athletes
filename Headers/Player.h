#ifndef PLAYER_H
#define PLAYER_H

#include "Date.h"
#include <string>
#include <iostream>
#include <fstream>


class Player{
    std::string name;
    Date last_eletro;
    Date birth;
    unsigned int height;
    unsigned int assiduity;//this parameter gives the assiduity of a player in events

public:


	Player();//default constructor
	Player(std::string name, Date birth_date, Date eletro , unsigned int height, unsigned int assi);


	inline std::string getName() const {return this->name;}
	inline Date getBirth() const {return this->birth;}
	inline Date getLast_Eletro() const {return this->last_eletro;}
	inline unsigned int getHeight() const {return this->height;}
	inline unsigned int getAssiduity() const {return this->assiduity;}

	void setEletro(bool eletro);
	void setCheck(bool check);

	friend std::ostream& operator<<(std::ostream& os, const Player&p);
	friend std::istream &operator>>(std::istream &in, Player &player);//gets date from instream in
};

#endif
