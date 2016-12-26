#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>
#include"../Headers/Date.h"
using namespace std;

class InvalidDate {//throws an exception if date is invalid
	int day;
	int month;
	int year;
public:
	InvalidDate(unsigned int day, unsigned int month, unsigned int year) { this->day = day; this->month = month; this->year = year; }
	void show() const { cout << year << "/" << month << "/" << day; };
};

class InvalidPlayer { //a player is invalid if he doesn't have the minimum age to be on the team: 4 years old
	string name;
	Date birth;
public:
	InvalidPlayer(string name, Date birth);
	void show() const;
};

class DuplicateName{
	string name;
public:
	DuplicateName(const string &n) : name(n) {};
	void show() const {cout << this->name << " already exists! " << endl; }
};

#endif
