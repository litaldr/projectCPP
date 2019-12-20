#include "sellers.h"

sellers::sellers(const char *user_name, const char *password, const address_user &address) : address(address) // constructor
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name)] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password)] = '\0';
	this->ProductArr = nullptr;
	this->feedbackArr = nullptr;
	this->CountProduct = 0;
	this->CountFeedback = 0;
}

sellers::~sellers() //destructor
{	
	delete[]user_name;
	delete[]password;
	for (int i = 0; i < CountFeedback; i++)
	{
		delete feedbackArr[i];
	}
	delete[]feedbackArr;
	for (int i = 0; i < CountProduct; i++)
	{
		delete ProductArr[i];
	}
	delete[]ProductArr;
}

void sellers::showSellerBasicDeatelis() const
{
	cout << "User name is: " << user_name << endl;
	cout << "User password is: " << password << endl;
	address.show();
}

//------------------------------set & get function-------------------------------//

bool sellers::setName(const char* n) 
{

	if (strlen(n) <= MAX_NAME_SIZE) //valid name 
	{
		user_name = new char[strlen(n) + 1];
		strncpy(user_name, n,strlen(n));
		user_name[strlen(n) ] = '\0';
	}
	else
		return false;

	return true;
}

void  sellers::setCountProduct(int n)
{
	this->CountProduct = n;
}

void  sellers::setCountFeedback(int n)
{
	this->CountFeedback = n;
}


char * sellers::getName() const
{
	return user_name;
}

int sellers::getCountProduct() const
{
	return CountProduct;
}

int sellers::getCountFeedback() const
{
	return CountFeedback;
}

Product ** sellers::getProductArr() const
{
	return ProductArr;
}

//----------------not in use-----------------//
Feedback ** sellers::getFeedbackArr() const
{
	return feedbackArr;
}

char * sellers::getPassword() const
{
	return password;
}

address_user sellers::getAddress()  const
{
	return address;
}


bool sellers::setPassword(const char* p)
{
	if ((strlen(p) >= MIN_PASSWORD_SIZE) && (strlen(p) <= MAX_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strncpy(password, p, strlen(p));
		user_name[strlen(p)] = '\0';
	}
	else
		return false;

	return true;
}
//----------------not in use-----------------//

//------------------------------add product and feedback functions-------------------------------//

void sellers::addProduct(Product &newProduct)
{
	int i = CountProduct - 1;
	if (CountProduct == 0) //if it is the first buyer
		ProductArr = new Product*;
	else
	{
		ProductArr = reallocProductArr(ProductArr, i + 1); //if it isn't the first buyer
	}
	i++;
	ProductArr[i] = new Product(newProduct);

	CountProduct=i + 1; // increase the counter of products in product array
}

Product ** sellers::reallocProductArr(Product **oldProductArr, int size) // function increase by one the products array for the new product
{
	Product **newProductArr = new Product*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newProductArr[i] = oldProductArr[i];
	}
	delete[]oldProductArr;
	return newProductArr;
}

void sellers::addFeedback(Feedback &newFeedback)  
{
	int i = getCountFeedback() - 1;
	if (getCountFeedback() == 0) //if it is the first buyer
		feedbackArr = new Feedback*;
	else
	{
		feedbackArr = reallocFeedbackArr(feedbackArr, i + 1);//if it isn't the first buyer
	}
	i++;
	feedbackArr[i] = new Feedback(newFeedback);

	CountFeedback = i + 1; // increase the counter of feedback in feedback array
}

Feedback ** sellers::reallocFeedbackArr(Feedback **oldFeedbackArr, int size) // function increase by one the feedback array for the new feedback
{
	Feedback **newFeedbackArr = new Feedback*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newFeedbackArr[i] = oldFeedbackArr[i];
	}
	delete[]oldFeedbackArr;
	return newFeedbackArr;
}


