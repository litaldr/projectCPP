#ifndef __MANAGER_H
#define __MANAGER_H
#pragma warning (disable: 4996) 

#include "trade_system.h"
#include "Product.h"

#define EXIT 11 //define the input of exiting program




void run(); // function run on using system
void printMenu(); // function prints the menu system for the user
void init_system_name(trade_system &system); //function to initialize the system name
int getAction(); // function give indicate which action the user is about to choose
void doAction(int num, trade_system *system); // function do the wanted action 
bool initializeDate(date & feedbackDate, int &day, int& month, int &year);


void cleanBuffer();



#endif