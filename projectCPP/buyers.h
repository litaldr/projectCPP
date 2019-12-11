#ifndef __BUYERS_H
#define __BUYERS_H

#include "address_user.h"
#include "Product.h"
#include "wishList.h"
class buyers
{

public:
	// define length valid for user details


	buyers() = delete; //constructor
	buyers(char *user_name, char *password, const address_user & address); //constructor
	buyers(char *user_name, char *password, const address_user & address, wishList **wishListArr); //constructor

	buyers(const buyers &other);
	~buyers(); // defualt destructor because names strings are allocated static

    // set & get function
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getName()          const;
	char * getPassword()      const;
	address_user getAddress()      const;

	void addProductToWishlist(Product * newProduct);
	int getCountProductInWishList() const;
	wishList **getWishListArr() const;
	void  setCountProductInWishList(int n);
	wishList **reallocWishList(wishList **oldWishListArr, int size);

private:
	//attributes
	char *user_name;
	char *password;
	address_user address;

	
	wishList **WishListArr; //עגלת קניות: מצביעים על מצביעים למוצרים מהמערכים של המוכרים במערכת
	int CountProductInWishList = 0;
							/*
	Product **buyProdustsArr // מערך שמצביע למוצרים מהwishlist אותם הקונה באמת מתכוון לרכוש אבל ההצבעה מתבצעת ישירות למוצר ולא דרך wishlist
	purchase_user purchase; //אובייקט הזמנה\רכישה: מכיל את הפרטי הקונה, מערך מוכרים שמהם הקונה רוכש מוצרים ומחיר סה"כ לרכישה 
	purchase_user **purchase_userArr; // מערך היסטוריית הזמנות של הקונה- מצביע לכל הרכישות שנעשו- מערך זה נותן אינדיקציה להוספת הפידבק עבור מוכר שאכן הקונה קנה ממנו מוצר
	*/
};


#endif

