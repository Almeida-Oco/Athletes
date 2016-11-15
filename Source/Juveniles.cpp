#include "../Headers/Juveniles.h"
#include "../Headers/utilities.h"
#include <fstream>
using namespace std;


void Juveniles::playerOutput(ofstream &out) const{
	out << JUV_ID << endl;
	Level::playerOutput(out);
}

/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Juveniles::addPlayer(Player * player){
	unsigned int age=actualage(player->getBirth());
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
void Juveniles::showplayers() const {
	cout << "Juveniles - Players" << endl;
	Level::showplayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Juveniles::showtrainings() const {
	cout << "Juveniles - Trainings" << endl;
	Level::showtrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Juveniles::showtournaments() const {
	cout << "Juveniles - Tournaments" << endl;
	Level::showtournaments();
}

