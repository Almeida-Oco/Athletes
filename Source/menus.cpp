#include "../Headers/menus.h"
#include "../Headers/Club.h"
#include "../Headers/exceptions.h"
#include "../Headers/utilities.h"
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
			file_players.open(filename_players.c_str());
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

/*
This function gets information from the trainings file into the vector clients
*/
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
			file_trainings.open(filename_trainings.c_str());
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

/*
This function gets information from the tournaments file into the vector clients
*/
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
			file_tournaments.open(filename_tournaments.c_str());
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

/*
* This function asks the user for a date
* Returns the date typed by the user
*/
Date askfordate() {
	unsigned int year_date, month_date, day_date;//year month and day of the date
	bool repeat = true;//this boolean will be set to true when the cycles that ask the user for the elements of the dates should be repeated
	//The following loop asks the user for the year of the date
	while (repeat) {
		cout << "Date year(press c to cancel): ";
		string year;//year that's going to be typed by the user
		cin.clear();
		getline(cin, year);
		if (isInteger(year) && convint(year) >= 0) {
			year_date = convint(year);
			repeat = false;
		}
		else if (year == "c") {
			return Date(0, 0, 0);
		}
		else {
			cout << "That year is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the month of the first date
	while (repeat) {
		cout << "Date month(press c to cancel): ";
		string month;//month that is going to be typed by the user
		cin.clear();
		getline(cin, month);
		if (isInteger(month) && convint(month) >= 1 && convint(month) <= 12) {
			month_date = convint(month);
			repeat = false;
		}
		else if (month == "c") {
			return Date(0, 0, 0);
		}
		else {
			cout << "That month is not valid" << endl;
		}
	}
	repeat = true;
	//The following loop asks the user for the day of the first date
	while (repeat) {
		cout << "Date day(press c to cancel): ";
		string day;//day that is going to be typed by the user
		cin.clear();
		getline(cin, day);
		if (isInteger(day) && convint(day) >= 1 && convint(day) <= 31) {
			day_date = convint(day);
			unsigned int months[13] = { 0, 31,28 + Isleap(year_date),31,30,31,30,31,31,30,31,30,31 };//array with the number of days in each month
			if ((month_date>12) || (day_date > months[month_date])) {
				cout<< "That day is not valid" << endl;
			}
			else {
				repeat = false;
			}
		}
		else if (day == "c") {
			return Date(0, 0, 0);
		}
		else {
			cout << "That day is not valid" << endl;
		}
	}
	return Date(day_date, month_date, year_date);
}

/*
* This function prints the level that corresponds to the number level
* parameter : level - number that corresponds to the level (0->Minis, 1->Juveniles...)
*/
void printlevel(unsigned int level) {
	switch (level) {
	case 0:
		cout << "Minis" << endl;
		break;
	case 1:
		cout << "Juveniles" << endl;
		break;
	case 2:
		cout << "Juniors" << endl;
		break;
	case 3:
		cout << "Seniors" << endl;
		break;
	}
}

/*
Displays the initial menu on the sceen and asks the user to choose an option
Then, directs the user to the option he chose
*/

void initialmenu() {
	Club *club = Club::getinstance();//gets intance of class Club
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");// clears the screen
			cout << "INITIAL MENU - Club\n" << endl;
			if (errormessage) {
				cout << "The option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Minis" << endl;
			cout << "2: Juveniles" << endl;
			cout << "3: Juniors" << endl;
			cout << "4: Seniors" << endl;
			cout << "5: Register new player" << endl;
			cout << "6: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				levelmenu(0);
				repeatmenu = false;
				break;
			case 2:
				levelmenu(1);
				repeatmenu = false;
				break;
			case 3:
				levelmenu(2);
				repeatmenu = false;
				break;
			case 4:
				levelmenu(3);
				repeatmenu = false;
				break;
			case 5:
				regnewplayermenu();
				break;
			case 6:
				repeatmenu = false;
				club->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!club->getleaveprogram());

}

/*
* This function displays the main menu for each level(minis, juveniles, juniors, seniors). Then directs the user to the option he chose.
* parameter: level (0-> minis, 1->juveniles...)
* 
*/
void levelmenu(unsigned int level) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");// clears the screen
			printlevel(level);
			cout <<"Coach: "<<club_levels[level]->getCoach()<<"\n\n";
			if (errormessage) {
				cout << "The option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Players" << endl;
			cout << "2: Trainings" << endl;
			cout << "3: Tournaments" << endl;
			cout << "4: Next Events" << endl;
			cout << "5: Back" << endl;
			cout << "6: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				playersmenu(level);
				repeatmenu = false;
				break;
			case 2:
				trainingsmenu(level);
				repeatmenu = false;
				break;
			case 3:
				tournamentsmenu(level);
				repeatmenu = false;
				break;
			case 4:
				repeatmenu = false;
				break;
			case 5:
				backflag = true;
				repeatmenu = false;
				break;
			case 6:
				repeatmenu = false;
				club->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while(!backflag && !club->getleaveprogram());
}

/*
* displays the menu with the information of the players
* parameter: level (0-> minis, 1->juveniles...)
*
*/
void playersmenu(unsigned int level) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");// clears the screen
			club_levels[level]->showPlayers();
			if (errormessage) {
				cout << "The ID you introduced is not valid " << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "\nType the ID of the Player you are interested in (or press b to go back):";
			string id;//id to be typed by the user;
			cin.clear();
			getline(cin, id);
			if (id[0] == 'b' && id.size() == 1) {
				backflag = true;
				repeatmenu = false;
			}
			else {
				vector<Player *> vector_players = club_levels[level]->getPlayers();//gets vector of players of the chosen level
				if (convint(id) <= vector_players.size() && convint(id) >= 1) {
					individualplayermenu(level, convint(id));
					repeatmenu = false;
				}
				else {
					errormessage = true;
				}
				
			}
		}
	} while (!backflag && !club->getleaveprogram());
}


