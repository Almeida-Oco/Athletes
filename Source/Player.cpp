#include "../Headers/Player.h"
#include"../Headers/utilities.h"

using namespace std;

/*
*This function prints the player on the screen
*/
void Player::show() const {
	cout << setw(20) << name << "|";
	cout << "     ";
	birth.show();
	cout << "|     ";
	last_eletro.show();
	cout << "|";
	cout << setw(10) << height<<"|";
	cout << setw(8) << assiduity << " |" << setw(7) << presences_games << " |" << setw(10) << presences_stournaments;
}

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
