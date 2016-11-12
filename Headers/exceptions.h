#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>
#include"Date.h"

class InvalidDate {//throws an exception if date is invalid
	int day;
	int month;
	int year;
public:
	InvalidDate(unsigned int day, unsigned int month, unsigned int year) { this->day = day; this->month = month; this->year = year; }
	void show() const { std::cout << year << "/" << month << "/" << day; };
};

class InvalidPlayer {//a player is invalid if he doesn't have the minimum age to be on the team: 4 years old
	std::string name;
	Date birth;
	
public:
	InvalidPlayer(std::string name, Date birth);
	void show() const;
};

#endif
