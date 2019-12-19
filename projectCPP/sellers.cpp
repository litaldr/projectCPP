#include "sellers.h"

sellers::sellers(const char *user_name, const char *password, const address_user &address) : address(address)
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

//sellers::sellers(const sellers &other) : address(other.address)//copy c'tor
//{
//	this->user_name = strdup(other.user_name);
//	this->password = strdup(other.password);
//
//	this->CountProduct = other.CountProduct;
//
//	this->feedbackArr = new Feedback*;// feedback is a pointer therefor it is initialized by it's address.
//	memcpy(this->feedbackArr, other.feedbackArr, sizeof(other.feedbackArr));
//	this->ProductArr = new Product*;// Product is a pointer therefor it is initialized by it's address.
//	memcpy(this->ProductArr, other.ProductArr, sizeof(other.ProductArr));
//
//}

sellers::~sellers() //destructor
{
	// does we need those delete? we allocate string in static way
	
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
	//we also need to delete the feedback & products arr's- ������
}
bool sellers::setName(const char* n) //������ ����� ������ �� ������ ������ �� �������- ����� ������� �� ���� ����� ���������
{
	/*
	if (user_name != NULL)
	   delete[] user_name;
	*/
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

bool sellers::setPassword(const char* p) //������ ����� ������ �� ������ ������ �� �������- ����� ������� �� ���� ����� ���������
{
	/*
	if (password != NULL)
		delete[] password;
		*/
	if ((strlen(p) >= MIN_PASSWORD_SIZE) && (strlen(p) <= MAX_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strncpy(password, p,strlen(p));
		user_name[strlen(p) ] = '\0';
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

char * sellers::getPassword() const
{
	return password;
}

address_user sellers::getAddress()  const
{
	return address;
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
void sellers::showSellerBasicDeatelis() const
{
	cout << "user name is: " << user_name << endl;
	cout << "user password is: " << password << endl;
	address.show();
}
void sellers::addProduct(Product &newProduct)
{
	int i = CountProduct - 1;
	if (CountProduct == 0)
		ProductArr = new Product*;//if it is the first buyer
	else
	{
		ProductArr = reallocProductArr(ProductArr, i + 1);//if it isn't the first buyer
	}
	i++;
	ProductArr[i] = new Product(newProduct);

	CountProduct=i + 1;
}
Product ** sellers::reallocProductArr(Product **oldProductArr, int size)
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

void sellers::addFeedback(Feedback &newFeedback)  
{
	int i = getCountFeedback() - 1;
	if (getCountFeedback() == 0)
		feedbackArr = new Feedback*;//if it is the first buyer
	else
	{
		feedbackArr = reallocFeedbackArr(feedbackArr, i + 1);//if it isn't the first buyer
	}
	i++;
	feedbackArr[i] = new Feedback(newFeedback);

	CountFeedback = i + 1;
}
Feedback ** sellers::reallocFeedbackArr(Feedback **oldFeedbackArr, int size)
{
	Feedback **newFeedbackArr = new Feedback*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newFeedbackArr[i] = oldFeedbackArr[i];
		//delete[]oldProductArr[i]
	}
	delete[]oldFeedbackArr;
	return newFeedbackArr;
}


