#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)
using namespace std;

class date
{
private:
	int day;
	int month;
	int year;

public:
	date(int day = 1, int month = 1, int year = 2001);
	date(const date& other);// copy c'tor
	// defualt destructor because all variables are integers

	bool setDay(int day);
	bool setMonth(int month);
	bool setYear(int year);
	int getDay()   const;
	int getMonth() const;
	int getYear()  const;


};

#endif

