#include "../Headers/menus.h"
#include "../Headers/Club.h"
#include "../Headers/exceptions.h"
using namespace std;

/*
 *This function opens the files and saves the name of the file in the respective variable
 * file = 0 -> ERROR ,  file = 1 -> players file , file = 2 -> training file , file = 3 -> tournament file
 */
int openFile(Club *club, ifstream &fout, unsigned int file) {

	string file_name;
	do {

		cout<< "Introduce the path of the file with the " <<
				((file == 1) ? "players" : ((file == 2) ? "trainings" : "tournaments")) <<
				" (or press l if you want to leave): ";

		cin.clear();
		getline(cin, file_name);

		if ((file_name.size() == 1) && (file_name[0] == 'l'))
			return 1; //MEANS PROGRAM SHOULD LEAVE
		 else
			fout.open(file_name.c_str());

		if (fout.fail()) {
			cout << "\n\nThe path you introduced is not valid." << endl;
		}
	} while (fout.fail());

	if (file == 1)
		club->setPFname(file_name);
	else if (file == 2)
		club->setTrFname(file_name);
	else if (file == 3)
		club->setToFname(file_name);

	return 0;
}
