#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<vector>
using namespace std;
class Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();//default constructor sets date to current time
	Date(unsigned int day ,unsigned int month, unsigned int year);

	inline int getDay() const {return this->day;}
	inline int getMonth() const {return this->month;}
	inline int getYear() const {return this->year;}

	bool operator>(const Date &d1) const;
	bool operator>=(const Date &d1) const;
	bool operator<(const Date &d1) const;
	bool operator<=(const Date &d1) const;
	bool operator==(const Date &d1) const;
	vector<int> operator-(const Date &d1) const;//this operator return the time that passed between two dates

};

ostream& operator<<(ostream& out, const Date & date);//writes date in ostream out
istream& operator >> (istream& in, Date & date);//gets date from instream in


#endif
