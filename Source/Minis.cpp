#include "../Headers/Minis.h"
#include "../Headers/utilities.h"
#include <fstream>
using namespace std;

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Minis::addPlayer(Player * player){
	unsigned int age=actualage(player->getBirth());
	if(age>=age_min && age<=age_max){
		Level::addPlayer(player);
		return true;
	}
	else{
		return false;
	}
}

void Minis::playerOutput(ofstream &out) const {
	out << MINI_ID << endl;
	 Level::playerOutput(out);
}
