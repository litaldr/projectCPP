#ifndef __BUYERS_H
#define __BUYERS_H

#include "address_user.h"
#include "Product.h"
#include "wishList.h"
#include "order.h"
class buyers
{

public:
	
	buyers() = delete; //constructor
	buyers(char *user_name, char *password,const address_user & address); //constructor
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
	void setCountProductInWishList(int n);

	// functions for  orders of buyer
	void addOrderToOrdersArr(order *newOrder, double totalPrice);
	order **reallocOrdersArr(order **oldOrdersArr, int size);
	order **getOrdersArr() const;
	int getCountOrders() const;
	void addOneToCountOrders();
	void showBuyerBasicDeatelis() const;
	void showWishList() const;
	bool checkIfSellerExistsInAllOrders(const sellers *seller);
	void deleteProductFromBuyerWishList(int OrderIndex);
	void showBuyerorderByIndex(int index) const;
private:
	//attributes
	char *user_name;
	char *password;
	address_user address;

	wishList **WishListArr; 
	int CountProductInWishList;

	
	order **ordersArr; 
	int CountOrders;

	/*
	purchase_user **purchase_userArr; // מערך היסטוריית הזמנות של הקונה- מצביע לכל הרכישות שנעשו- מערך זה נותן אינדיקציה להוספת הפידבק עבור מוכר שאכן הקונה קנה ממנו מוצר
	*/
};


#endif

