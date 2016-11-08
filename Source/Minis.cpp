#include "../Headers/Minis.h"
#include <fstream>
using namespace std;

void Minis::playerOutput(ofstream &out) const {
	out << MINI_ID << endl;
	 Level::playerOutput(out);
}
