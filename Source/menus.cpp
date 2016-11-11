#include "../Headers/menus.h"
#include "../Headers/Club.h"
#include "../Headers/exceptions.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
 This function gets information from the clients file into the vector clients
 */
int readplayers() {
	Club *club = Club::getinstance(); //gets intance of class Club
	ifstream file_players; //players file
	string filename_players; //name of the file with the players
	bool errormessage = false; //if true it will display an error message
	do {
		if (errormessage) {
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
		errormessage = true;
		cout<< "Introduce the path of the file with the players (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_players);
		if ((filename_players.size() == 1) && (filename_players[0] == 'l')) {
			club->setleaveprogram(true);
		} else {
			file_players.open(filename_players);
		}
	} while (file_players.fail() && !club->getleaveprogram());
	if (!club->getleaveprogram()) {
		club->setfilename_players(filename_players); //sets a new clients filename
		try {
			club->readplayers(file_players); //reads players
		}
		catch (InvalidDate & d) {
			cout << "This date is not valid: ";
			d.show();
			cout << "\nThe file is corrupted";
			system("PAUSE");
			return 1;
		}
		catch (InvalidPlayer & p) {
			p.show();
			system("PAUSE");
			return 1;
		}
	}
	return 0;
}

int readtrainings() {
	Club *club = Club::getinstance(); //gets intance of class Club
	ifstream file_trainings; //players file
	string filename_trainings; //name of the file with the trainings
	bool errormessage = false; //if true it will display an error message
	do {
		if (errormessage) {
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
		errormessage = true;
		cout<< "Introduce the path of the file with the trainings (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_trainings);
		if ((filename_trainings.size() == 1)
				&& (filename_trainings[0] == 'l')) {
			club->setleaveprogram(true);
		} else {
			file_trainings.open(filename_trainings);
		}
	} while (file_trainings.fail() && !club->getleaveprogram());
	if (!club->getleaveprogram()) {
		club->setfilename_trainings(filename_trainings); //sets a new clients filename
		try {
			club->readtrainings(file_trainings); //reads players
		}
		catch (InvalidDate & d) {
			cout << "This date is not valid: ";
			d.show();
			cout << "\nThe file is corrupted";
			system("PAUSE");
			return 1;
		}
	}
	return 0;
}

int readtournaments() {
	Club *club = Club::getinstance(); //gets intance of class Club
	ifstream file_tournaments; //tournaments file
	string filename_tournaments; //name of the file with the tournaments
	bool errormessage = false; //if true it will display an error message
	do {
		if (errormessage) {
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
		errormessage = true;
		cout<< "Introduce the path of the file with the tournaments (or press l if you want to leave): ";
		cin.clear();
		getline(cin, filename_tournaments);
		if ((filename_tournaments.size() == 1) && (filename_tournaments[0] == 'l')) {
			club->setleaveprogram(true);
		} else {
			file_tournaments.open(filename_tournaments);
		}
	} while (file_tournaments.fail() && !club->getleaveprogram());
	if (!club->getleaveprogram()) {
		club->setfilename_tournaments(filename_tournaments); //sets a new tournaments filename
		try {
			club->readtournaments(file_tournaments); //reads tournaments
		}
		catch (InvalidDate & d) {
			cout << "This date is not valid: ";
			d.show();
			cout << "\nThe file is corrupted";
			system("PAUSE");
			return 1;
		}
	}
	return 0;
}

