#include "sellers.h"

sellers::sellers(const char *user_name, const char *password, const address_user &address) : user(user_name,password,address) // constructor
{
	this->ProductArr = nullptr;
	this->feedbackArr = nullptr;
	this->CountProduct = 0;
	this->CountFeedback = 0;
}

sellers::~sellers() //destructor
{	
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

//------------------------------set & get function-------------------------------//

void  sellers::setCountProduct(int n)
{
	this->CountProduct = n;
}

void  sellers::setCountFeedback(int n)
{
	this->CountFeedback = n;
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

