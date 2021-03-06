#ifndef  __WISHLIST_H
#define __WISHLIST_H

#include "product.h"

class sellers;


class wishList
{

private:
	static int countSerialNumber;// static variable initialized with 0

public:
	enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };

	wishList() = delete;// we don't allowed to create a new product without the details in the constructor below 
	wishList(Product * product, sellers * seller); //constructor
	wishList(const wishList& other); //copy constructor
	//~wishList(); //destructor

 //-------------not in use---------------//
	wishList(Product * product);//constructor product only 	
//-------------not in use---------------//

 
//----------------------set & get functions---------------------//
	Product* getProduct()  const;
	sellers * getseller() const;
//-------------not in use---------------//
	void setProduct(Product * newProduct);
	void setSeller(sellers * seller);
//-------------not in use---------------//

	friend class Product;

private:
//-------------attributes---------------//
	Product *product;
	sellers *seller;
	
}; 
#endif 



