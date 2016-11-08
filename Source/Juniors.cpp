#include "../Headers/Juniors.h"

using namespace std;

void Juniors::playerOutput(ofstream &out) const{
	out << JUN_ID << endl;
	Level::playerOutput(out);
}