/*
*displays a menu with the information of an individual player
*/
void individualplayermenu(unsigned int level, unsigned int id) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	vector<Player *> vector_players = club_levels[level]->getPlayers();//gets vector of players of the chosen level
	Player * player = vector_players[id-1];//gets pointer to the chosen player
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");
			cout << "Name: " << player->getName() << endl;
			cout << "Level: ";
			printlevel(level);
			cout << "Birthday: " << player->getBirth() << endl;
			cout << "Last ECG date: " << player->getLast_Eletro() << endl;
			cout << "Height: " << player->getHeight() << endl;
			cout << "Assiduity: " << player->getAssiduity() << endl;
			cout << "Presences in Trainings Games: " << player->getPresences_games() << endl;
			cout << "Presences in Small Tournaments: " << player->getPresences_stournaments() << endl;
			cout << "\n";
			if (errormessage) {
				cout << "The option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Actualize Last ECG date" << endl;
			cout << "2: Actualize Height" << endl;
			cout << "3: Remove Player" << endl;
			cout << "4: Back" << endl;
			cout << "5: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				actualizeECG(level, id);
				repeatmenu = false;
				break;
			case 2:
				actualizeheight(level, id);
				repeatmenu = false;
				break;
			case 3:
				removeplayer(level, id);
				repeatmenu = false;
				backflag = true;
				break;
			case 4:
				backflag = true;
				repeatmenu = false;
				break;
			case 5:
				club->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				repeatmenu = false;
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!backflag && !club->getleaveprogram());
}

/*
Actualizes ECG date
*/
void actualizeECG(unsigned int level, unsigned int id) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	vector<Player *> vector_players = club_levels[level]->getPlayers();//gets vector of players of the chosen level
	Player * player = vector_players[id-1];//gets pointer to the chosen player
	system("cls");//clears the screen
	cout << "Name: " << player->getName() << endl;
	cout << "Level: ";
	printlevel(level);
	cout << "Actualize ECG date" << endl;
	Date date = askfordate();
	if (date.getDay() != 0) {
		player->setLast_Eletro(date);
	}
}

/*
Actualizes the height of a player
*/
void actualizeheight(unsigned int level, unsigned int id) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	vector<Player *> vector_players = club_levels[level]->getPlayers();//gets vector of players of the chosen level
	Player * player = vector_players[id-1];//gets pointer to the chosen player
	bool cancelflag = false;//if true it is going cancel
	bool errormessage = false;//if true it's going to display an errormessage
	while (!cancelflag) {
		system("cls");//clears the screen
		cout << "Name: " << player->getName() << endl;
		cout << "Level: ";
		printlevel(level);
		cout << "Actualize Height" << endl;
		if (errormessage) {
			cout << "The height you introduced is not valid" << endl;
		}
		cout << "Introduce the player current height in cm(or press c to cancel): ";
		string height;//height to be typed by the user;
		cin.clear();
		getline(cin, height);
		if (height=="c") {
			cancelflag = true;
		}
		else if (convint(height) > 0) {
			player->setHeight(convint(height));
			cancelflag = true;
		}
		else {
			errormessage = true;
		}
	}
}

/*
Removes a player from the team
*/
void removeplayer(unsigned int level,unsigned int id) {

	system("cls");
	cout << "Are you sure you want to remove " << Club::getinstance()->getLevels().at(level)->getPlayers().at(id-1)->getName() << " from the team ?" << endl;
	cout << "Press y for yes and any other key for no: ";
	string key;
	getline(cin, key);
	if (key[0] == 'y')
		Club::getinstance()->getLevels().at(level)->removePlayer
		( Club::getinstance()->getLevels().at(level)->getPlayers().at(id-1)->getName());
}

