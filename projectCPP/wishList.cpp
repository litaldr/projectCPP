#include "wishList.h"

int wishList::countSerialNumber = 0;

wishList::wishList( Product * product) : product(product) //constructor
{
	this->seller = nullptr;
}
//wishList::wishList(const Product & product) : product(product) {}// c'tor

wishList::wishList(Product * product, sellers * seller) : product(product), seller(seller) {}

void wishList::setProduct(Product * newProduct)
{
	this->product = newProduct;
}
void wishList::setSeller(sellers *seller)
{
	this->seller = seller;
}

//wishList::~wishList() //destructor
//{
//	
//	
//}


 Product* wishList::getProduct()  const
{
	return product;
}
 sellers * wishList::getseller() const
{
	return seller;
}

