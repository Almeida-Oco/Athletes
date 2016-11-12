#include "../Headers/Juniors.h"
#include "../Headers/utilities.h"
using namespace std;

void Juniors::playerOutput(ofstream &out) const{
	out << JUN_ID << endl;
	Level::playerOutput(out);
}

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Juniors::addPlayer(Player * player){
	unsigned int age = actualAge(player->getBirth());
	if(age>=age_min && age<=age_max){
		Level::addPlayer(player);
		return true;
	}
	else{
		return false;
	}
}
