#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;

class date
{

private:
//-----------------------attributes----------------------//
	int day;
	int month;
	int year;

public:

	date(int day = 1, int month = 1, int year = 2001); // default constructor
	//not interested in copy constructor - each date is set for a specific feedback
	~date(); // destructor
	
//---------------------set & get functions-----------------------//
	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);
	
//------------not in use----------------//
	int getDay()   const;
	int getMonth() const;
	int getYear()  const;
};

#endif

