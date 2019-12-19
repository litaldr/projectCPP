#ifndef __BUYERS_H
#define __BUYERS_H


#include "wishList.h"
#include "order.h"
class buyers
{

public:
	
	buyers() = delete; //constructor
	buyers(char *user_name, char *password,const address_user & address); //constructor
	~buyers(); //  destructor 
	
	void showBuyerBasicDeatelis() const;

	// --------------------------set & get function--------------------------//
	char * getName()          const;
	
	//----not in use yet-------//
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getPassword()      const;
	address_user getAddress()      const;
	//---------------------------//

	// ------------------------functions for wish list of buyer-----------------//

	void addProductToWishlist(Product * newProduct, sellers * newSeller); // add a new product to a wish list array of specific buyer
	wishList **reallocWishList(wishList **oldWishListArr, int size); // using this function in "addProductToWishlist" for increasing the wish list array 
	wishList **getWishListArr() const;
	void showWishList() const;
	int getCountProductInWishList() const;
	void addOneToWishListArr(); // using this function to update the current size of wish list array after adding a wish list object to wish list array 
	void deleteProductFromBuyerWishList(int OrderIndex); // using function to update wish list array after payment (option 7 in interactive shell)

	// --------------------------functions for  orders of buyer-----------------//
	void addOrderToOrdersArr(order *newOrder); // add a new order to a order array of specific buyer
	order **reallocOrdersArr(order **oldOrdersArr, int size); // using this function in "addOrderToOrdersArr" for increasing the orders array
	order **getOrdersArr() const;
	int getCountOrders() const;
	void addOneToCountOrders();// count orders per buyer
	bool checkIfSellerExistsInAllOrders(const sellers *seller); 
	// this function prevents duplicate sellers in the sellers array of orders,if the buyer bought more then once from a seller
	void showBuyerorderByIndex(int index) const;//shows a specific order for a specific buyer
	void showAllSellersInBuyerorder() const;
	
	
	
private:
	//------------------------------attributes---------------------//
	char *user_name;
	char *password;
	address_user address;

	wishList **WishListArr; // pointers array to wish list objects
	int CountProductInWishList;// index that count product in wish list per buyer (not a static variable)
	
	order **ordersArr; // pointers array to order objects-  represent the history transactions
	int CountOrders; // index that count orders in order array per buyer (not a static variable)

};
#endif

