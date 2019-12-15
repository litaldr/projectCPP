#ifndef __ADDRESS_USERS_H
#define __ADDRESS_USERS_H

#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)

using namespace std;

static const int MAX_NAME_SIZE = 20; //maximun name length
static const int MIN_PASSWORD_SIZE = 8;
static const int MAX_PASSWORD_SIZE = 20;
/* the use of the max & min const size is for limiting the password users (sellers& buyers),
we choose to initialize those const's in this class for revent multiple initializtion in both sellers & buyers class */
class address_user
{
public:
	address_user() = default; //constructor delete
	address_user(const char* country, const char* city, const char *street, int house_number); //constructor
	address_user(const address_user& other);
	address_user(const address_user&& other);
	~address_user();// defualt destructor because all names strings are allocated static

					// set all atributes
	bool setCountry(const char *c);
	bool setStreet(const char *s);
	bool setCity(const char *c);
	void setHouse_number(int n);

	//functions check valid name
	bool validString_name(const char *c);
	bool validString_street(const char *s);

	// get all atributes
	char * getCountry()    const;
	char * getCity()       const;
	char * getStreet()     const;
	int getHouse_number() const;


private:
	//attributes
	char* country;
	char* city;
	char* street;
	int house_number;
};


#endif