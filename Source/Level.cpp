#include "../Headers/Level.h"
#include<iomanip>

using namespace std;
/*
* Destructor
*/
Level::~Level() {
	for (unsigned int i = 0; i < players.size(); i++) {
		delete players[i];
	}
	for (unsigned int i = 0; i < events.size(); i++) {
		delete events[i];
	}
}

/*
* Gets vector of trainings
*/
vector<Event *> Level::getTrainings() const{
	vector<Event *> rtrainings;//vector that is going to be returned
	for (unsigned int i = 0; i < events.size(); i++) {
		if (events[i]->Istraining()) {
			rtrainings.push_back(events[i]);
		}
	}
	return rtrainings;
}

/*
*Gets vector of tournaments
*/
vector<Event *> Level::getTournaments() const {
	vector<Event *> rtournaments;//vector that is going to be returned
	for (unsigned int i = 0; i < events.size(); i++) {
		if (!(events[i]->Istraining())) {
			rtournaments.push_back(events[i]);
		}
	}
	return rtournaments;
}

/*
* Inserts player on the list  
* parameter: player - pointer to the player that is going to be added to the list
* return value: always true for base class. In derived classes it can be false.
*/

bool Level::addPlayer(Player * player) { 
	for (unsigned int i = 0; i < players.size(); i++) {
		if (*player < *players[i]) {
			players.insert(players.begin() + i, player);
			return true;
		}
	}
	players.push_back(player);
	return true;
}

/*
* Inserts event on the list
* parameter: ev - pointer to the event that is going to be added to the list
*/
void Level::addEvent(Event * ev) {
	for (unsigned int i = 0; i < events.size(); i++) {
		if (*ev < *(events[i])) {
			events.insert(events.begin() + i, ev);
			return;
		}
	}
	events.push_back(ev);
}

/*
* Shows players on the screen
*/
void Level::showplayers() const {
	cout <<setw(4)<<"ID|"<< setw(21) << "Name |" << setw(16) << "Birthday|" << setw(16) << "Last ECG|" <<setw(10)<<"Height(cm)|"<< setw(5) << "Assiduity|" << setw(5) << "   Games|" << setw(5) << "Small Tournaments" << endl;
	for (unsigned int i = 0; i < players.size(); i++) {
		cout <<"  "<< i + 1 << "|";
		players[i]->show();
		cout << "\n";
	}
}

/*
* Shows trainings that already happened on the screen
*/
void Level::showtrainings() const {
	cout <<setw(4)<<"ID|"<< setw(16) << "Date|" << setw(6) << "Game|" << "No. of players present"<<endl;
	vector<Event *> trainings = this->getTrainings();//gets vector of pointers to the trainings of this level
	unsigned int count = 1;//counts the training that have already been displayed
	Date current_date;//current_date
	for (unsigned int i = 0; i < trainings.size(); i++) {
		if (trainings[i]->getDay()<current_date) {
			cout << "  " << count << "|     ";
			trainings[i]->show();
			cout << "\n";
			count++;
		}
	}
}

/*
* Shows tournaments that already happened on the screen
*/
void Level::showtournaments() const {
	cout << setw(4) << " ID| " << setw(15) << "Date|" << setw(12) << " Major Tournament|" << setw(10) <<"   Rank|  No. of games| No. of players present"<<endl;
	vector<Event *> tournaments = this->getTournaments();//gets vector of pointers to the tournaments of this level
	unsigned int count = 1;//counts the training that have already been displayed
	Date current_date;//current_date
	for (unsigned int i = 0; i < tournaments.size(); i++) {
		if (tournaments[i]->getDay() < current_date) {
			cout << "  " << count << "|     ";
			tournaments[i]->show();
			cout << "\n";
			count++;
		}
	}
}

/*
*Increases by 1 the assiduity of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose assiduity is going to be raise
*/
void Level::raiseassiduity(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setAssiduity(players[i]->getAssiduity() + 1);
		}
	}
}

/*
*Decreases by 1 the assiduity of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose assiduity is going to be raised
*/
void Level::lowerassiduity(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setAssiduity(players[i]->getAssiduity() - 1);
		}
	}
}


/*
*Increases by 1 the presences in training games of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose presence in training games is going to be raised
*/
void Level::raisepgames(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setPresences_games(players[i]->getPresences_games() + 1);
		}
	}
}

/*
*Decreases by 1 the presences in training games of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose presence in training games is going to be decreased
*/
void Level::lowerpgames(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setPresences_games(players[i]->getPresences_games() -1);
		}
	}
}

/*
*Increases by 1 the presences in small tournaments of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose presence in small tournaments is going to be raised
*/
void Level::raiseptournaments(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setPresences_stournaments(players[i]->getPresences_stournaments() + 1);
		}
	}
}

/*
*Decreases by 1 the presences in small tournaments of all players whose name appears in the vector of strings
* parameter: players_names - vector with the names of players whose presence in training games is going to be decreased
*/
void Level::lowerptournaments(vector<string> players_names) {
	for (unsigned int i = 0; i < players.size(); i++) {
		if (find(players_names.begin(), players_names.end(), players[i]->getName()) != players_names.end()) {
			players[i]->setPresences_stournaments(players[i]->getPresences_stournaments() - 1);
		}
	}
}


void Level::playerOutput(ofstream &out) const {
	out << P_OPEN;
	for (unsigned int i = 0; i < this->players.size(); i++) {
		//this->players.at(i)->output(out);
	}
	out << P_CLOSE << endl;
}
