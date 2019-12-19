#ifndef  __WISHLIST_H
#define __WISHLIST_H

#include "product.h"

class sellers;


class wishList
{
private:
	static int countSerialNumber;// static variable initialized  with 0

public:
	enum eCategory { CHILDREN, ELECTRONICS, OFFICE, CLOTHING };

	wishList() = default;// we don't allowed to create a new product without the details in the constructor below 
	wishList( Product * product);//constructor
	wishList(Product * product, sellers * seller);
	wishList(const wishList& other);
	~wishList();
 
	//wishList(const Product & product);
	
	

	//~wishList(); //destructor // defualt destructor because name allocated static
	
	// set & get functions
	Product* getProduct()  const;
	sellers * getseller() const;
	void setSeller(sellers * seller);
	void setProduct(Product * newProduct);

	friend class Product;

private:
	//attributes
	Product* product;
	sellers *seller;
	
}; 
#endif // 



