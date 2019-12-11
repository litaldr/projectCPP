#ifndef __SELLERS_H
#define __SELLERS_H

#include "address_user.h"
class buyers;
class Feedback;
#include "Product.h"



class sellers
{

public:
	// define length valid for user details
	sellers() = delete; //constructor defult
	sellers(const char *user_name, const char *password, const address_user &address, Feedback **feedbackArr = nullptr, Product **ProductArr = nullptr); //להוסיף item* items=nullptr //define constructor
	sellers(const char *user_name, const char *password, const address_user &address); //define constructor

	sellers(const sellers &other);//copy c'tor
	~sellers(); //destructor // defualt destructor because strings allocated static

	// set & get function
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getName()     const;
	char * getPassword() const;
	address_user getAddress()  const;
	int getCountProduct()   const;
	void setCountBuyer(int n);

	Product ** reallocProduct(Product **oldProductArr, int size);
	void addProduct(Product& newProduct);

	Product ** getProductArr() const;

	void addFeedback(buyers *buyer);// choice 4 in the interactive shell

private:
	//attributes
	char* user_name;
	char* password;
	int CountProduct = 0;

	address_user address;
	Feedback **feedbackArr; // נוכל להוסיף פידבק רק לאחר שנבצע הזמנה עבור קונה
	Product **ProductArr;
};
#endif
