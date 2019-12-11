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

	wishList() = default;// we don't allowed to create a new product without the details in the constructor below 
	wishList(const Product & product, sellers * seller);//constructor
    wishList(const Product & product);
	
	

	~wishList(); //destructor // defualt destructor because name allocated static
	
	// set & get functions
	const Product& getProduct()  const;
	const sellers * getseller() const;
	void setSeller(const sellers & seller);
	friend class Product;

private:
	//attributes
	Product product;
	const sellers *seller;

};
#endif // 



