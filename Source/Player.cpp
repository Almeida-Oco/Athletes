#include "../Headers/Player.h"
#include"../Headers/utilities.h"

using namespace std;


Player::Player() :
		name("") ,  birth(Date(0,0,0)) ,last_eletro(Date(0,0,0)) , height(0) , assiduity(0){};//default constructor


Player::Player(string name, Date birth_date, Date eletro , unsigned int height, unsigned int assi) :
	 name(name) , birth(birth_date) , last_eletro(eletro) , height(height) , assiduity(assi) {};


/*
parameter: ostream & out - ostream where player is going to be written
parameter: const Player & player - player
Writes the player passed as a parameter in out
*/

ostream & operator<<(ostream& out, const Player &player){
	out << player.getName() << " ; " << player.getBirth() <<" ; "<<player.getLast_Eletro() <<" ; "<<player.getHeight() <<" ; ";
	out << player.getAssiduity();
	return out;
}

/*
parameter: istream & in - istream from where date is going to be read
parameter: Date & date - variable where the date extracted from stream is going to be stored
Reads date from istream
*/
istream &operator>>(istream &in, Player &player){
	char semicolon;//semicolon that exists in the file
	string name;//name of the player
	getline(in, name, ';');
	player.name = removeSpaces(name);
	in>>player.birth;
	in>>semicolon;
	in>>player.last_eletro;
	in>>semicolon;
	in>>player.height;
	in>>semicolon;
	in>>player.assiduity;
	getline(in,name); //TO CONSUME THE \n
	return in;

}
