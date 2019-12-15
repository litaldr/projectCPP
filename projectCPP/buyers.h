#ifndef __BUYERS_H
#define __BUYERS_H

#include "address_user.h"
#include "Product.h"
#include "wishList.h"
#include "order.h"
class buyers
{

public:
	// define length valid for user details
	//buyers(char *user_name, char *password, const address_user & address, wishList **WishListArr, order **ordersArr);
	buyers() = delete; //constructor
	buyers(char *user_name, char *password, const address_user & address); //constructor
	buyers(char *user_name, char *password, const address_user & address, wishList **wishListArr, order **ordersArr); //constructor

	buyers(const buyers &other);
	~buyers(); // default destructor because names strings are allocated static

	// set & get function
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getName()          const;
	char * getPassword()      const;
	address_user getAddress()      const;

	// functions for wish list of buyer
	void addProductToWishlist(Product * newProduct);
	wishList **reallocWishList(wishList **oldWishListArr, int size);
	wishList **getWishListArr() const;
	int getCountProductInWishList() const;
	void  setCountProductInWishList(int n);

	// functions for  orders of buyer
	void addOrderToOrdersArr(order *newOrder, double totalPrice);
	order **reallocOrdersArr(order **oldOrdersArr, int size);
	order **getOrdersArr() const;
	int getCountOredersInOrders() const;
	void setCountOredersInOrders(int n);

	void showWishList() const;
	bool checkIfSellerExistsInAllOrders(const sellers *seller);
private:
	//attributes
	char *user_name;
	char *password;
	address_user address;

	wishList **WishListArr; 
	int CountProductInWishList = 0;

	
	order **ordersArr; //ההקצאה לא עובדת בגלל הקופי קונסטרקטור צריך לתקן
	int CountOrdersInOrders = 0;

	/*
	purchase_user **purchase_userArr; // מערך היסטוריית הזמנות של הקונה- מצביע לכל הרכישות שנעשו- מערך זה נותן אינדיקציה להוספת הפידבק עבור מוכר שאכן הקונה קנה ממנו מוצר
	*/
};


#endif

