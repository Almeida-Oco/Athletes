#include "../Headers/utilities.h"

using namespace std;

/*
This functions eliminates extra spaces between words, so that if there is more than one space in
the string, this function returns a string with only one space between two words. It also eliminates extra
spaces at the beginning and at the end of a string
parameter: string s - string that will have extra spaces eliminated from
return value: string s without extra spaces
*/
string removespaces(string s){
	unsigned int i = 0;
	//the following loop removes newlines
	while (i < s.size()){
		if (s[i] == 10){
			s.erase(i, 1);
			i--;
		}
		i++;
	}
	i = 0;
	//The following loops transforms multiple spaces in only one space
	while (i+1 < s.size()){
		if (s[i] == ' ' && s[i + 1] == ' '){
			s.erase(i, 1);
			i = i - 1;
		}
		i = i + 1;
	}
	if ((s.size()>0) && s[0] == ' '){
		s.erase(0, 1);//deletes space at the beginning of a string
	}
	if ((s.size() > 0) && s[s.size()-1]==' '){
		s.erase(s.size() - 1, 1);//deletes space at the end of a string
	}
	return s;
}

Date currentDate(){
	time_t t = time(0);   // gets current time
	struct tm *now = localtime(&t);
	Date d(now->tm_mday , now->tm_mon +1 , now->tm_year +1900);

	return d;
}

/*
 * This function returns the date of someone that was born on day birth
 * parameter: birth - day where the person was born
 * Returns the age that the person currently has
 */
unsigned int actualAge(const Date &birth){
	return (currentDate() - birth).getYear();
}

/*This function checks if a year is leap or not
* parameter: year - year that is going to be checked
* Returns true if the year is leap and false if not
*/
bool Isleap(int year) {
	if (year % 4 != 0) {
		return false;
	}
	else if (year % 100 != 0) {
		return true;
	}
	else if (year % 400 != 0) {
		return false;
	}
	else {
		return true;
	}
}

/*
This functions checks if a string is an integer
parameter: const string &s-The function will check if this string is an integer
return value- true if string is an integer and false if not
source:http://stackoverflow.com/questions/2844817/how-do-i-check-if-a-c-string-is-an-int
*/
bool isInteger(const string & s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char * p;
		strtol(s.c_str(), &p, 10);

	return (*p == 0);
}

/*
This function converts a string to an integer and returns -1 if string is not an integer
parameter: string s-string that is going to be converted
return value - integer that corresponds to the string
*/
int convint(string s) {
	if (!isInteger(s))
		return -1;
	else
		return atoi(s.c_str());
}
