#include "../Headers/Seniors.h"
#include "../Headers/Level.h"
#include "../Headers/Globals.h"
#include <fstream>
using namespace std;

void Seniors::playerOutput(ofstream &out) const {
	out << SEN_ID << endl;
	Level::playerOutput(out);
}
