#include "../Headers/exceptions.h"
using namespace std;

ostream &operator<< (ostream &out , const InvalidDate &d){
	out << d.day << "/" << d.month << "/" << d.year << endl;
	return out;
}

ostream &operator<< (ostream &out , const InvalidPlayer &p){
	out << p.name << "born on: " << p.birth << " is not a valid player of the team." << endl;
	return out;
}

InvalidDate::InvalidDate(unsigned int day , unsigned int month , unsigned int year) : day(day) , month(month) , year(year) {};

InvalidPlayer::InvalidPlayer(string name, Date birth) :name(name) , birth(birth) {};

UnexistingPlayer::UnexistingPlayer(const string &name) : name(name) {};

ostream &operator<<(ostream &out , const UnexistingPlayer &p){
	out << p.name << " does not exist!" << endl;
	out << "File must be corrupt" << endl;
	return out;
}
