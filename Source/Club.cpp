#include "../Headers/Club.h"
#include "../Headers/utilities.h"
#include "../Headers/Minis.h"
#include "../Headers/Juveniles.h"
#include "../Headers/Juniors.h"
#include "../Headers/Seniors.h"
#include "../Headers/Event.h"
#include "../Headers/Tournament.h"
#include "../Headers/Training.h"
#include "../Headers/exceptions.h"

using namespace std;

/*
 * Public Default Constructor
 */
Club::Club() :
		minis(new Minis()), juveniles(new Juveniles()), juniors(new Juniors()), seniors(new Seniors()), current_date(Date()) {};


/*
 *Public Destructor
 */
Club::~Club() {
	delete minis;
	delete juveniles;
	delete juniors;
	delete seniors;
}


/*
 *Reads players file
 *parameter: in - file where the players information is written ,  lvl - what lvl it is (Minis = 1,Juv =2,Jun=3,Sen=4)
 */
void Club::readPlayers(ifstream &in, unsigned int lvl) {
	unsigned int size;
	string line, coach;
	getline(in,coach);
	if (lvl == 1)
		this->minis->setCoach(removeSpaces(coach));
	else if (lvl == 2)
		this->juveniles->setCoach(removeSpaces(coach));
	else if (lvl == 3)
		this->juniors->setCoach(removeSpaces(coach));
	else if (lvl == 4)
		this->seniors->setCoach(removeSpaces(coach));

	getline(in,line);
	size = atoi(line.c_str());
	for (unsigned int i = 0; i < size; i++) {
		Player *p = new Player; //new player to be added to the list of players
		in >> (*p);
		//scout << *p << endl;
		if (!( (lvl == 1 && this->minis->addPlayer(p)) || (lvl == 2 && this->juveniles->addPlayer(p)) ||
				(lvl == 3 && this->juniors->addPlayer(p)) || (lvl == 4 && this->seniors->addPlayer(p))))
			throw InvalidPlayer(p->getName() , p->getBirth());
		
	}
}
/*
 *Reads trainings file
 *parameter: in - file where the trainings information is written, lvl - what lvl it is (Minis = 1,Juv =2,Jun=3,Sen=4)
 */
void Club::readTrainings(ifstream &in, unsigned int lvl) {
	string placeholder; //name of the level that is written in the file
	int n_trainings; //number of trainings for each level

	getline(in,placeholder);
	n_trainings = atoi(placeholder.c_str());
	for (int i = 0; i < n_trainings; i++) {
		Training *t = new Training();
		in >> (*t);
		//NOW WILL READ PLAYERS PRESENT
		assignPlayers(in , lvl , t);
		//cout << (*t) << endl;
		if (lvl == 1)
			this->minis->addEvent(t);
		else if (lvl == 2)
			this->juveniles->addEvent(t);
		else if (lvl == 3)
			this->juniors->addEvent(t);
		else if (lvl == 4)
			this->seniors->addEvent(t);
	}
}

/*
*Reads tournaments file
*parameter: in - file where the tournaments information is written,  lvl - what lvl it is (Minis = 1,Juv =2,Jun=3,Sen=4)
*/
void Club::readTournaments(ifstream & in , unsigned int lvl) {
	int n_tournaments; //number of tournaments for each level
	string placeholder;

	getline(in,placeholder);
	n_tournaments = atoi(placeholder.c_str());

	for (int i = 0; i < n_tournaments; i++) {
		Tournament *t = new Tournament;
		in >> (*t);
		cout << *t;
		//NOW WILL READ PRESENCES
		assignPlayers(in,lvl,t);
		if (lvl == 1)
			this->minis->addEvent(t);
		else if (lvl == 2)
			this->juveniles->addEvent(t);
		else if (lvl == 3)
			this->juniors->addEvent(t);
		else if (lvl == 4)
			this->seniors->addEvent(t);
	}

}
/*
 * Writes players in a file
 */
void Club::writePlayers() {
	ofstream out; //file
	out.open(this->p_fname.c_str());

	vector<Player *> mini_p = minis->getPlayers();
	vector<Player *> juv_p = juveniles->getPlayers();
	vector<Player *> jun_p = juniors->getPlayers();
	vector<Player *> sen_p = seniors->getPlayers();

	out << this->minis->getCoach() << endl;
	out << this->minis->getPlayers().size() << endl;
	for (unsigned int i = 0; i < mini_p.size(); i++) {
		out << *mini_p[i] << endl;
	}
	out << this->juveniles->getCoach() << endl;
	out << this->juveniles->getPlayers().size() << endl;
	for (unsigned int i = 0; i < juv_p.size(); i++) {
		out << *juv_p[i] << endl;
	}
	out << this->juniors->getCoach() << endl;
	out << this->juniors->getPlayers().size() << endl;
	for (unsigned int i = 0; i < jun_p.size(); i++) {
		out << *jun_p[i] << endl;
	}
	out << this->seniors->getCoach() << endl;
	out << this->seniors->getPlayers().size() << endl;
	for (unsigned int i = 0; i < sen_p.size(); i++) {
		out << *sen_p[i] << endl;
	}
}

