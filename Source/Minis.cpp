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
		return Level::addPlayer(player);
	}
	else{
		return false;
	}
}

/*
* This function shows the list of players on the screen
*/
void Minis::showplayers() const {
	cout << "Minis - Players" << endl;
	Level::showplayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Minis::showtrainings() const {
	cout << "Minis - Trainings" << endl;
	Level::showtrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Minis::showtournaments() const {
	cout << "Minis - Tournaments" << endl;
	Level::showtournaments();
}



void Minis::playerOutput(ofstream &out) const {
	out << MINI_ID << endl;
	 Level::playerOutput(out);
}
