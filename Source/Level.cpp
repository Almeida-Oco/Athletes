#include "../Headers/Level.h"

using namespace std;
Level::~Level() {
	for (unsigned int i = 0; i < players.size(); i++) {
		delete players[i];
	}
	for (unsigned int i = 0; i < events.size(); i++) {
		delete events[i];
	}
}

void Level::playerOutput(ofstream &out) const {
	out << P_OPEN;
	for (unsigned int i = 0; i < this->players.size(); i++) {
		//this->players.at(i)->output(out);
	}
	out << P_CLOSE << endl;
}
