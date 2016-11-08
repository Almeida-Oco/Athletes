#include "../Headers/Juveniles.h"

#include <fstream>
using namespace std;


void Juveniles::playerOutput(ofstream &out) const{
	out << JUV_ID << endl;
	Level::playerOutput(out);
}
