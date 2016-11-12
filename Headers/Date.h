#ifndef DATE_H
#define DATE_H

class Date {
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
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
};


#endif
