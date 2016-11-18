#ifndef CLUB_H
#define CLUB_H

#include "Date.h"
#include "Level.h"
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
	bool leaveprogram;//boolean that will tell the program when to leave
	static Club * singleton_instance;//pointer to instance of class Club
	std::string filename_players;//players filename
	std::string filename_trainings;//trainings filename
	std::string filename_tournaments;//tournaments filename
	Club();//constructor
	~Club();//destructor

public:

	static Club * getinstance();//gets instance of class Club
	bool getleaveprogram() const{return leaveprogram;};//gets leaveprogram

	std::string getfilename_players() const{return this->filename_players;}//gets filename_players
	std::string getfilename_trainings() const{return this->filename_trainings;}//gets filename_trainings
	std::string getfilename_tournaments() const{return this->filename_tournaments;}//gets filename_tournaments
	std::vector<Level *> getLevels() const { return std::vector<Level *>{this->minis,this->juveniles,this->juniors,this->seniors}; };//return a vector with minis, juveniles, juniors...
	std::vector<std::string> getPlayers() const;//returns a vector with thes name of all the players in the club. It also includes players that participated in certain events and were later removed

	void readplayers(std::istream &in);//reads players from an istream
	void readtrainings(std::istream &in);//reads players from an istream
	void readtournaments(std::istream & in);//reads tournaments from an istream

	void writeplayers();//writes players in a file
	void writetrainings();//writes trainings in a file
	void writetournaments();//writes tournaments in a file

	void setleaveprogram(bool leaveprogram){this->leaveprogram=leaveprogram;}//sets leaveprogram
	void setfilename_players(std::string filename_players){this->filename_players=filename_players;}//sets filename_players
	void setfilename_trainings(std::string filename_trainings){this->filename_trainings=filename_trainings;}//sets filename_trainings
	void setfilename_tournaments(std::string filename_tournaments){this->filename_tournaments=filename_tournaments;}//sets filename_tournaments
	void setMinis(Level * minis);
	void setJuveniles(Level * juveniles);
	void setJuniors(Level * juniors);
	void setSeniors(Level * seniors);
	void setCurrentDate();
};


#endif
