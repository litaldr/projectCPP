#ifndef __MANAGER_H
#define __MANAGER_H
#pragma warning (disable: 4996) 

#include "trade_system.h"
//#include "Product.h"

#define EXIT 11 //define the input of exiting program
class manager // class Intended to contact with the user of the system which gives commands to the system manager 
{
public:
	manager();
	~manager();
	void run(); // function run on using system
	void printMenu(); // function prints the menu system for the user
	void init_system_name(); //function to initialize the system name
	int getAction(); // function give indicate which action the user is about to choose
	void doAction(int *num); // function do the wanted action 
	bool userLogOut();
	void cleanBuffer();

	//----------------------------------related to option 1&2 -add new buyer\seller---------------// 

	void addBuyerToTradeSystem();
	address_user* createAddress();
	buyers* createBuyer();
	void addSellerToTradeSystem();
	sellers* createSeller();
	
	//----------------------------------related to option 3 -add new Product---------------// 
	void addProductToSeller();
	Product* createProduct();
	bool findSellerInSystem(int & indexSellersArr);
	
	//----------------------------------related to option 4 -create a feedback---------------// 
	void addFeedbackToASeller();
	
	char *chooseSeller(int & indexBuyersArr);
	
	bool initializeDate(date & feedbackDate);
	void insertFeedbackToSellerInSystem(char *tempSeller, Feedback &newFeedback);
	bool findBuyerInSystem(int &indexBuyerArr);
	
	//----------------------------------related to option 5 -create a wish list---------------// 
	void addToWishlist();
	
	//----------------------------------related to option 6 -add order---------------// 
	void addOrderToBuyer();
	order* createNewOrder(int &indexBuyersArr);

	//----------------------------------related to option 7 payment---------------// 
	void payment();

	//----------------------------------related to option 8 print buyers---------------// 
	void printBuyers();

	//----------------------------------related to option 9 print sellers---------------// 
	void printSellers();
	
	//----------------------------------related to option 10 (and 5) - print products---------------// 
	void printProductsByName();
private:
	trade_system system;
};
#endif