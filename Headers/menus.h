#ifndef MENUS_H
#define MENUS_H
#include "Date.h"
#include "Event.h"
#include <iostream>
#include <string>
#include <fstream>

int readplayers();//asks the user for the players file
int readtrainings();//asks the user for the trainings file
int readtournaments();//asks the user for the tournaments file

Date askfordate();//asks the user to type a date
void printlevel(unsigned int level);//prints a level
void initialmenu();//displays the initial menu
void levelmenu(unsigned int level);//displays the main menu for each level
void playersmenu(unsigned int level);//displays the menu with the information of the players
void individualplayermenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual player
void actualizeECG(unsigned int level, unsigned int id);//menu that actualizes ECG
void actualizeheight(unsigned int level, unsigned int id);//menu that actualizes height
void removeplayer(unsigned int level,unsigned int id);//menu that removes a player
void regnewplayermenu();//menu that allows the user to register a new player on the team
void trainingsmenu(unsigned int level);//displays the menu with information of the trainings
void tournamentsmenu(unsigned int level);//displays the menu with information of the tournaments
void individualtrainingmenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual training
void editplayerstraining(unsigned int level, Event * ev);//asks the user to select the players that participated in the tournament
void individualtournamentmenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual tournament
 




#endif
