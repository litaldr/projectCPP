#ifndef  __PRODUCT_H
#define __PRODUCT_H

#include "address_user.h" // include the MAX_NAME_SIZE = 20 for the product name

class Product
{

private:
	static int countSerialNumber;// static variable initialized  with 0 - gives serial number to each new product added to the whole system

public:
	enum eCategory { CHILDREN=0, ELECTRONICS, OFFICE, CLOTHING };
	const char* categoryStr[4] = { "Children", "Electronics" , "Office", "Clothing" }; // define here the string category enum of product to use in print products with identical name #10

	Product() = delete;// we don't allowed to create a new product without the details in the constructor below 
	Product(const char *productName,  eCategory category, double price);//constructor
	Product(const Product& other);// copy constructor
	~Product(); //destructor 

	friend ostream& operator<<(ostream& os, const Product& theProduct);

 //---------------------------------set & get functions------------------------------//
	const char * getName()  const;
	const int getItemSerialNumber()  const;
	const double getPrice()  const;

 //--------------------not in use--------------------//
	bool setName(const char *n);
	bool setCategory(eCategory type);
    void setPrice(double p);
			
	
//-------------------------------------------------//

	
	friend class wishList; 

private:
	//--------------------attributes--------------------//
	char *productName;
	eCategory category;
	double price;
	int serialNumber;

};
#endif 


