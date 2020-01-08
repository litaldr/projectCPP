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
ostream& operator<<(ostream& os, const user& u) // operator print user details include his address
{
	os << "User name is: " << u.user_name << endl;
	os << "User password is: " << u.password << endl;
	os << "User address is: " << u.address << endl; //זה סינטקס לקריאת האופרטור הדפסה של הכתובת של האוביקש הנוכחי?

	return os;
}
void user::showUserBasicDeatelis() const
{
	cout << "User name is: " << user_name << endl;
	cout << "User password is: " << password << endl;
	address.show();
}
bool user::operator>(ostream & os, const user & u1, const user & u2) const
{
	return false;
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
char * user::getPassword() const
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
