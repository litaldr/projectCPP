#include "Product.h"

int Product::countSerialNumber = 0;

Product::Product(const char *productName, eCategory category, double price)  //constructor
{
	this->productName = new char[strlen(productName) + 1];
	strncpy(this->productName, productName, strlen(productName));
	this->productName[strlen(productName) + 1] = '\0';

	serialNumber = ++countSerialNumber;
	this->category = category;
	this->price = price;
}

Product::Product(const Product & other) //copy c'tor
{
	this->productName = strdup(other.productName);
	this->category = other.category;
	this->serialNumber = other.serialNumber;
	this->price = other.price;

}

Product::~Product() //destructor
{
	delete[]productName;
}


bool Product::setName(const char* n)
{
	/*
	if (n != NULL)
	delete[] user_name;
	*/

	if (strlen(n) <= MAX_NAME_SIZE) //valid name
	{
		productName = new char[strlen(n) + 1];
		strcpy(productName, n);
		productName[strlen(n) + 1] = '\0';
	}
	else
		return false;
	return true;
}

bool Product::setCategory(int i)
{
	/*
	if (n != NULL)
	delete[] user_name;
	*/
	if (i == 0)
		eCategory category= CHILDREN;
	else if (i == 1)
		eCategory category= ELECTRONICS;
	else if (i == 2)
		eCategory category= OFFICE;
	else if (i == 3)
		eCategory category= CLOTHING;
	else 
		return false;

	return true;
}

void Product::setPrice(double p)
{
	this->price = p;
}

char * Product::getName()  const
{
	return productName;
}

Product::eCategory Product::getCategory()  const
{
	return category;
}

double Product::getPrice()  const
{
	return price;
}

int Product::getItemSerialNumber() const
{
	return serialNumber;
}


