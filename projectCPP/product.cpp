#include "Product.h"

int Product::countSerialNumber = 0; 

Product::Product(const char *productName, eCategory category, double price)  //constructor
{
	this->productName = strdup(productName);
	serialNumber = ++countSerialNumber;
	this->category = categoryStr[category];
	this->price = price;
}

Product::Product(const Product & other) //copy constructor
{
	this->productName = strdup(other.productName);
	this->category = strdup(category);
	this->serialNumber = other.serialNumber;
	this->price = other.price;

}

Product::~Product() //destructor
{
	delete[] productName;
}


void Product::show()  const // function prints product details
{
	cout << "Product name is: " << productName << endl;
	cout << "Product category is: " << category << endl;
	cout << "Product serial number is: " << serialNumber << endl;
	cout << "Product price is: " << price << endl;
	cout << "---------------------------------" << endl;
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
		category = categoryStr[type];
		return true;
	}
		return false;
}

void Product::setPrice(double p)
{
	this->price = p;
}

const char* Product::getCategory()  const
{
	return category;
}
