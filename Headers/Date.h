#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<vector>
#include <ctime>


class Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date();
	Date(unsigned int day ,unsigned int month, unsigned int year);

	inline unsigned int getDay() const {return this->day;}
	inline unsigned int getMonth() const {return this->month;}
	inline unsigned int getYear() const {return this->year;}
	inline Date getDate() const {return *this;}

	bool operator>(const Date &d1) const;
	bool operator>=(const Date &d1) const;
	bool operator<(const Date &d1) const;
	bool operator<=(const Date &d1) const;
	bool operator==(const Date &d1) const;
	Date operator-(const Date &d1) const;//this operator return the time that passed between two dates

	bool checkDate(const unsigned int day , const unsigned int month , const unsigned int year) const;
	bool isLeap(const unsigned int y) const;

	unsigned int actualAge(const Date &birth , const Date &current_date) const;

};

std::ostream& operator<<(std::ostream& out, const Date & date);//writes date in ostream out
std::istream& operator>> (std::istream& in, Date & date);//gets date from instream in


#endif
