#include "../Headers/Level.h"
#include "../Headers/exceptions.h"

using namespace std;

bool Level::removePlayer(string &name){
	bool found = false;

	for(vector<Player*>::iterator it = this->players.begin() ; it !=this->players.end() ; it++){
		if ((*it)->getName() == name){
			it = this->players.erase(it);
			found = true;
		}
	}

	for (vector<Event *>::iterator it = this->events.begin() ; it!=this->events.end() ; it++){
		for (vector<Player *>::iterator p_it = (*it)->getPresence().begin() ; p_it != (*it)->getPresence().end() ; p_it++){
			if ( (*p_it)->getName() == name)
				(*it)->getPresence().erase((*p_it));
				continue;
			}
		}
	}
	return found;
}

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


set<pScore> Level::calcScores(){
	set<pScore> score_board;
	pScore temp;

	for (vector<Event *>::iterator e_it = this->events.begin() ; e_it != this->events.end() ; e_it++){
		for (vector<Player *>::iterator p_it = (*e_it)->getPresence().begin() ; p_it != (*e_it)->getPresence().end() ; p_it++){
			if( find(score_board.begin() , score_board.end() , (*p_it)->getName()) != score_board.end() ){

			}
		}
	}

	return score_board;
}

bool repeated()
