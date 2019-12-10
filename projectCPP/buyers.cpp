#include "buyers.h"

buyers::buyers(char *user_name, char *password, const address_user & address) //constructor
	:address(address)
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name) + 1] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password) + 1] = '\0';

}
buyers::buyers(const buyers &other) : address(other.address)//copy c'tor
{
	this->user_name = strdup(other.user_name);
	this->password = strdup(other.password);
}


buyers::~buyers() //destructor
{
	// does we need those delete? we allocate string in static way
	delete[]user_name;
	delete[]password;
}


bool buyers::setName(const char* n) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	//משום שאנחנו מקצות בmanager שם משתמש בגודל 20, תמיד שנקבל מהמקלדת שם הוא יהיה לכל היותר באורך 20 גם אם המשתמש הכניס 100 תווים 
	/*
	if (user_name != NULL)
		delete[] user_name;
	*/
	if (strlen(n) <= MAX_NAME_SIZE) //valid name
	{
		user_name = new char[strlen(n) + 1];
		strcpy_s(user_name, strlen(n), n);
	}
	
	else
		return false;

	return true;
}

bool buyers::setPassword(const char* p) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	/*
	if (password != NULL)
		delete[] password;
		*/
	if ((strlen(p) >= MAX_PASSWORD_SIZE) && (strlen(p) <= MIN_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strcpy_s(password, strlen(p), p);
	}
	else
		return false;

	return true;
}

char * buyers::getName() const
{
	return user_name;
}

char * buyers::getPassword() const
{
	return user_name;
}
address_user buyers::getAddress()  const
{
	return address;
}
