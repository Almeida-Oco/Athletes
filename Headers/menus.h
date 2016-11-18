#ifndef MENUS_H
#define MENUS_H
#include "Date.h"
#include "Event.h"
int readplayers();//asks the user for the players file
int readtrainings();//asks the user for the trainings file
int readtournaments();//asks the user for the tournaments file
Date askfordate();//asks the user to type a date
void printlevel(unsigned int level);//prints a level
void initialmenu();//displays the initial menu
void levelmenu(unsigned int level);//displays the main menu for each level
void changecoachmenu(unsigned level);//asks the user for the new name of the coach
void playersmenu(unsigned int level);//displays the menu with the information of the players
void individualplayermenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual player
void actualizeECG(unsigned int level, unsigned int id);//menu that actualizes ECG
void actualizeheight(unsigned int level, unsigned int id);//menu that actualizes height
void removeplayer(unsigned int level, unsigned int id);//menu that removes a player
void regnewplayermenu();//menu that allows the user to register a new player on the team
void trainingsmenu(unsigned int level);//displays the menu with information of the trainings
void tournamentsmenu(unsigned int level);//displays the menu with information of the tournaments
void individualtrainingmenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual training
void editplayerstraining(unsigned int level, Event * ev);//asks the user to select the players that participated in the training
void individualtournamentmenu(unsigned int level, unsigned int id);//displays a menu with the information of an individual tournament
void editranktournament(unsigned int level, Event * tournament);//edits the rank of team in a tournament
void editplayerstournament(unsigned int level, Event * tournament);//asks the user to select the players that participated in a certain tournament
void editresultstournament(unsigned int level, Event * tournament);//asks the user to select the results of a certain tournament
void calendarmenu(unsigned int level);//This function displays the next events menu that shows the next events on the calendar
void individualeventmenu(unsigned int level, unsigned int id);//Shows the user information about a scheduled event
void removeevent(unsigned int level, unsigned int id);//removes an event
void scheduleeventmenu(unsigned int level);//This function displays the menu that allows the user to schedule an event
void askeventdate(unsigned int level, unsigned int event);//This function asks the user for the date of an event
void makecall(unsigned int level, Event * tournament);//This function asks the user for the number of player that he wants to call for a major tournament



#endif
