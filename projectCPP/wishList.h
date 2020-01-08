#ifndef  __WISHLIST_H
#define __WISHLIST_H

#include "product.h"

class seller;


class wishList
{

private:
	static int countSerialNumber;// static variable initialized with 0

public:
	//enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };

	wishList() = delete;// we don't allowed to create a new product without the details in the constructor below 
	wishList(Product * product, seller * seller); //constructor
	wishList(const wishList& other); //copy constructor
	
 //-------------not in use---------------//
	wishList(Product * product);//constructor product only 	
//-------------not in use---------------//

 
//----------------------set & get functions---------------------//
	Product* getProduct()  const;
	seller * getseller() const;


	friend class Product;

private:
//-------------attributes---------------//
	Product *product;
	seller *theSeller;
	
}; 
#endif 



