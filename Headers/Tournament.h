#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "Date.h"
#include "Event.h"

#include <vector>

class Tournament:public Event{
  bool major; // = True -> major Tournament , = False -> small Tournament
  unsigned int rank;
  std::vector< std::pair<unsigned int, unsigned int> > results;
public:
	Tournament(){};

  virtual ~Tournament(){};
	virtual bool Istraining() const{return false;};
	virtual void show() const;
	virtual bool getGame() const { return false; };
	friend std::ostream& operator<<(std::ostream& out, const Tournament & tournament);//writes tournament in ostream out
	friend std::istream& operator>>(std::istream& in, Tournament & tournament);//gets tournament from instream in
	virtual void writetofile(std::ostream & out) const {out<<*this;};

	inline unsigned int score() {return 3+this->major;}
};

#endif
