#include "../Headers/Player.h"
#include <iostream>
#include"../Headers/utilities.h"
using namespace std;

/*void Player::output(ofstream &out) const{
	out << this->getName() <<
					SEPARATOR << this->getHeight() <<
					SEPARATOR << this->getEletro() <<
					SEPARATOR << this->getCheck() <<
					SEPARATOR << this->getYear().getDay() <<
					SEPARATOR << this->getYear().getMonth() <<
					SEPARATOR << this->getYear().getYear();
}*/

/*
parameter: ostream & out - ostream where player is going to be written
parameter: const Player & player - player
Writes the player passed as a parameter in out
*/
ostream & operator<<(ostream& out, const Player & player){
	out<<player.name<<" ; "<<player.birth<<" ; "<<player.last_eletro<<" ; "<<player.height<<" ; ";
	out<<player.assiduity<<" ; "<<player.presences_games<<" ; "<<player.presences_stournaments;
	return out;
}
/*
parameter: istream & in - istream from where date is going to be read
parameter: Date & date - variable where the date extracted from stream is going to be stored
Reads date from istream
*/
istream& operator>>(istream& in, Player & player){
	char semicolon;//semicolon that exists in the file
	string name;//name of the player
	getline(in, name ,';');
	player.name=removespaces(name);
	in>>player.birth;
	in>>semicolon;
	in>>player.last_eletro;
	in>>semicolon;
	in>>player.height;
	in>>semicolon;
	in>>player.assiduity;
	in>>semicolon;
	in>>player.presences_games;
	in>>semicolon;
	in>>player.presences_stournaments;
	return in;

}
