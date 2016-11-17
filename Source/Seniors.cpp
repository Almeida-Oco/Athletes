#include "../Headers/Seniors.h"
#include "../Headers/Level.h"
#include "../Headers/utilities.h"
#include <fstream>
using namespace std;

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Seniors::addPlayer(Player * player){
	unsigned int age=actualAge(player->getBirth());
	if(age>=age_min && age<=age_max){
		Level::addPlayer(player);
		return true;
	}
	else{
		return false;
	}
}

/*
* This function shows the list of players on the screen
*/
void Seniors::showPlayers() const {
	cout << "Seniors - Players" << endl;
	Level::showPlayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Seniors::showTrainings() const {
	cout << "Seniors - Trainings" << endl;
	Level::showTrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Seniors::showTournaments() const {
	cout << "Seniors - Tournaments" << endl;
	Level::showTournaments();
}
