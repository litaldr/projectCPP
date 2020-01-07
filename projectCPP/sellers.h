#ifndef __SELLERS_H
#define __SELLERS_H

class buyers;
#include "feedback.h"
#include "Product.h"
#include "user.h"

class sellers: virtual public user
{

public:
	sellers() = delete; //delete constructor- we don't allow default constructor of seller
	sellers(const char *user_name, const char *password, const address_user &address); // constructor
	 //not interested in copy constructor- we don't copy a seller(person)
	virtual ~sellers(); //destructor 


//------------------------------set & get function-------------------------------//
	void setCountProduct(int n) ;
	void setCountFeedback(int n) ;

	int getCountProduct()   const ;
	int getCountFeedback()   const ;
	Product ** getProductArr() const   ;
	//----------------not in use-----------------//
	Feedback ** getFeedbackArr() const;
	
	//------------------------------add product and feedback functions-------------------------------//
	 void addProduct(Product& newProduct) ;
	Product ** reallocProductArr(Product **oldProductArr, int size);

	 void addFeedback(Feedback& newFeedback) ;
	Feedback ** reallocFeedbackArr(Feedback **oldFeedbackArr, int size);

protected:
//----------------attributes-----------------//

	Feedback **feedbackArr; // pointers array to feedback objects
	int CountFeedback; // index counts feedback in feedback array per seller (not a static variable)

	Product **ProductArr; // pointers array to products objects
	int CountProduct; // index counts product in product array per seller (not a static variable)

};
#endif
