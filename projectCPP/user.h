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
	char * getName()     const;
	
	//----------------not in use-----------------//
	
	char * getPassword() const;
	address_user getAddress()  const;
	bool setPassword(const char* newPassword);
	
	
	virtual void addProduct(Product &newProduct) = 0;
	virtual void setCountProduct(int n) = 0;
	virtual int getCountProduct()   const = 0;
	virtual Product ** getProductArr() const = 0;

	virtual void setCountFeedback(int n) = 0;
	virtual int getCountFeedback()   const = 0;
	virtual void showAllSellersInBuyerorder() const = 0; // show all the sellers that the buyer has bought from
	virtual int getCountOrders() const = 0;
	virtual order **getOrdersArr() const = 0;
	virtual void addFeedback(Feedback &newFeedback) = 0;


protected:
	char* user_name;
	char* password;
	address_user address;
	
	user(const char *user_name, const char *password, const address_user &address);

};

#endif // !
