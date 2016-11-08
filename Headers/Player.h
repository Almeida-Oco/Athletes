#ifndef PLAYER_H
#define PLAYER_H

#include "Date.h"
#include "Globals.h"
#include <string>
#include <fstream>

class Player{
    std::string name;
    Date year;
    bool eletro, check;
    float height;
public:
	Player();
	Player(std::string name, Date birth_date, float height);


	inline std::string getName() const {return this->name;}
	inline Date getYear() const {return this->year;}
	inline bool getEletro() const {return this->eletro;}
	inline bool getCheck() const {return this->check;}
	inline float getHeight() const {return this->height;}
	void setEletro(bool eletro);
	void setCheck(bool check);
	void output(std::ofstream &out) const;


};

#endif
