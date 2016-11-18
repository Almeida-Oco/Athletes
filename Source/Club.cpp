#include "../Headers/Club.h"
#include "../Headers/Level.h"
#include"../Headers/utilities.h"
#include "../Headers/Minis.h"
#include "../Headers/Juveniles.h"
#include "../Headers/Juniors.h"
#include "../Headers/Seniors.h"
#include "../Headers/Event.h"
#include "../Headers/Tournament.h"
#include "../Headers/Training.h"
#include "../Headers/exceptions.h"
#include <algorithm>
#include <stdlib.h>

using namespace std;

Club * Club::singleton_instance = NULL; //Initially singleton_instance points to null

/*
 * Private Default Constructor
 */
Club::Club() :
		minis(new Minis()), juveniles(new Juveniles()), juniors(new Juniors()), seniors(
				new Seniors()){
	leaveprogram = false;

}

/*
 *Private Destructor
 */
Club::~Club() {
	delete minis;
	delete juveniles;
	delete juniors;
	delete seniors;
	delete singleton_instance;
	singleton_instance = NULL;
}

/*
 Gets instance of Club Class
 */
Club * Club::getinstance() {
	if (!singleton_instance) {
		singleton_instance = new Club;
	}
	return singleton_instance;
}

/*
 *Reads players file
 *parameter: in - file where the players information is written
 */
void Club::readplayers(istream &in) {
	unsigned int size;
	in >> size;
	for (unsigned int i = 0; i < size; i++) {
		Player *p = new Player; //new player to be added to the list of players
		in >> (*p);
		if (!minis->addPlayer(p) && !juveniles->addPlayer(p) && !juniors->addPlayer(p) && !seniors->addPlayer(p)) {
			throw InvalidPlayer(p->getName(), p->getBirth());
		}
	}
}
/*
 *Reads trainings file
 *parameter: in - file where the trainings information is written
 */
void Club::readtrainings(istream &in) {
	string level_name; //name of the level that is written in the file
	string coach_name; //coach name for each category
	int n_trainings; //number of trainings for each level
	in >> level_name;
	in.ignore();//extracts the end of line
	getline(in, coach_name);
	minis->setCoach(removespaces(coach_name));
	in >> n_trainings;
	for (int i = 0; i < n_trainings; i++) {
		Training *t = new Training;
		in >> (*t);
		minis->addEvent(t);
	}

	in >> level_name;
	in.ignore();//extracts the end of line
	getline(in, coach_name);
	juveniles->setCoach(removespaces(coach_name));
	in >> n_trainings;
	for (int i = 0; i < n_trainings; i++) {
		Training *t = new Training;
		in >> (*t);
		juveniles->addEvent(t);
	}
	in >> level_name;
	in.ignore();//extracts the end of line
	getline(in, coach_name);
	juniors->setCoach(removespaces(coach_name));
	in >> n_trainings;
	for (int i = 0; i < n_trainings; i++) {
		Training *t = new Training;
		in >> (*t);
		juniors->addEvent(t);
	}
	in >> level_name;
	in.ignore();//extracts the end of line
	getline(in, coach_name);
	seniors->setCoach(removespaces(coach_name));
	in >> n_trainings;
	for (int i = 0; i < n_trainings; i++) {
		Training *t = new Training;
		in >> (*t);
		seniors->addEvent(t);
	}
}

/*
*Reads tournaments file
*parameter: in - file where the tournaments information is written
*/
void Club::readtournaments(istream & in) {
	string level_name; //name of the level that is written
	int n_tournaments; //number of tournaments for each level
	in >> level_name;
	in >> n_tournaments;
	for (int i = 0; i < n_tournaments; i++) {
		Tournament *t = new Tournament;
		in >> (*t);
		minis->addEvent(t);
	}
	in >> level_name;
	in >> n_tournaments;
	for (int i = 0; i < n_tournaments; i++) {
		Tournament *t = new Tournament;
		in >> (*t);
		juveniles->addEvent(t);
	}
	in >> level_name;
	in >> n_tournaments;
	for (int i = 0; i < n_tournaments; i++) {
		Tournament *t = new Tournament;
		in >> (*t);
		juniors->addEvent(t);
	}
	in >> level_name;
	in >> n_tournaments;
	for (int i = 0; i < n_tournaments; i++) {
		Tournament *t = new Tournament;
		in >> (*t);
		seniors->addEvent(t);
	}
}
/*
 * Writes players in a file
 */
void Club::writeplayers() {
	ofstream out; //file
	out.open(filename_players);
	vector<Player *> minis_players = minis->getPlayers();
	vector<Player *> juveniles_players = juveniles->getPlayers();
	vector<Player *> juniors_players = juniors->getPlayers();
	vector<Player *> seniors_players = seniors->getPlayers();
	out
			<< minis_players.size() + juveniles_players.size()
					+ juniors_players.size() + seniors_players.size() << "\n";
	for (unsigned int i = 0; i < minis_players.size(); i++) {
		out << *minis_players[i] << "\n";
	}
	for (unsigned int i = 0; i < juveniles_players.size(); i++) {
		out << *juveniles_players[i] << "\n";
	}
	for (unsigned int i = 0; i < juniors_players.size(); i++) {
		out << *juniors_players[i] << "\n";
	}
	for (unsigned int i = 0; i < seniors_players.size(); i++) {
		out << *seniors_players[i] << "\n";
	}
}

