#ifndef __TRADE_SYSTEM_H
#define __TRADE_SYSTEM_H

#include "buyers.h"
#include "sellers.h"


#pragma warning (disable: 4996)
class trade_system
{
private:
	// static variable initialized  with 0 - gives serial number to each new product added to the whole system
	static int count_buyers; 
	static int count_sellers;

public:

	trade_system() = default; // constructor defualt
	~trade_system(); // destructor 

//--------not in usr---------//
	trade_system(const char *name); // constructor
	trade_system(const trade_system & other); // copy constructor
//--------not in usr---------//

 //------------------------------set & get function-------------------------------//
	int getCountBuyer();
	int getCountSeller();
	buyers** getBuyersArr();
	sellers** getSellersArr();

	bool setName(const char* n);
	void setCountBuyer(int i);
	void setCountSeller(int j);
	//-------- not in use----------//
	char * getName()  const;
	//-------- not in use----------//

//------------------------------add buyers and sellers to system functions-------------------------------//
	bool addBuyer(buyers& buyer);
	bool addSeller(sellers &seller);

	buyers ** reallocbuyers(buyers **oldBuyersArr, int size); // function increases by one the buyers array for a new buyer in the system
	sellers ** reallocSellers(sellers **oldSellersArr, int size); // function increases by one the sellers array for a new seller in the system

	bool nameAvailable(char *comperdName, bool flag); // function checks that all buyers and sellers in the system have different name

 //------------------------------show products in the system functions-------------------------------//
	void showProductWithIdenticalName(const char *nameProduct) const; // function prints all product with identical name

 //------------------------------enum- products categiries in the system-------------------------------//
	const char* categoryStr[4] = { "Children", "Electronics" , "Office", "Clothing" }; // define here the string category enum of product to use in print products with identical name #10

private:
//--------------------attributes----------------------//
	char *system_name;
	buyers** buyersArr;
	sellers** sellersArr;

};

#endif