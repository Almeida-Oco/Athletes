#include "../Headers/Date.h"

using namespace std;



Date::Date(unsigned int d=0 , unsigned int m=0 , unsigned int y=0){
	this->day=d; this->month = m; this->year = y;
}

bool Date::operator> (const Date &D1) const
{
	if (this->year > D1.year)
		return true;
	else if (this->year == D1.year)
	{
		if (this->month > D1.month)
			return true;
		else if (this->day > D1.day)
			return true;
		else
			return false;
	}
	return false;
}
bool Date::operator>= (const Date &D1) const
{
	if (this->year > D1.year)
		return true;
	else if (this->year == D1.year)
	{
		if (this->month > D1.month)
			return true;
		else if (this->day >= D1.day)
			return true;
		else
			return false;
	}
	return false;
}
bool Date::operator<= (const Date &D1) const{
	return !(*this > D1);
}
bool Date::operator< (const Date &D1) const{
	return !(*this >= D1);
}
bool Date::operator== (const Date &D1) const{
	return (this->day == D1.day && this->month == D1.month && this->year == D1.year);
}
