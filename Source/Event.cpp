#include "../Headers/Event.h"

using namespace std;

void Event::outputNames(ofstream &fout) const{
	for (unsigned int i = 0 ; i < this->presences.size() ; i++){
		fout << this->presences.at(i);
		if (i == this->presences.size() -1)
			fout << endl;
		else
			fout << " ; ";
	}

}
