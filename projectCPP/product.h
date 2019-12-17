#ifndef  __PRODUCT_H
#define __PRODUCT_H


#include "address_user.h" // include the MAX_NAME_SIZE =20

class Product
{
private:
	static int countSerialNumber;// static variable initialized  with 0

public:
	enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };
	const char* categoryStr[4] = { "Children", "Electronics" , "Office", "Clothing" }; // define here the string category enum of product to use in print products with identical name #10

	Product() = delete;// we don't allowed to create a new product without the details in the constructor below 
	Product(const char *productName, eCategory category, double price);//constructor
	Product(const Product& other);// copy constructor
	~Product(); //destructor // defualt destructor because name allocated static

    // set & get functions
	bool setName(const char *n);//אנחנו לא רוצות  לאפשר שינויים?
	bool setCategory(int i);
    void setPrice(double p);
			   
	char * getName()  const;
	eCategory getCategory()  const;
	int getItemSerialNumber()  const;
	double getPrice()  const;
	void show()  const;

	friend class wishList;
private:
	//attributes
	char *productName;
	eCategory category;
	double price;
	int serialNumber;


};
#endif //


