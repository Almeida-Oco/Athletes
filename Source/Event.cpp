#include "../Headers/Event.h"

using namespace std;

void Event::outputNames(ofstream &fout) const{
	for (unsigned int i = 0 ; i < this->presence.size() ; i++){
		fout << this->presence.at(i)->getName();
		if (i == this->presence.size() -1)
			fout << endl;
		else
			fout << " ; ";
	}

}

void Event::addPlayer(Player *p){
	this->presence.push_back(p);
}
