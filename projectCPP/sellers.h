#ifndef __SELLERS_H
#define __SELLERS_H

#include "address_user.h"
class buyers;
#include "feedback.h"
#include "Product.h"



class sellers
{

public:
	sellers() = delete; //constructor defult
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
	void setCountProduct(int n);
	void showSellerBasicDeatelis() const;
	Product ** reallocProductArr(Product **oldProductArr, int size);
	void addProduct(Product& newProduct);

	Product ** getProductArr() const;
	void addFeedback(Feedback& newFeedback);
	Feedback ** reallocFeedbackArr(Feedback **oldFeedbackArr, int size);
	int getCountFeedback()   const;
	void setCountFeedback(int n);

private:
	//attributes
	char* user_name;
	char* password;
	int CountProduct = 0;
	int CountFeedback = 0;
	address_user address;
	Feedback **feedbackArr; // נוכל להוסיף פידבק רק לאחר שנבצע הזמנה עבור קונה
	Product **ProductArr;
};
#endif
