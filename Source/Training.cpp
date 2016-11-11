#include "../Headers/Training.h"

using namespace std;

/*void Training::eventOutput(ofstream &out) const{
	out << TRAIN_ID  <<
			SEPARATOR << this->game <<
			SEPARATOR << this->getDay().getDay() <<
			SEPARATOR << this->getDay().getMonth() <<
			SEPARATOR << this->getDay().getYear() <<
			SEPARATOR;
	out << P_OPEN;*/
	/*for (unsigned int i = 0 ; i<this->getPresence().size() ; i++){
		this->getPresence().at(i)->output(out);
	}*/
	/*out << P_CLOSE << endl;
}*/
/*
parameter: ostream & out - ostream where training is going to be written
parameter: const Training & training - training
Writes the training passed as a parameter in out
*/
ostream& operator<<(ostream& out, const Training & training){
	out<<training.getDay()<<" ; "<<training.game;
	return out;

}
/*
parameter: istream & in - istream from where training is going to be read
parameter: Training & training - variable where the training extracted from stream is going to be stored
Reads training from istream
*/
istream& operator>>(istream& in, Training & training){
	char semicolon;
	Date date_day(0,0,0);
	in>>date_day;
	training.setDay(date_day);
	in>>semicolon;
	in>>training.game;
	return in;
}
