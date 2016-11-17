#include "../Headers/Training.h"
#include "../Headers/utilities.h"
#include <iomanip>

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

void Training::show() const{
	(this->getDay()).show();
	cout<< "| ";
	if (game) {
		cout << "Yes |";
	}
	else {
		cout << " No |";
	}
	vector<string> vector_presences = this->getPresences();
	cout << setw(7) << vector_presences.size();
}

/*
parameter: ostream & out - ostream where training is going to be written
parameter: const Training & training - training
Writes the training passed as a parameter in out
*/
ostream& operator<<(ostream& out, const Training & training){
	out << training.getDay() << " ; " << training.game << " ; ";
	vector<string> presences = training.getPresences();
	out << presences.size() << " ; ";
	for (unsigned int i = 0; i < presences.size(); i++) {
		out << presences[i] << " ; ";
	}
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
	in >> semicolon;
	unsigned int n_presences;
	in >> n_presences;
	in >> semicolon;
	for (unsigned int i = 0; i < n_presences; i++) {
		string player_name;
		getline(in, player_name, ';');
		training.addPresence(removespaces(player_name));
	}
	return in;
}
