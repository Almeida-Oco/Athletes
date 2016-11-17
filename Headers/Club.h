#ifndef CLUB_H
#define CLUB_H

#include "../Headers/Date.h"
#include "../Headers/Level.h"
#include <set>
#include <string>
#include <stdlib.h>
#include <fstream>

class Club{

	Level * minis;
	Level * juveniles;
	Level * juniors ;
	Level * seniors;
	Date current_date;
	//Date end_of_season;
	bool leaveprogram;//boolean that will tell the program when to leave
	static Club * singleton_instance;//pointer to instance of class Club
	string filename_players;//players filename
	string filename_trainings;//trainings filename
	string filename_tournaments;//tournaments filename
	Club();//constructor
	~Club();//destructor

public:

	static Club * getinstance();//gets instance of class Club
	bool getleaveprogram() const{return leaveprogram;};//gets leaveprogram

	string getfilename_players() const{return this->filename_players;}//gets filename_players
	string getfilename_trainings() const{return this->filename_trainings;}//gets filename_trainings
	string getfilename_tournaments() const{return this->filename_tournaments;}//gets filename_tournaments
	vector<Level *> getLevels() const { return vector<Level *>{minis,juveniles,juniors,seniors}; };//return a vector with minis, juveniles, juniors...
	vector<string> getPlayers() const;//returns a vector with thes name of all the players in the club. It also includes players that participated in certain events and were later removed

	void readplayers(istream &in);//reads players from an istream
	void readtrainings(istream &in);//reads players from an istream
	void readtournaments(istream & in);//reads tournaments from an istream

	void writeplayers();//writes players in a file
	void writetrainings();//writes trainings in a file
	void writetournaments();//writes tournaments in a file

	void setleaveprogram(bool leaveprogram){this->leaveprogram=leaveprogram;}//sets leaveprogram
	void setfilename_players(string filename_players){this->filename_players=filename_players;}//sets filename_players
	void setfilename_trainings(string filename_trainings){this->filename_trainings=filename_trainings;}//sets filename_trainings
	void setfilename_tournaments(string filename_tournaments){this->filename_tournaments=filename_tournaments;}//sets filename_tournaments
	void setMinis(Level * minis);
	void setJuveniles(Level * juveniles);
	void setJuniors(Level * juniors);
	void setSeniors(Level * seniors);
	void setCurrentDate();
};


#endif
