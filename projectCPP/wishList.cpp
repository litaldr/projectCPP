#include "wishList.h"

int wishList::countSerialNumber = 0;

wishList::wishList(const Product & product, sellers * seller) : product(product) //constructor
{
	this->seller = seller;
}
wishList::wishList(const Product & product) : product(product) {}// c'tor



void wishList::setSeller(const sellers & seller) // יש בעיה בגישה למוכר לא מצליחות להכניס פויינטר למוכר בתוך העגלת קניות 
{
	this->seller = &seller;
}

wishList::~wishList() //destructor
{
	
	delete[]seller;
}


const Product& wishList::getProduct()  const
{
	return product;
}
const sellers * wishList::getseller() const
{
	return seller;
}

