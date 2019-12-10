#include "sellers.h"

sellers::sellers(const char *user_name, const char *password, const address_user &address, Feedback **feedbackArr, Product **ProductArr) : address(address)// constructor
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name) + 1] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password) + 1] = '\0';

}
sellers::sellers(const char *user_name, const char *password, const address_user &address) : address(address)
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name) + 1] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password) + 1] = '\0';
}

sellers::sellers(const sellers &other) : address(other.address)//copy c'tor// מקבל כלום other יש בעיה עם ההעתקה!!!
{
	this->user_name = strdup(other.user_name);
	this->password = strdup(other.password);

	this->CountProduct = other.CountProduct;

	this->feedbackArr = new Feedback*;// feedback is a pointer therefor it is initialized by it's address.
	memcpy(this->feedbackArr, feedbackArr, sizeof(feedbackArr));
	this->ProductArr = new Product*;// Product is a pointer therefor it is initialized by it's address.
	memcpy(this->ProductArr, ProductArr, sizeof(ProductArr));

}

sellers::~sellers() //destructor
{
	// does we need those delete? we allocate string in static way
	delete[]user_name;
	delete[]password;

	//we also need to delete the feedback & products arr's- חשובבב
}
bool sellers::setName(const char* n) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	/*
	if (user_name != NULL)
	   delete[] user_name;
	*/
	if (strlen(n) <= MAX_NAME_SIZE) //valid name 
	{
		user_name = new char[strlen(n) + 1];
		strcpy(user_name, n);
		user_name[strlen(n) + 1] = '\0';
	}
	else
		return false;

	return true;
}

bool sellers::setPassword(const char* p) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	/*
	if (password != NULL)
		delete[] password;
		*/
	if ((strlen(p) >= MIN_PASSWORD_SIZE) && (strlen(p) <= MAX_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strcpy(password, p);
		user_name[strlen(p) + 1] = '\0';
	}
	else
		return false;

	return true;
}
void  sellers::setCountBuyer(int n)
{
	this->CountProduct = n;
}

char * sellers::getName() const
{
	return user_name;
}

char * sellers::getPassword() const
{
	return user_name;
}

address_user sellers::getAddress()  const
{
	return address;
}
int sellers::getCountProduct() const
{
	return CountProduct;
}

void sellers::addProduct(Product &newProduct)
{
	int i = getCountProduct() - 1;
	if (getCountProduct() == 0)
		ProductArr = new Product*;//if it is the first buyer
	else
	{
		ProductArr = reallocProduct(ProductArr, i + 1);//if it isn't the first buyer
	}
	i++;
	ProductArr[i] = new Product(newProduct);

	setCountBuyer(i + 1);
}
Product ** sellers::reallocProduct(Product **oldProductArr, int size)
{
	Product **newProductArr = new Product*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newProductArr[i] = oldProductArr[i];
		//delete[]oldProductArr[i]
	}
	delete[]oldProductArr;
	return newProductArr;
}
