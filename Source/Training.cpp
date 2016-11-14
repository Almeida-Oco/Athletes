#include "../Headers/Training.h"
#include "../Headers/utilities.h"

using namespace std;

/*
parameter: ostream & out - ostream where training is going to be written
parameter: const Training & training - training
Writes the training passed as a parameter in out
*/
ostream& operator<<(ostream& out, const Training & training){
	out << training.getDay() <<" ; "<<training.game;
	return out;

}
/*
parameter: istream & in - istream from where training is going to be read
parameter: Training & training - variable where the training extracted from stream is going to be stored
Reads training from istream
*/
istream& operator>>(istream& in, Training & training){
	char semicolon;
	vector<string> names;
	string place;
	Date date_day(0,0,0);
	in >> date_day;
	training.setDay(date_day);
	in>>semicolon;
	in>>training.game;
	getline(in,place); //USED TO IGNORE UNCONSUMED \n

	return in;
}
