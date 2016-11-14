#include "../Headers/Club.h"
#include "../Headers/menus.h"
#include "../Headers/exceptions.h"
#include <iostream>

using namespace std;

const unsigned int PLAYER = 1;
const unsigned int TRAINING = 2;
const unsigned int TOURNAMENT = 3;

int main(){
	Club *club = new Club();
	ifstream fin;
	string line;

	if(openFile(club,fin,PLAYER))
		return 1; // USER INSERTED "L" WHICH MEANS LEAVE PROGRAM
	else
		for(unsigned int i = 1 ; i<5 ; i++){ //I ->{1,2,3,4}, EACH NUMBER IS A LEVEL
			try{  club->readPlayers(fin,i); }

			catch (InvalidDate &d){
				cout << "Date not valid : " << d << "The file is corrupted";
				return 1;
			}
			catch (InvalidPlayer &p){
				cout << p;
				return 1;
			}
		}
	fin.close();

	if(openFile(club,fin,TRAINING))
		return 1;
	else
		for (unsigned int i = 1 ; i<5 ; i++){ //I ->{1,2,3,4}, EACH NUMBER IS A LEVEL
			try{ club->readTrainings(fin,i); }

			catch (InvalidDate &d){
				cout << "Date not valid : " << d << "The file is corrupted";
				return 1;
			}
			catch (UnexistingPlayer &p){
				cout << p;
				return 1;
			}
		}

	fin.close();

	if(openFile(club,fin,TOURNAMENT))
		return 1;
	else
		for (unsigned int i = 1 ; i<5 ; i++){ //I ->{1,2,3,4}, EACH NUMBER IS A LEVEL
		try{ club->readTournaments(fin,i); }

		catch (InvalidDate &d){
			cout << "Date not valid : " << d << "The file is corrupted";
			return 1;
		}
		catch (UnexistingPlayer &p){
			cout << p;
			return 1;
		}
	}
	fin.close();

	club->writePlayers();
	club->writeTrainings();
	club->writeTournaments();


	return 0;


}
