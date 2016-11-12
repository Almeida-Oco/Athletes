#include "../Headers/Club.h"
#include "../Headers/menus.h"

int main(){
	Club * club=Club::getinstance();//gets new instance of class Vendemaismais
	
 
	if (readplayers() != 0) {
		return 1;//this means that the program caught an exception
	}
	if (club->getleaveprogram()){
		return 1;//leaves the program
	}


	if (readtrainings() != 0) {
		return 1;//this means that the program caught an exception
	}
	if (club->getleaveprogram()){
		return 1;//leaves the program
	}


	if (readtournaments() != 0) {
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
