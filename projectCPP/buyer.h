#ifndef __BUYER_H
#define __BUYER_H

#include "user.h"
#include "wishList.h"
#include "order.h"
class buyer : virtual public user
{
public:
	
	buyer() = delete; //delete constructor- we don't allow default constructor of buyer
	buyer(char *user_name, char *password,const address_user & address); //constructor
	//not interested in copy constructor- we don't copy a buyer(person)
	virtual ~buyer(); //  destructor 

	// ------------------------functions of wish list's buyer-----------------//

	void addProductSellerToWishlist(Product * newProduct, sellers * newSeller); // add a new product and seller to a wish list array of specific buyer
	const wishList **reallocWishList(wishList **oldWishListArr, int size); // using this function in "addProductSellerToWishlist" for increasing the wish list array 
	
	void showWishList() const;
	wishList **getWishListArr() const;

	int getCountProductInWishList() const;
	void addOneToWishListArr(); // using this function to update the current size of wish list array after adding a wish list object to wish list array 
	void deleteProductFromBuyerWishList(int OrderIndex); // using function to update wish list array after payment (option 7 in interactive shell)

	// --------------------------functions of orders's buyer-----------------//
	
	void addOrderToOrdersArr(order *newOrder) ; // add a new order to a order array of specific buyer
	const order **reallocOrdersArr(order **oldOrdersArr, int size); // using this function in "addOrderToOrdersArr" for increasing the orders array
	
	void showBuyerorderByIndex(int index) const;//shows a specific order for a specific buyer
	void showAllSellersInBuyerorder() const ; // show all the sellers that the buyer has bought from
	order **getOrdersArr() const;
	int getCountOrders() const;

	void addOneToCountOrders();// increase by one count orders per buyer
	bool checkIfSellerExistsInAllOrders(const sellers *seller); // this function prevents duplicate sellers in the sellers array of orders,if the buyer bought more then once from a seller
	
protected:
//-----------------------attributes----------------------//

	wishList **WishListArr; // pointers array to wish list objects
	int CountProductInWishList;// index counts product in wish list per buyer (not a static variable)
	
	order **ordersArr; // pointers array to order objects- represent the history transactions
	int CountOrders; // index counts orders in order array per buyer (not a static variable)

};
#endif