/*
menu that allows the user to register a new player on the team
*/
void regnewplayermenu() {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	bool cancelflag = false;//if true it is going cancel
	bool errormessage = false;//if true it's going to display an errormessage
	bool successflag = false;//if true it means that the user was able to introduce the input successfully
	string player_name;//name of the player
	Date player_birth, player_last_eletro;//date of birth and date of last ECG of the player
	unsigned int player_height;
	system("cls");
	while (!cancelflag && !successflag) {
		if (errormessage) {
			cout << "The name you introduced is not valid" << endl;
		}
		cout << "Type the name of the new player. It must be between 4 and 20 characters (or press c to cancel): ";
		string name;
		getline(cin, name);
		if (name == "c") {
			cancelflag = true;
		}
		else if ((name.size() >= 4) && (name.size() <= 20)) {
			vector<string> vector_players = club->getPlayers();
			player_name = removespaces(name);
			if ( find(vector_players.begin() , vector_players.end() , player_name) == vector_players.end())
				successflag = true;
			else {
				cout << "There is already a player on the team with the same name." << endl;
			}
		}
		else {
			errormessage = true;
		}
	}

	
	if (!cancelflag) {
		cout << "\nIntroduce the date when the player was born" << endl;
		player_birth = askfordate();
		if (player_birth.getDay() == 0) {
			cancelflag = true;
		}
	}

	
	if (!cancelflag) {
		cout << "\nIntroduce the day when the player realized is last ECG." << endl;
		cout << "Note: He must have realized at least one exam in order to be admited to the team" << endl;
		player_last_eletro = askfordate();
		if (player_birth.getDay() == 0) {
			cancelflag = true;
		}
	}
	errormessage = false;
	successflag = false;
	cout << "\n";
	while (!cancelflag && !successflag) {
		if (errormessage) {
			cout << "The height you introduced is not valid" << endl;
		}
		cout << "Type the height of the new player(press c to cancel): ";
		string height;
		getline(cin, height);
		if (convint(height) >= 0) {
			player_height = convint(height);
			successflag = true;
		}
		else if (height == "c") {
			cancelflag = true;
		}
		else {
			errormessage = true;
		}
	}
	if (!cancelflag) {
		Player * p = new Player(player_name, player_birth, player_last_eletro, player_height);
		
		if (club_levels[0]->addPlayer(p)) {
			cout << player_name << " was registered on the team."<<endl;
			cout << "He is now part of the Minis team."<<endl;
			cout << "Press any keys to leave: ";
			string keys;
			getline(cin, keys);
		}
		else if (club_levels[1]->addPlayer(p)) {
			cout << player_name << " was registered on the team."<<endl;
			cout << "He is now part of the Juveniles team."<<endl;
			cout << "Press any keys to leave: ";
			string keys;
			getline(cin, keys);
		}
		else if (club_levels[2]->addPlayer(p)) {
			cout << player_name << " was registered on the team."<<endl;
			cout << "He is now part of the Juniors team."<<endl;
			cout << "Press any keys to leave: ";
			string keys;
			getline(cin, keys);
		}
		else if (club_levels[3]->addPlayer(p)) {
			cout << player_name << " was registered on the team. "<<endl;
			cout << "He is now part of the Seniors team. "<<endl;
			cout << "Press any keys to leave: ";
			string keys;
			getline(cin, keys);
		}
		else {
			cout << "The player couldn't be registered on the team. He is too young" << endl;
			cout << "Press any keys to leave: ";
			string keys;
			getline(cin, keys);
		}
	}
}

/*
* displays the menu with information of the trainings
*/
void trainingsmenu(unsigned int level) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");// clears the screen
			club_levels[level]->showTrainings();
			if (errormessage) {
				cout << "\nThe ID you introduced is not valid " << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "\nType the ID of the Training you are interested in (or press b to go back):";
			string id;//id to be typed by the user;
			cin.clear();
			getline(cin, id);
			if (id[0] == 'b' && id.size() == 1) {
				backflag = true;
				repeatmenu = false;
			}
			else {
				vector<Event *> vector_trainings = club_levels[level]->getTrainings();//gets vector of trainings of the chosen level
				Date current_date;//current date
				if (convint(id) <= vector_trainings.size() && convint(id) >= 1 && vector_trainings[convint(id)-1]->getDay()<current_date) {
					individualtrainingmenu(level, convint(id));
					repeatmenu = false;
				}
				else {
					errormessage = true;
				}

			}
		}
	} while (!backflag && !club->getleaveprogram());
}


