#include "../Headers/utilities.h"

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

/*
 * This function returns the date of someone that was born on day birth
 * parameter: birth - day where the person was born
 * Returns the age that the person currently has
 */
int actualage(Date birth){
	Date current_date;
	vector<int> v=current_date-birth;
	return v[0];
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