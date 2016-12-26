#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<vector>
using namespace std;
class Date {
	unsigned int day;//Date day
	unsigned int month;//Date month
	unsigned int year;//Date year
public:
	Date();//default constructor sets date to current time
	Date(unsigned int day ,unsigned int month, unsigned int year);//constructs date with the given parameters
	inline int getDay() const {return this->day;}//gets day
	inline int getMonth() const {return this->month;}//gets month
	inline int getYear() const {return this->year;}//gets year
	bool operator>(const Date &d1) const;//date comparator
	bool operator>=(const Date &d1) const;//date comparator
	bool operator<(const Date &d1) const;//date comparator
	bool operator<=(const Date &d1) const;//date comparator
	bool operator==(const Date &d1) const;//date comparator
	/**
		@brief Sums n days to the date in the object
		@param n Number of days to sum
		@details Used only on hash table , takes into consideration leap years

		@return New object with correct date
	*/
	Date addDays(unsigned int n) const;
	/**
		@brief Subtracts n days to the date in the object
		@param n Number of days to subtract
		@details Used only on hash table , takes into consideration leap years

		@return New object with correct date
	*/
	Date subtractDays(unsigned int n) const;
	/**
		@brief Computates the difference in days between the date of the object and the current date
		@return If object date > current date returns number of days, else returns -1
	*/
	unsigned int diffDays();

	Date year_date(unsigned int year) const;//returns the date in year that corresponds to the object date for example if obj. is 8/7/2005 and year is 2016 it returns 8/7/2016
	vector<int> operator-(const Date &d1) const;//this operator return the time that passed between two dates
	void show() const;//prints the date on the screen
};

ostream& operator<<(ostream& out, const Date & date);//writes date in ostream out
istream& operator >> (istream& in, Date & date);//gets date from instream in


#endif
