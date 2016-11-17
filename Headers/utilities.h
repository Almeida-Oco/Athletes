#ifndef UTILITIES_H
#define UTILITIES_H

#include<iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Date.h"

std::string removeSpaces(std::string s);//removes extra spaces from a string
unsigned int actualAge(const Date &birth);
bool Isleap(int year);//checks if a year is leap or not
Date currentDate();
std::vector<std::string> stringSplit(const std::string &line, const std::string &spliter);

struct pScore{
	Player * player;
	unsigned int score;
public:
	inline bool operator< (const pScore &p) {return this->score < p.score;}
	inline bool operator== (const std::string name) {return this->player->getName() == name;}
};

#endif