/*
 * Writes trainings in a file
 */
void Club::writeTrainings() {
	ofstream out; //file
	out.open(this->tr_fname.c_str());
	vector<Event *> mini_e = minis->getEvents();
	vector<Event *> juv_e = juveniles->getEvents();
	vector<Event *> jun_e = juniors->getEvents();
	vector<Event *> sen_e = seniors->getEvents();

	out << minis->countTrainings(mini_e) << endl;
	for (unsigned int i = 0; i < mini_e.size(); i++)
		if (mini_e[i]->Istraining()){
			mini_e.at(i)->fileOutput(out);
			mini_e.at(i)->outputNames(out);
		}

	out << juveniles->countTrainings(juv_e) << endl;
	for (unsigned int i = 0; i < juv_e.size(); i++)
		if (juv_e[i]->Istraining()){
			juv_e.at(i)->fileOutput(out);
			juv_e.at(i)->outputNames(out);
		}

	out << juniors->countTrainings(jun_e) << endl;
	for (unsigned int i = 0; i < jun_e.size(); i++)
		if (jun_e[i]->Istraining()){
			jun_e.at(i)->fileOutput(out);
			jun_e.at(i)->outputNames(out);
		}

	out << seniors->countTrainings(sen_e) << endl;
	for (unsigned int i = 0; i < sen_e.size(); i++)
		if (sen_e[i]->Istraining()){
			sen_e.at(i)->fileOutput(out);
			sen_e.at(i)->outputNames(out);
		}
}

/*
 * Writes tournaments in a file
 */
void Club::writeTournaments() {
	ofstream out; //file
	out.open(this->to_fname.c_str());
	vector<Event *> mini_e = minis->getEvents();
	vector<Event *> juv_e = juveniles->getEvents();
	vector<Event *> jun_e = juniors->getEvents();
	vector<Event *> sen_e = seniors->getEvents();

	out << mini_e.size() - minis->countTrainings(mini_e) << endl;
	for (unsigned int i = 0; i < mini_e.size(); i++)
		if (!mini_e[i]->Istraining()){
			mini_e.at(i)->fileOutput(out);
			mini_e.at(i)->outputNames(out);
		}


	out << juv_e.size() - juveniles->countTrainings(juv_e) << endl;
	for (unsigned int i = 0; i < juv_e.size(); i++)
		if (!juv_e[i]->Istraining()){
			juv_e.at(i)->fileOutput(out);
			juv_e.at(i)->outputNames(out);
		}

	out << jun_e.size() - juniors->countTrainings(jun_e) << endl;
	for (unsigned int i = 0; i < jun_e.size(); i++)
		if (!jun_e[i]->Istraining()){
			jun_e.at(i)->fileOutput(out);
			jun_e.at(i)->outputNames(out);
		}

	out << sen_e.size() - seniors->countTrainings(sen_e) << endl;
	for (unsigned int i = 0; i < sen_e.size(); i++)
		if (!sen_e[i]->Istraining()){
			sen_e.at(i)->fileOutput(out);
			sen_e.at(i)->outputNames(out);
		}
}

void Club::assignPlayers(ifstream &fin , unsigned int lvl , Event *ev){
	string placeholder;
	vector<string> names;

	getline(fin,placeholder);
	names = stringSplit(placeholder,";");

	for (unsigned int i = 0 ; i < names.size() && names.at(0) != ""; i++){
		if(lvl == 1)
			ev->addPlayer(this->minis->findPlayer(removeSpaces(names.at(i))));
		else if (lvl == 2)
			ev->addPlayer(this->juveniles->findPlayer(removeSpaces(names.at(i))));
		else if (lvl == 3)
			ev->addPlayer(this->juniors->findPlayer(removeSpaces(names.at(i))));
		else if (lvl == 4)
			ev->addPlayer(this->seniors->findPlayer(removeSpaces(names.at(i))));
	}

	cout << "DONE PLAYERS " << endl;
}
