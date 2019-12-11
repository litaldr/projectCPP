#ifndef  __WISHLIST_H
#define __WISHLIST_H

#include <iostream>
#include <string.h>

#include "product.h"

class sellers;

using namespace std;


#pragma warning (disable: 4996)

class wishList
{
private:
	static int countSerialNumber;// static variable initialized  with 0

public:
	enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };

	wishList() = delete;// we don't allowed to create a new product without the details in the constructor below 
	wishList(const Product & product, sellers * seller);//constructor
	wishList(const wishList& other);// copy constructor
	~wishList(); //destructor // defualt destructor because name allocated static

	// set & get functions
	const Product& getProduct()  const;
	sellers * getseller() const;
	void setProduct(Product* product);
	void setSeller(sellers *seller);

private:
	//attributes
	const Product* product;
	sellers *seller;

};
#endif // 



