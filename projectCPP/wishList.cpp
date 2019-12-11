#include "wishList.h"

int wishList::countSerialNumber = 0;

wishList::wishList(const Product & product, sellers * seller) : product(&product) //constructor
{
	this->seller = seller;
}

wishList::wishList(const wishList & other) //copy c'tor
{
	this->product = other.product;
	this->seller = other.seller;
}

wishList::~wishList() //destructor
{
	
	delete[]seller;
}


const Product& wishList::getProduct()  const
{
	return *product;
}
sellers * wishList::getseller() const
{
	return seller;
}

void wishList::setProduct(Product* product)
{
	this->product = product;
}
void wishList::setSeller(sellers *seller)
{
	this->seller = seller;
}

