#include "../Headers/Seniors.h"
#include "../Headers/Level.h"
#include "../Headers/Globals.h"
#include "../Headers/utilities.h"
#include <fstream>
using namespace std;

void Seniors::playerOutput(ofstream &out) const {
	out << SEN_ID << endl;
	Level::playerOutput(out);
}

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Seniors::addPlayer(Player * player){
	unsigned int age = actualAge(player->getBirth());
	if(age>=age_min && age<=age_max){
		Level::addPlayer(player);
		return true;
	}
	else{
		return false;
	}
}
