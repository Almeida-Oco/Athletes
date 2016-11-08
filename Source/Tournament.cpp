#include "../Headers/Tournament.h"

using namespace std;

void Tournament::eventOutput(ofstream &out) const{
	 out << TOUR_ID <<
			 SEPARATOR << this->major <<
			 SEPARATOR << this->rank <<
			 SEPARATOR << this->getDay().getDay() <<
			 SEPARATOR << this->getDay().getMonth() <<
			 SEPARATOR << this->getDay().getYear() <<
			 SEPARATOR;

	 for (unsigned int i = 0 ; i<this->getPresence().size() ; i++){
		 this->getPresence().at(i)->output(out);
	 }
}
