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

class UnexistingPlayer{
	std::string name;
	Date birth;
public:
	UnexistingPlayer(const std::string &name) : name(name) {};
	void show() const;
};

#endif
