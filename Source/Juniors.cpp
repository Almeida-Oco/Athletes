#include "../Headers/Juniors.h"
#include "../Headers/utilities.h"
#include <algorithm>
using namespace std;



/*
*This function adds a new player to the vector of players
*parameter : player - player to be added to the list
*Returns true if insert operation was successfuland false if not
*/
bool Juniors::addPlayer(Player * player){
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
void Juniors::showplayers() const {
	cout << "Juniors - Players" << endl;
	Level::showplayers();
}

/*
* This function shows the list of trainings on the screen
*/
void Juniors::showtrainings() const {
	cout << "Juniors - Trainings" << endl;
	Level::showtrainings();
}

/*
* This function shows the list of tournaments on the screen
*/
void Juniors::showtournaments() const {
	cout << "Juniors - Tournaments" << endl;
	Level::showtournaments();
}


/*
*This function returns the score that is going to be used to make the call of the players for a tournament
* parametes: player - player whose score is going to be computed
* return value score of the player
*/
unsigned int Juniorscallscore(const Player & player) {
	return player.getAssiduity() + 2 * player.getPresences_games() +  5* player.getPresences_stournaments();
}

/*
*This function compares the scores of two players
*parameters: Player_left, Player_right - players whose score is going to be compared
*return value: true if Player_left score is smaller than Player_right score
*/
bool Juniorscomp(const Player & Player_left, const Player & Player_right) {
	if (Juniorscallscore(Player_left) == Juniorscallscore(Player_right)) {
		return Player_left.getBirth() < Player_right.getBirth();
	}
	else {
		return Juniorscallscore(Player_left) > Juniorscallscore(Player_right);
	}
}

/*
* This function makes the call for a major tournament
*parameter: size - number of players that are going to be called
* Return value: vector with the names of the players that are going to be called
*/
vector<string> Juniors::getCall(unsigned int size) {
	vector<Player *> vector_players_pointers = this->getPlayers();//vector of pointers to players
	vector<Player> vector_players;//vector of players
	for (unsigned int i = 0; i < vector_players_pointers.size(); i++) {
		vector_players.push_back(*vector_players_pointers[i]);
	}
	sort(vector_players.begin(), vector_players.end(), Juniorscomp);
	vector<string> names;//vector with the names of the players
	unsigned int counter = 0;//counts the number of players in the vector
	Date current_date;//current date
	for (unsigned int i = 0; i<vector_players.size() && counter<size; i++) {
		if (vector_players[i].checkECG(current_date)) {
			names.push_back(vector_players[i].getName());
			counter++;
		}
	}
	return names;
}