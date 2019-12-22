#ifndef __SELLERS_H
#define __SELLERS_H

class buyers;
#include "feedback.h"
#include "Product.h"

class sellers
{

public:
	sellers() = delete; //delete constructor- we don't allow default constructor of seller
	sellers(const char *user_name, const char *password, const address_user &address); // constructor
	 //not interested in copy constructor- we don't copy a seller(person)
	~sellers(); //destructor 

	void showSellerBasicDeatelis() const;// function show basic details of seller

//------------------------------set & get function-------------------------------//
	bool setName(const char* n);
	void setCountProduct(int n);
	void setCountFeedback(int n);

	char * getName()     const;
	int getCountProduct()   const;
	int getCountFeedback()   const;
	Product ** getProductArr() const;
	//----------------not in use-----------------//
	Feedback ** getFeedbackArr() const;
	char * getPassword() const;
	address_user getAddress()  const;

	bool setPassword(const char* p);
	//----------------not in use-----------------//



	//------------------------------add product and feedback functions-------------------------------//
	void addProduct(Product& newProduct);
	Product ** reallocProductArr(Product **oldProductArr, int size);

	void addFeedback(Feedback& newFeedback);
	Feedback ** reallocFeedbackArr(Feedback **oldFeedbackArr, int size);

private:
//----------------attributes-----------------//
	char* user_name;
	char* password;
	address_user address;

	Feedback **feedbackArr; // pointers array to feedback objects
	int CountFeedback; // index counts feedback in feedback array per seller (not a static variable)

	Product **ProductArr; // pointers array to products objects
	int CountProduct; // index counts product in product array per seller (not a static variable)

};
#endif
