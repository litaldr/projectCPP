#include "wishList.h"


wishList::wishList(Product * product, seller * seller) : product(product), theSeller(seller) {} // constructor

wishList::wishList(const wishList& other) : product(other.product), theSeller(other.theSeller) {} // copy constructor

//-------------not in use---------------//
wishList::wishList(Product * product) : product(product) //constructor
{
	this->theSeller = nullptr;
}
//----------------------set & get functions---------------------//

Product* wishList::getProduct()  const
{
	return product;
}

seller * wishList::getseller() const
{
	return theSeller;
}

ostream & operator<<(ostream & os, const wishList & theItemInWishList)
{
	os <<theItemInWishList.product<<endl;
	
	return os;
}