/*
 * Writes trainings in a file
 */
void Club::writetrainings() {
	ofstream out; //file
	out.open(filename_trainings);
	vector<Event *> minis_events = minis->getEvents();
	vector<Event *> juveniles_events = juveniles->getEvents();
	vector<Event *> juniors_events = juniors->getEvents();
	vector<Event *> seniors_events = seniors->getEvents();
	out << "Minis\n" << minis->getCoach() << "\n";
	unsigned int count = 0;
	for (unsigned int i = 0; i < minis_events.size(); i++) {
		count = count + minis_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < minis_events.size(); i++) {
		if (minis_events[i]->Istraining()) {
			minis_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Juveniles\n" << juveniles->getCoach() << "\n";
	count = 0;
	for (unsigned int i = 0; i < juveniles_events.size(); i++) {
		count = count + juveniles_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < juveniles_events.size(); i++) {
		if (juveniles_events[i]->Istraining()) {
			juveniles_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Juniors\n" << juniors->getCoach() << "\n";
	count = 0;
	for (unsigned int i = 0; i < juniors_events.size(); i++) {
		count = count + juniors_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < juniors_events.size(); i++) {
		if (juniors_events[i]->Istraining()) {
			juniors_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Seniors\n" << seniors->getCoach() << "\n";
	count = 0;
	for (unsigned int i = 0; i < seniors_events.size(); i++) {
		count = count + seniors_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < seniors_events.size(); i++) {
		if (seniors_events[i]->Istraining()) {
			seniors_events[i]->writetofile(out);
			out << "\n";
		}
	}
}

/*
 * Writes tournaments in a file
 */
void Club::writetournaments() {
	ofstream out; //file
	out.open(filename_tournaments);
	vector<Event *> minis_events = minis->getEvents();
	vector<Event *> juveniles_events = juveniles->getEvents();
	vector<Event *> juniors_events = juniors->getEvents();
	vector<Event *> seniors_events = seniors->getEvents();
	out << "Minis\n";
	unsigned int count = 0;
	for (unsigned int i = 0; i < minis_events.size(); i++) {
		count = count + !minis_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < minis_events.size(); i++) {
		if (!minis_events[i]->Istraining()) {
			minis_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Juveniles\n";
	count = 0;
	for (unsigned int i = 0; i < juveniles_events.size(); i++) {
		count = count + !juveniles_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < juveniles_events.size(); i++) {
		if (!juveniles_events[i]->Istraining()) {
			juveniles_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Juniors\n";
	count = 0;
	for (unsigned int i = 0; i < juniors_events.size(); i++) {
		count = count + !juniors_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < juniors_events.size(); i++) {
		if (!juniors_events[i]->Istraining()) {
			juniors_events[i]->writetofile(out);
			out << "\n";
		}
	}
	out << "Seniors\n";
	count = 0;
	for (unsigned int i = 0; i < seniors_events.size(); i++) {
		count = count + !seniors_events[i]->Istraining();
	}
	out << count << "\n";
	for (unsigned int i = 0; i < seniors_events.size(); i++) {
		if (!seniors_events[i]->Istraining()) {
			seniors_events[i]->writetofile(out);
			out << "\n";
		}
	}
}

/*
* returns a vector with thes name of all the players in the club. It also includes players that participated in certain events and were later removed
* Return value- vector with the names of all the players in the club
*/
vector<string> Club::getPlayers() const {
	vector<string> rplayers;//vector with the names of the players that is going to be returned
	vector<Level *> vector_levels = this->getLevels();//gets vector of pointers to the existent levels
	for (unsigned int i = 0; i < 4; i++) {
		vector<Player *>vector_players = vector_levels[i]->getPlayers();//gets vector of pointers to the existent players
		for (unsigned int j = 0; j < vector_players.size(); j++) {
			if (find(rplayers.begin(), rplayers.end(), vector_players[j]->getName()) == rplayers.end()) {
				rplayers.push_back(vector_players[j]->getName());
			}
		}
		vector<Event *> vector_events = vector_levels[i]->getEvents();//gets vector of pointers to the existent events
		for (unsigned int j = 0; j < vector_events.size(); j++) {
			vector<string> vector_presences = vector_events[j]->getPresences();//gets vector with the names of the players that participated in a tournament
			for (unsigned int k = 0; k < vector_presences.size(); k++) {
				if (find(rplayers.begin(), rplayers.end(), vector_presences[k]) == rplayers.end()) {
					rplayers.push_back(vector_presences[k]);
				}
			}
		}
	}
	
	sort(rplayers.begin(), rplayers.end());
	return rplayers;
}



