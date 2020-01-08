#include "date.h"

date::date(int day, int month, int year) //constructor
{
	this->day = day;
	this->month = month;
	this->year = year;

}

date::~date() {} // destructor

//----------------------set & get functions-----------------------//

bool date::setDay(int day)
{
	if (!((day >= 1) && (day <= 31)))
		return false;

	else
		this->day = day;
	return true;
}

bool date::setMonth(int month)
{
	if (!((month >= 1) && (month <= 12)))
		return false;

	else
		this->month = month;
	return true;
}

bool date::setYear(int year)
{
	if (!((year >= 2001) && (year <= 2019))) // system starts counting years from 2001 
		return false;
	
	else
		this->year = year;
	return true;

}

//------------not in use----------------//

int date::getDay() const
{
	return day;
}

int date::getMonth() const
{
	return month;
}

int date::getYear() const
{
	return year;
}

ostream & operator<<(ostream & os, const date & date)
{
	os << date.day << "/" << date.month << "/" << date.year << endl;
	return os;
}
