#include "wishList.h"

int wishList::countSerialNumber = 0;

wishList::wishList( Product * product) : product(product) //constructor
{
	this->seller = nullptr;
}
//wishList::wishList(const Product & product) : product(product) {}// c'tor
wishList::wishList(const wishList& other) : product(other.product), seller(other.seller) {}

wishList::wishList(Product * product, sellers * seller) : product(product), seller(seller) {}

wishList::~wishList() {}

void wishList::setProduct(Product * newProduct)
{
	this->product = newProduct;
}
void wishList::setSeller(sellers *seller)// not in use
{
	this->seller = seller;
}


 Product* wishList::getProduct()  const
{
	return product;
}
 sellers * wishList::getseller() const
{
	return seller;
}

