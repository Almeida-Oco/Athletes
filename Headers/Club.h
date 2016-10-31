#ifndef CLUB_H
#define CLUB_H

class Level;
class Date;

class Club{
 
	Level * minis;
	Level * juveniles;
	Level * juniors ;
	Level * seniors;
	Date current_date;
	const Date end_of_season;

public:
    Club();
    Club(Level * mi , Level * juv , Level * jun , Level * sen);
	void setMinis(Level * minis);
	void setJuveniles(Level * juveniles);
	void setJuniors(Level * juniors);
	void setSeniors(Level * seniors);
	void setCurrentDate();

};


#endif
