#include "../Headers/Level.h"
#include "../Headers/exceptions.h"

using namespace std;

/*
void Level::playerOutput(ofstream &out) const{
	out << P_OPEN;
	for (unsigned int i = 0 ; i< this->players.size() ; i++){
		//this->players.at(i)->output(out);
	}
	out << P_CLOSE << endl;
}

bool Level::removePlayer(string &name){
	//THROW EXCEPTION UNKNOWN/PLAYER NOT FOUND
	for(vector<Player*>::iterator it = this->players.begin() ; it !=this->players.end() ; it++){
		if ((*it)->getName() == name){
			it = this->players.erase(it);
			return true;
		}

	}
	return false;
}
*/
bool Level::addEvent(Event * event){
	this->events.push_back(event);
	return true;
}

bool Level::addPlayer(Player *player){
	this->players.push_back(player);
	return true;
}

bool Level::removeEvent(const Date &date){
	//THROW EXCEPTION EVENT NOT FOUND
	for(vector<Event*>::iterator it = this->events.begin() ; it!=this->events.end() ; it++){
		if ( (*it)->getDay() == date){
			this->events.erase(it);
			return true;
		}
	}
	return false;
}

unsigned int Level::countTrainings(const vector<Event *> &ev) const{
	unsigned int count = 0;
	for (unsigned int i = 0 ; i<ev.size() ; i++)
		count += ev.at(i)->Istraining();

	return count;
}

Player *Level::findPlayer(const string &name) const{
	for (unsigned int i = 0 ; this->players.size() ; i++)
		if (this->players.at(i)->getName() == name)
			return this->players.at(i);
	throw UnexistingPlayer(name);
}

Level::~Level() {
	for (unsigned int i = 0; i < players.size(); i++) {
		delete players[i];
	}
	for (unsigned int i = 0; i < events.size(); i++) {
		delete events[i];
	}
}
