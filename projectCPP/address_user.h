#ifndef __ADDRESS_USERS_H
#define __ADDRESS_USERS_H

#include <iostream>
#include <string.h>
#pragma warning (disable: 4996)

using namespace std;

/* the use of the max & min const size below is for limiting the password users (sellers& buyers),
we choose to initialize those const's in this class for prevent multiple initialization in both sellers & buyers class */

static const int MAX_NAME_SIZE = 20; //maximum name length
static const int MIN_PASSWORD_SIZE = 8; //maximum password length
static const int MAX_PASSWORD_SIZE = 20;//minimum password length

class address_user
{

public:
	
	address_user() = default; //default constructor
	address_user(const char* country, const char* city, const char *street, int house_number); //constructor
	address_user(const address_user& other); //copy constructor
	~address_user();// default destructor because all names strings are allocated static
    
	friend ostream& operator<<(ostream& os, const address_user& a); // operator print address
	void show()  const;

//------------------------------not in use yet------------------------------//

	address_user(const address_user&& other); //move constructor- we know it is not in use in this stage of the project

//--------------------set attributes---------------------------//
	bool setCountry(const char *c);
	bool setStreet(const char *s);
	bool setCity(const char *c);
	void setHouse_number(int n);

//----------------------functions check valid name--------------//
	bool validString_name(const char *c);
	bool validString_street(const char *s);

// ---------------------get attributes-------------------//
	char * getCountry()    const;
	char * getCity()       const;
	char * getStreet()     const;
	int getHouse_number() const;

private:
//-----------------------attributes----------------------//
	char* country;
	char* city;
	char* street;
	int house_number;
};


#endif