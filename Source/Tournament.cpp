#include "../Headers/Tournament.h"

using namespace std;

/*
parameter: ostream & out - ostream where tournament is going to be written
parameter: const Tournament & tournament - tournament
Writes the tournament passed as a parameter in out
*/
ostream & operator<<(ostream& out, const Tournament & tournament){
	out << tournament.getDay() << " ; " << tournament.major << " ; " << tournament.rank << " ; ";
	out<<(tournament.results).size()<<" ; ";
	for(unsigned int i=0;i<(tournament.results).size();i++){
		out<<tournament.results[i].first<<" ";
		out<<tournament.results[i].second;

		if (i != tournament.results.size()-1)
			out << " ; ";
	}
	return out;
}
/*
parameter: istream & in - istream from where tournament is going to be read
parameter: Tournament & tournament - variable where the tournament extracted from stream is going to be stored
Reads tournament from istream
*/
istream & operator>>(istream& in, Tournament & tournament){
	char semicolon;//semicolon that exists in the file
	string place;
	Date date_day(0,0,0);
	in>>date_day;
	tournament.setDay(date_day);
	in>>semicolon;
	in>>tournament.major;
	in>>semicolon;
	in>>tournament.rank;
	in>>semicolon;
	unsigned int size;
	in>>size;
	in >> semicolon;
	tournament.results.clear();
	for(unsigned int i=0;i<size;i++){
		pair<unsigned int, unsigned int> game;
		in>>game.first>>game.second;
		if (i != size-1) in>>semicolon;
		tournament.results.push_back(game);
	}
	getline(in,place); //TO GET RID OF \n
	return in;
}