/*
* displays the menu with information of the tournaments
*/
void tournamentsmenu(unsigned int level) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");// clears the screen
			club_levels[level]->showTournaments();
			if (errormessage) {
				cout << "\nThe ID you introduced is not valid " << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "\nType the ID of the Tournament you are interested in (or press b to go back):";
			string id;//id to be typed by the user;
			cin.clear();
			getline(cin, id);
			if (id[0] == 'b' && id.size() == 1) {
				backflag = true;
				repeatmenu = false;
			}
			else {
				vector<Event *> vector_tournaments = club_levels[level]->getTournaments();//gets vector of tournaments of the chosen level
				Date current_date;//current date
				if (convint(id) <= vector_tournaments.size() && convint(id) >= 1 && vector_tournaments[convint(id) - 1]->getDay()<current_date) {
					individualtournamentmenu(level, convint(id));
					repeatmenu = false;
				}
				else {
					errormessage = true;
				}

			}
		}
	} while (!backflag && !club->getleaveprogram());
}

/*
*displays the menu with the individual information of a certain training
*/
void individualtrainingmenu(unsigned int level, unsigned int id) {
	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	vector<Event *> vector_trainings = club_levels[level]->getTrainings();//gets vector of trainings of the chosen level
	Event * training = vector_trainings[id - 1];//gets pointer to the chosen training
	bool backflag = false;//When set to true this boolean stop the main cycle in this function and make the program go back
	do {
		bool errormessage = false;//If true will display an error message
		bool repeatmenu = true;//If true will keep showing the initial menu to the user and asking him to type an option
		while (repeatmenu) {
			system("cls");
			cout << "Training" << endl;
			cout << "Date: " << training->getDay() << endl;
			cout << "Level: ";
			printlevel(level);
			cout << "Training Game: ";
			if (training->getGame()) {
				cout << " Yes" << endl;
			}
			else {
				cout << " No" << endl;
			}
			cout << "\nPlayers that participated in this training:" << endl;
			vector<string> vector_presences = training->getPresences();
			for (unsigned int i = 0; i < vector_presences.size(); i++) {
				cout << vector_presences[i]<<endl;
			}
			if (errormessage) {
				cout << "\nThe option you introduced is not valid \n" << endl;//tells the user the option he had previously introduced is not valid
			}
			cout << "1: Edit the players that participated in the training" << endl;
			cout << "2: Back" << endl;
			cout << "3: Leave" << endl;
			cout << "Type the option number: ";
			string option;//option to be chosen by the user
			cin.clear();
			getline(cin, option);
			switch (convint(option))
			{
			case 1:
				editplayerstraining(level, training);
				repeatmenu = false;
				break;
			case 2:
				backflag = true;
				repeatmenu = false;
				break;
			case 3:
				club->setleaveprogram(true);//sets leaveprogram to true so that the program can end when it leaves this function
				repeatmenu = false;
				break;
			default:
				errormessage = true;//sets errormessage to true to show an error message to the user when this cycle is repeated
			}
		}
	} while (!backflag && !club->getleaveprogram());
	
}

void editplayerstraining(unsigned int level, Event * ev){

	Club *club = Club::getinstance();//gets intance of class Club
	vector<Level *> club_levels = club->getLevels();//gets pointers to levels of the club
	vector<Player *> vector_players = club_levels[level]->getPlayers();//gets vector of players of the chosen level
	vector<bool> alreadychosen(vector_players.size(), false); //each entry of this vector will be set to true if the player that is in the same position of that entry was already chosen
	bool repeatquestion = true;//if set to true it will repeat the question asking the user to select a player
	vector<string > participant_players;//vector with the players that participated in the tournament


	system("cls");//clears screen
	cout << "Edit Players that participated in the Training" << endl;
	club_levels[level]->showPlayers();//shows players that participated in the training

	while (repeatquestion)
	{   
		cout << "\nType the ID of the player a that was present in the training (or press f if you have already chosen all the players that participated in the training): ";
		string id;//player typed by the user
		cin.clear();
		getline(cin, id);

		if (id=="f")
			repeatquestion = false;
		else if (convint(id) <= 0 || (convint(id))>vector_players.size()) //checks if it was typed a valid player
			cout << "The player you selected is not valid" << endl;
		else if (alreadychosen[convint(id) - 1]) //checks if the player has already been chosen
			cout << "You have already selected that player" << endl;
		else {
			alreadychosen[convint(id) - 1] = true;
			participant_players.push_back(vector_players[convint(id)-1]->getName());
		}
	}

	club_levels[level]->lowerAssiduity(ev->getPresences() , 1 + ev->getGame());
	club_levels[level]->raiseAssiduity(participant_players , 1 + ev->getGame());
	ev->setPresences(participant_players);
}
/*
*displays the menu with the individual information of a certain tournament
*/
void individualtournamentmenu(unsigned int level, unsigned int id) {

}
