#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>
#include <string>
#include"Date.h"

class InvalidDate {//throws an exception if date is invalid
	int day;
	int month;
	int year;
public:
	InvalidDate(unsigned int day, unsigned int month, unsigned int year);
	friend std::ostream &operator<<(std::ostream &out, const InvalidDate &d);
};

class InvalidPlayer {//a player is invalid if he doesn't have the minimum age to be on the team: 4 years old
	std::string name;
	Date birth;
	
public:
	InvalidPlayer(std::string name, Date birth);
	friend std::ostream &operator<<(std::ostream &out, const InvalidPlayer &p);
};

class UnexistingPlayer{
	std::string name;
public:
	UnexistingPlayer(const std::string &name);
	friend std::ostream &operator<<(std::ostream &out , const UnexistingPlayer &p);
};
#endif
