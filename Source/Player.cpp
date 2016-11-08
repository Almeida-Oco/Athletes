#include "../Headers/Player.h"

using namespace std;

void Player::output(ofstream &out) const{
	out << this->getName() <<
					SEPARATOR << this->getHeight() <<
					SEPARATOR << this->getEletro() <<
					SEPARATOR << this->getCheck() <<
					SEPARATOR << this->getYear().getDay() <<
					SEPARATOR << this->getYear().getMonth() <<
					SEPARATOR << this->getYear().getYear();
}
