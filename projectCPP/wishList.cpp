#include "wishList.h"

int wishList::countSerialNumber = 0;

wishList::wishList( Product * product) : product(product) //constructor
{
	this->seller = nullptr;
}
//wishList::wishList(const Product & product) : product(product) {}// c'tor


void wishList::setProduct(Product * newProduct)
{
	this->product = newProduct;
}
void wishList::setSeller(sellers *seller) // יש בעיה בגישה למוכר לא מצליחות להכניס פויינטר למוכר בתוך העגלת קניות 
{
	this->seller = seller;
}

wishList::~wishList() //destructor
{
	
	delete seller;
}


 Product* wishList::getProduct()  const
{
	return product;
}
 sellers * wishList::getseller() const
{
	return seller;
}

