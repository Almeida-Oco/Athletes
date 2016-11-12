#ifndef CLUB_H
#define CLUB_H

#include "../Headers/Date.h"
#include "../Headers/Level.h"


class Club{
 
	Level * minis;
	Level * juveniles;
	Level * juniors ;
	Level * seniors;
	Date current_date;
	//Date end_of_season;
	bool leaveprogram;//boolean that will tell the program when to leave
	//static Club * singleton_instance;//pointer to instance of class Club
	std::string filename_players;//players filename
	std::string filename_trainings;//trainings filename
	std::string filename_tournaments;//tournaments filename

public:
	Club();
	~Club();//destructor
	static Club * instance();//gets instance of class Club
	bool getleaveprogram() const{return leaveprogram;};//gets leaveprogram
	void setleaveprogram(bool leaveprogram){this->leaveprogram=leaveprogram;}//sets leaveprogram

	std::string getfilename_players() const{return this->filename_players;}//gets filename_players
	std::string getfilename_trainings() const{return this->filename_trainings;}//gets filename_trainings
	std::string getfilename_tournaments() const{return this->filename_tournaments;}//gets filename_tournaments

	void setfilename_players(std::string filename_players){this->filename_players=filename_players;}//sets filename_players
	void setfilename_trainings(std::string filename_trainings){this->filename_trainings=filename_trainings;}//sets filename_trainings
	void setfilename_tournaments(std::string filename_tournaments){this->filename_tournaments=filename_tournaments;}//sets filename_tournaments

	void readplayers(std::istream &in);//reads players from an istream
	void readtrainings(std::istream &in);//reads players from an istream
	void readtournaments(std::istream & in);//reads tournaments from an istream

	void writeplayers();//writes players in a file
	void writetrainings();//writes trainings in a file
	void writetournaments();//writes tournaments in a file

	void setMinis(Level * minis);
	void setJuveniles(Level * juveniles);
	void setJuniors(Level * juniors);
	void setSeniors(Level * seniors);
	void setCurrentDate();

};


#endif
