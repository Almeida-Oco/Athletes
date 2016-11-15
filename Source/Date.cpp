#include "../Headers/Date.h"
#include "../Headers/utilities.h"
#include "../Headers/exceptions.h"
#include <ctime>
using namespace std;


Date::Date(){
	struct tm timeinfo;
	time_t t = time(0);   // gets current time
	localtime_s(&timeinfo, &t);
	year = timeinfo.tm_year + 1900;
	month = timeinfo.tm_mon + 1;
	day = timeinfo.tm_mday;

}

//This constructor throws an exception if a date is not valid, although it ignores dates with zero parameters 
Date::Date(unsigned int d,unsigned int m , unsigned int y){
	unsigned int months[13] = {0, 31,28 + Isleap(y),31,30,31,30,31,31,30,31,30,31 };//array with the number of days in each month
	if ((m>12) || (d > months[m])) {
		throw InvalidDate(d, m, y);
	}
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

/* Computes the difference between two dates
 * parameter: d1 - Date to be subtracted from the object date
 * Returns the subtraction between the object date and d1
 */
vector<int> Date::operator-(const Date &d1) const{
	if(*this >= d1){
		int d,m,y;
		if(this->day>=d1.day){
			d=this->day-d1.day;
			if(this->month>=d1.month){
				m=this->month-d1.month;
				y=this->year-d1.year;
			}
			else{
				m=this->month+12-d1.month;
				y=this->year-d1.year-1;
			}
		}
		else{
			d=this->day+30-d1.day;
			if(this->month>=d1.month+1){
				m=this->month-d1.month-1;
				y=this->year-d1.year;
			}
			else{
				m=this->month+12-d1.month-1;
				y=this->year-d1.year-1;
			}
		}
		vector<int> v = { y,m,d };
		return v;
	}
	else{
		vector<int> v=d1-*this;
		v[0] = -v[0];
		v[1] = -v[1];
		v[2] = -v[2];
		return v;
	}
}
/*
parameter: ostream & out - ostream where date is going to be written
parameter: const Date & date - date
Writes the date passed as a parameter in out
*/
ostream& operator<<(ostream& out, const Date& date){
	out << date.getDay();
	out << "/";
	if (date.getMonth() < 10){
		out << 0;
	}
	out << date.getMonth();
	out << "/";
	out << date.getYear();
	return out;
}

/*
parameter: istream & in - istream from where date is going to be read
parameter: Date & date - variable where the date extracted from stream is going to be stored
Reads date from istream
*/
istream& operator>>(istream& in, Date& date){
	int d, m, y;//day, month and year of the date that is going to be read
	in >> d;
	in.ignore(1);
	in >> m;
	in.ignore(1);
	in >> y;
	Date date2(d, m, y);
	date = date2;
	return in;
}

/*
Prints the date on the screen
*/
void Date::show() const {
	cout << year;
	cout << "/";
	if (month < 10) {
		std::cout << 0 << month;
	}
	else {
		cout << month;
	}
	cout << "/";
	if (day < 10) {
		cout << 0 << day;
	}
	else {
		cout << day;
	}
}



