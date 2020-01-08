#include "address_user.h"

#ifndef __USER_H 
#define __USER_H

class user
{
public:
	user()=delete;
	virtual ~user();
	void showUserBasicDeatelis() const;
	bool setName(const char* name);
	const char * getName()     const;
	
	//----------------not in use-----------------//
	
	const char * getPassword() const;
	const address_user& getAddress()  const;
	bool setPassword(const char* newPassword);
	
	

protected:
	char* user_name;
	char* password;
	address_user address;
	
	user(const char *user_name, const char *password, const address_user &address);

};

#endif // !
