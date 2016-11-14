#include "../Headers/Date.h"
#include "../Headers/utilities.h"
#include "../Headers/exceptions.h"
using namespace std;


Date::Date() : day(0) , month(0) , year(0){};
/*
 * Checks if number of month is correct and if number of days is also correct
 * Ignores undefined dates (d = 0, m=0, y=0)
 */
bool Date::checkDate(const unsigned int day , const unsigned int month , const unsigned int year) const{
	unsigned int months[13] = {0,31, 28 + isLeap(year),31,30,31,30,31,31,30,31,30,31 };//array with the number of days in each month
	if ( (month > 12) || day > months[month])
		return false;
	else
		return true;
}

bool Date::isLeap(const unsigned int y) const{
	if ((y % 4) == 0 ){
		if ( (y % 400) == 0)
			return true;
		else
			return false;
	}
	return false;
}
//This constructor throws an exception if a date is not valid, althougsh it ignores dates with zero parameters
Date::Date(unsigned int d,unsigned int m , unsigned int y){
	if (checkDate(d,m,y)){
		this->day=d; this->month = m; this->year = y;
	}else
		throw InvalidDate(d, m, y);

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
Date Date::operator-(const Date &d1) const{
	Date result;
	if(*this >= d1){
		int d,m,y;
		if(this->day >= d1.day){
			result.day=this->day-d1.day;
			if(this->month>=d1.month){
				result.month = this->month-d1.month;
				result.year=this->year-d1.year;
			}
			else{
				result.month=this->month+12-d1.month;
				result.year=this->year-d1.year-1;
			}
		}
		else{
			result.day=this->day+30-d1.day;
			if(this->month>=d1.month+1){
				result.month=this->month-d1.month-1;
				result.year=this->year-d1.year;
			}
			else{
				result.month=this->month+12-d1.month-1;
				result.year=this->year-d1.year-1;
			}
		}
		return result;
	}
	else
		return d1-*this;

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
	unsigned int d, m, y;//day, month and year of the date that is going to be read
	in >> d;
	in.ignore(1);
	in >> m;
	in.ignore(1);
	in >> y;
	Date date2(d, m, y);
	date = date2;
	return in;
}


