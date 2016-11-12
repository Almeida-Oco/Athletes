#include "../Headers/Club.h"
#include "../Headers/menus.h"
#include <iostream>

using namespace std;

int main(){
	Club *club = new Club();

	if (readplayers(club) != 0) {
		return 1;//this means that the program caught an exception
	}
	if (club->getleaveprogram()){
		return 1;//leaves the program
	}


	if (readtrainings(club) != 0) {
		return 1;//this means that the program caught an exception
	}
	if (club->getleaveprogram()){
		return 1;//leaves the program
	}


	if (readtournaments(club) != 0) {
		return 1;//this means that the program caught an exception
	}
	if (club->getleaveprogram()){
		return 1;//leaves the program
	}

	club->writeplayers();
	club->writetrainings();


	club->writetournaments();

	return 0;


}
