#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<vector>


class Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();//default constructor sets date to current time
	Date(unsigned int day ,unsigned int month, unsigned int year);

	inline int getDay() const {return this->day;}//gets day
	inline int getMonth() const {return this->month;}//gets month
	inline int getYear() const {return this->year;}//gets year

	bool operator>(const Date &d1) const;
	bool operator>=(const Date &d1) const;
	bool operator<(const Date &d1) const;
	bool operator<=(const Date &d1) const;
	bool operator==(const Date &d1) const;
	Date operator-(const Date &d1) const;//this operator return the time that passed between two dates

	void show() const;//prints the date on the screen


};

std::ostream& operator<<(std::ostream& out, const Date & date);//writes date in ostream out
std::istream& operator>>(std::istream& in, Date & date);//gets date from instream in


#endif
