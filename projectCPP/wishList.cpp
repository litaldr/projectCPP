#include "wishList.h"

int wishList::countSerialNumber = 0;


wishList::wishList(Product * product, sellers * seller) : product(product), seller(seller) {} // constructor

wishList::wishList(const wishList& other) : product(other.product), seller(other.seller) {} // copy constructor

//-------------not in use---------------//
wishList::wishList(Product * product) : product(product) //constructor
{
	this->seller = nullptr;
}
//-------------not in use---------------//

//wishList::~wishList() {} // destructor


//----------------------set & get functions---------------------//

Product* wishList::getProduct()  const
{
	return product;
}

sellers * wishList::getseller() const
{
	return seller;
}

//-------------not in use---------------//
void wishList::setProduct(Product * newProduct)
{
	this->product = newProduct;
}

void wishList::setSeller(sellers *seller)// not in use
{
	this->seller = seller;
}
//-------------not in use---------------//

