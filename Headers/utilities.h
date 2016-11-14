#ifndef UTILITIES_H
#define UTILITIES_H

#include<iostream>
#include <string>
#include <vector>
#include "Date.h"

std::string removeSpaces(std::string s);//removes extra spaces from a string
unsigned int actualAge(const Date &birth);
bool Isleap(int year);//checks if a year is leap or not
Date currentDate();
std::vector<std::string> stringSplit(const std::string &line, const std::string &spliter);





#endif
