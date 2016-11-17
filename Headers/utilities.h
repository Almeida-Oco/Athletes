#ifndef UTILITIES_H
#define UTILITIES_H

#include "Player.h"
#include "Date.h"
#include<iostream>
#include <string>
#include<vector>


using namespace std;

string removespaces(string s);//removes extra spaces from a string
int actualage(Date birth);//gives the age that someone born on birth has today
bool Isleap(int year);//checks if a year is leap or not
bool isInteger(const string & s);//checks if a string is an integer
int convint(string s);//converts an integer to a string

struct pScore{
	Player * player;
	unsigned int score;
public:
	inline bool operator< (const pScore &p) {return this->score < p.score;}
	inline bool operator== (const std::string name) {return this->player->getName() == name;}
};

#endif
