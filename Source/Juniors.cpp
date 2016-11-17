#include "../Headers/Juniors.h"
#include "../Headers/utilities.h"
using namespace std;

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Juniors::addPlayer(Player * player){
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
void Juniors::showPlayers() const {
	cout << "Juniors - Players" << endl;
	Level::showPlayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Juniors::showTrainings() const {
	cout << "Juniors - Trainings" << endl;
	Level::showTrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Juniors::showTournaments() const {
	cout << "Juniors - Tournaments" << endl;
	Level::showTournaments();
}
