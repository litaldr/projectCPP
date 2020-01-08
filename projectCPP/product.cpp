#include "Product.h"

int Product::countSerialNumber = 0; // init

Product::Product(const char *productName, eCategory category, double price)  //constructor
{
	this->productName = new char[strlen(productName) + 1];
	strncpy(this->productName, productName, strlen(productName));
	this->productName[strlen(productName) ] = '\0';

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

ostream& operator<<(ostream& os, const Product& p) // operator print address
{
	os << "Product name is: " << p.productName << endl;
	os << "Product category is: " << p.categoryStr[p.category] << endl;
	os << "Product serial number is: " << p.serialNumber << endl;
	os << "Product price is: " << p.price << endl;
	os << "---------------------------------" << endl;

	return os;
}

void Product::show()  const // function prints product details
{
	cout << "Product name is: " << productName << endl;
	cout << "Product category is: " << categoryStr[category] << endl;
	cout << "Product serial number is: " << serialNumber << endl;
	cout << "Product price is: " << price << endl;
	cout << "---------------------------------" << endl;
} 


//---------------------------------set & get functions------------------------------//
char * Product::getName()  const
{
	return productName;
}

double Product::getPrice()  const
{
	return price;
}

int Product::getItemSerialNumber() const
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

bool Product::setCategory(int i)
{
	eCategory category = static_cast<eCategory>(i);
	if (category)
		return true;
	/*if (i == 0)
		eCategory category = CHILDREN;
	else if (i == 1)
		eCategory category = ELECTRONICS;
	else if (i == 2)
		eCategory category = OFFICE;
	else if (i == 3)
		eCategory category = CLOTHING;*/
	else
		return false;

	//return true;
}

bool Product::setPrice(double p)
{
	if (p >= 0)
	{
		this->price = p;
		return true;
	}
	else
		return false;
}

Product::eCategory Product::getCategory()  const
{
	return category;
}
