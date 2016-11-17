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
	//static Club * singleton_instance;//pointer to instance of class Club
	std::string p_fname;//players filename
	std::string tr_fname;//trainings filename
	std::string to_fname;//tournaments filename

public:
	Club();
	~Club();//destructor
	//static Club * instance();//gets instance of class Club

	inline std::string getPFname() const{return this->p_fname;}//gets filename_players
	inline std::string getTrFname() const{return this->tr_fname;}//gets filename_trainings
	inline std::string getToFname() const{return this->to_fname;}//gets filename_tournaments

	inline void setPFname(std::string file_name){this->p_fname=file_name;}//sets filename_players
	inline void setTrFname(std::string file_name){this->tr_fname=file_name;}//sets filename_trainings
	inline void setToFname(std::string file_name){this->to_fname=file_name;}//sets filename_tournaments

	void readPlayers(std::ifstream &in, unsigned int lvl);//reads players from an istream
	void readTrainings(std::ifstream &in, unsigned int lvl);//reads players from an istream
	void readTournaments(std::ifstream & in , unsigned int lvl);//reads tournaments from an istream

	void writePlayers();//writes players in a file
	void writeTrainings();//writes trainings in a file
	void writeTournaments();//writes tournaments in a file

	void assignPlayers(std::ifstream &in, unsigned int lvl, Event *ev);

	inline void setMinis(Level * minis) {this->minis = minis;}
	inline void setJuveniles(Level * juveniles) {this->juveniles = juveniles;}
	inline void setJuniors(Level * juniors) {this->juniors = juniors;}
	inline void setSeniors(Level * seniors) {this->seniors = seniors;}
	inline void setCurrentDate();
};


#endif
