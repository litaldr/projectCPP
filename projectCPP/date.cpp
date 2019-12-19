#include "date.h"

date::date(int day, int month, int year) //constructor
{
	this->day = day;
	this->month = month;
	this->year = year;

}
date::~date() {} //destructor

//date::date(const date& other)// copy c'tor
//{
//
//	this->day = other.day;
//	this->month = other.month;
//	this->year = other.year;
//}
bool date::setDay(int day)
{
	if (!((day >= 1) && (day <= 31)))
	{
		return false;
		/*cout << "the day must be between 1 to 31. please enter a valid day" << endl; להעביר קריאת שגיאה למנג'ר
		cin >> day;*/
	}
	else
		this->day = day;
	return true;
}
bool date::setMonth(int month)
{
	if (!((month >= 1) && (month <= 12)))
	{
		return false;
		/*cout << "the month must be between 1 to 12. please enter a valid month number" << endl; להעביר קריאת שגיאה למנג'ר
		cin >> month;*/
	}
	else
		this->month = month;
	return true;
}
bool date::setYear(int year)
{
	if (!((year >= 2001) && (year <= 2019)))//  soon 2020
	{
		return false;
		/*cout << "the year must be relvent. please enter a valid year " << endl; להעביר קריאת שגיאה למנג'ר
		cin >> year;*/
	}
	else
		this->year = year;
	return true;

}
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
