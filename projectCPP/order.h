#ifndef  __ORDER_H
#define __ORDER_H

#include "sellers.h" // sellers include product

class order
{
public:

	order(double totalPrice=0); // defualt constructor
	order(const order & myOrder); // copy constructor
	~order(); // destructor

//----------------------set & get functions------------------------------//
	Product** getProductArr()  const;
	sellers ** getsellersArr() const;

	int getCountProductInProductArr() const; 
	int getCountSellersInSellersArr() const; 
	bool getOrderPayed()  const;
	double getTotalPrice() const;

	void setCountProductInProductArr(int n); 
	void setCountSellersInSellersArr(int n); 
	void setOrderPayedTrue();
	void setTotalPrice(double n); 

//----------------------adding order to buyer functions------------------------------//
	void addProductToProductArr(Product &newProduct); // function adds product to products array's buyer
	Product ** reallocProductArr(Product **oldProductArr, int size); // function increase products array by one, for a new order, to add to the order array's buyer 

	void addSellerToSellersArr(sellers &newSeller);// function adds seller to sellers array's buyer
	sellers ** reallocsellersArr(sellers **oldsellersArr, int size); // function increase sellers array by one, for a new seller, to add to the order array's buyer 
	
	void showSellersByCurrOrder() const; // function shows sellers in specific order
	bool checkIfSellerExists(const sellers *seller); // function checks that seller is adding only one time to sellers array of order to prevent duplicates

private:
//----------------------------attributes----------------------------//
	double totalPrice;
	Product** productArr;
	sellers **sellersArr;
	bool orderPayed; // indicate if specific order has payed
	int CountProductInProductArr = 0; // index counts product in oreder per buyer (not a static variable)
	int CountSellersInSellersArr = 0; // index counts seller in oreder per buyer (not a static variable)
};
#endif 