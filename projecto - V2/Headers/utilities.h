#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

#ifndef UTILITIES_H
#define UTILITIES_H

#include<iostream>
#include <string>
#include<vector>
#include "Date.h"

using namespace std;

string removespaces(string s);//removes extra spaces from a string
int actualage(Date birth);//gives the age that someone born on birth has today
bool Isleap(int year);//checks if a year is leap or not
bool isInteger(const string & s);//checks if a string is an integer
int convint(string s);//converts an integer to a string

#endif
