#include "../Headers/Training.h"

using namespace std;

void Training::eventOutput(ofstream &out) const{
	out << TRAIN_ID  <<
			SEPARATOR << this->game <<
			SEPARATOR << this->getDay().getDay() <<
			SEPARATOR << this->getDay().getMonth() <<
			SEPARATOR << this->getDay().getYear() <<
			SEPARATOR;
	out << P_OPEN;
	for (unsigned int i = 0 ; i<this->getPresence().size() ; i++){
		this->getPresence().at(i)->output(out);
	}
	out << P_CLOSE << endl;
}
