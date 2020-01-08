#ifndef __TRADE_SYSTEM_H
#define __TRADE_SYSTEM_H

#include "buyer.h"
#include "seller.h"
#include "buyerAndSeller.h"

#pragma warning (disable: 4996)
class trade_system
{
private:
	// static variable initialized  with 0 - gives serial number to each new product added to the whole system
	static int count_users;
	static int count_sellers;
	static int count_buyers;
	static int count_sellersAndBuyers;
public:

	trade_system() = default; // constructor default
	~trade_system(); // destructor 

//--------not in use---------//
	trade_system(const char *name); // constructor
	
//--------not in use---------//

 //------------------------------set & get function-------------------------------//
	int getCountUsers();
	void setCountSellers();
	int getCountSellers();
	void setCountBuyers();
	int getCountBuyers();
	void setCountBuyersSellers();
	int getCountBuyersSellers();
	user** getUsersArr();
	
	bool setName(const char* n);
	void setCountUsers();
	
	
	//-------- not in use----------//
	const char * getName()  const;
	//-------- not in use----------//

	/*const user**& operator+=(const buyer& other);
	const user**& operator+=(const seller& other);*/

//------------------------------add users to system functions-------------------------------//
	bool addUser(user& user);
	
	user ** reallocUsersArr(user **oldUsersArr, int size); // function increases by one the buyers array for a new buyer in the system
	bool nameAvailable(const char *comperdName); // function checks that all buyers and sellers in the system have different name

 //------------------------------show products in the system functions-------------------------------//
	void showProductWithIdenticalName(const char *nameProduct) const; // function prints all product with identical name

 //------------------------------enum- products categories in the system-------------------------------//
	const char* categoryStr[4] = { "Children", "Electronics" , "Office", "Clothing" }; // define here the string category enum of product to use in print products with identical name #10

private:
//--------------------attributes----------------------//
	char *system_name;
	user **usersArr;
};

#endif
