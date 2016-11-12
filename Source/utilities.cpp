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
	struct tm *time_info;
	time_t current_time;
	time(&current_time);// gets current time

	time_info = localtime(&current_time);
	Date t = Date(time_info->tm_mday , time_info->tm_mon+1 , time_info->tm_year+1900);
	return t;
}

unsigned int actualAge(const Date &birth){
	return (currentDate() - birth).getYear();
}
/*
 * This function returns the date of someone that was born on day birth
 * parameter: birth - day where the person was born
 * Returns the age that the person currently has
 */
