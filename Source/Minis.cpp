#include "../Headers/Minis.h"
#include "../Headers/utilities.h"
using namespace std;

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Minis::addPlayer(Player * player){
	unsigned int age = actualAge(player->getBirth());
	if(age>=age_min && age<=age_max){
		return Level::addPlayer(player);
	}
	else{
		return false;
	}
}

/*
* This function shows the list of players on the screen
*/
void Minis::showPlayers() const {
	cout << "Minis - Players" << endl;
	Level::showPlayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Minis::showTrainings() const {
	cout << "Minis - Trainings" << endl;
	Level::showTrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Minis::showTournaments() const {
	cout << "Minis - Tournaments" << endl;
	Level::showTournaments();
}
