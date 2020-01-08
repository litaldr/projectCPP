#ifndef  __WISHLIST_H
#define __WISHLIST_H

#include "product.h"

class seller;


class wishList
{

public:
	//enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };

	wishList() = delete;// we don't allowed to create a new product without the details in the constructor below 
	wishList(Product * product, seller * seller); //constructor
	wishList(const wishList& other); //copy constructor
	
	friend ostream& operator<<(ostream& os, const wishList& theItemInWishList);

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



