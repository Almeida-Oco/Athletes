#include "../Headers/Level.h"





using namespace std;


void Level::playerOutput(ofstream &out) const{
	out << P_OPEN;
	for (unsigned int i = 0 ; i< this->players.size() ; i++){
		this->players.at(i)->output(out);
	}
	out << P_CLOSE << endl;
}
