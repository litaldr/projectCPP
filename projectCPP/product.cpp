#include "Product.h"

int Product::countSerialNumber = 0; 

Product::Product(const char *productName, eCategory category, double price)  //constructor
{
	this->productName = strdup(productName);
	serialNumber = ++countSerialNumber;
	this->category = category;
	this->price = price;
}

Product::Product(const Product & other) //copy constructor
{
	this->productName = strdup(other.productName);
	this->category = other.category;
	this->serialNumber = other.serialNumber;
	this->price = other.price;

}

Product::~Product() //destructor
{
	delete[] productName;
}

ostream & operator<<(ostream & os, const Product & theProduct)
{
	os << "Product name is: " << theProduct.productName << endl;
	os << "Product category is: " << theProduct.categoryStr[theProduct.category] << endl;
	os << "Product serial number is: " << theProduct.serialNumber << endl;
	os << "Product price is: " << theProduct.price << endl;
	
	return os;
}

 


//---------------------------------set & get functions------------------------------//
const char * Product::getName()  const
{
	return productName;
}

const double Product::getPrice()  const
{
	return price;
}

const int Product::getItemSerialNumber() const
{
	return serialNumber;
}

//--------------------not in use--------------------//

bool Product::setName(const char* n)
{
	if (strlen(n) <= MAX_NAME_SIZE) //valid name
	{
		productName = new char[strlen(n) + 1];
		strncpy(productName, n, strlen(n));
		productName[strlen(n)] = '\0';
	}
	else
		return false;
	return true;
}

bool Product::setCategory(eCategory type)
{
	if (type >= 0 && type <= 3)
	{
		category = type;
		return true;
	}
		return false;
}

void Product::setPrice(double p)
{
	this->price = p;
}


