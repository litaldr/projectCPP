#include "user.h"



user::user(const char *user_name, const char *password, const address_user &address):address(address)
{
	this->user_name = strdup(user_name);
	this->password = strdup(password);
}
user::~user()
{
	delete[]user_name;
	delete[]password;
}


bool user::setName(const char* name)
{
	if (strlen(name) <= MAX_NAME_SIZE) //valid name 
	{
		if (user_name != NULL)
			delete user_name;
		user_name = strdup(name);
	}
	else
		return false;
	return true;
}
const char* user::getName() const
{
	return user_name;
}
const char * user::getPassword() const
{
	return password;
}
bool user::setPassword(const char* newPassword)
{
	if ((strlen(newPassword) >= MIN_PASSWORD_SIZE) && (strlen(newPassword) <= MAX_PASSWORD_SIZE))// password in range 8-20
	{
		if (password != NULL)
			delete password;
		password = strdup(newPassword);
	}
	else
		return false;
	return true;
	
}
const address_user& user::getAddress()  const
{
	return address;
}

ostream & operator<<(ostream & os, const user & theUser)
{
	cout << "in operator<<(base&)\n";
	os << "user name: "<< theUser.user_name << endl;
	os << "user password: " << theUser.password << endl;
	os << "user address: " << theUser.address << endl;
	theUser.toOs(os);
	return os;
}
