#ifndef UTILITIES_H
#define UTILITIES_H

#include "Player.h"
#include "Date.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <vector>

std::string removespaces(std::string s);//removes extra spaces from a string
unsigned int actualAge(const Date &birth);//gives the age that someone born on birth has today
bool Isleap(int year);//checks if a year is leap or not
bool isInteger(const std::string & s);//checks if a string is an integer
int convint(std::string s);//converts an integer to a string
Date currentDate();

#endif
