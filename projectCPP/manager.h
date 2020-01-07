#ifndef __MANAGER_H
#define __MANAGER_H
#pragma warning (disable: 4996) 

#include "trade_system.h"

#define EXIT 13 //define the input of exiting interactive shell
class manager // class Intended to contact with the user of the system which gives commands to the system manager 
{
public:
	manager(); // default constructor
	~manager(); // destructor

	void run(); // function run on using system
	void printMenu(); // function prints the menu system for the user
	void init_system_name(); //function to initialize the system name by having input from user who is the manager's system
	int getAction(); // function give indicate which action the user is about to choose
	void doAction(int *num); // function do the demanded action 
	bool userLogOut(); // function indicate if the user wants to log out of system
	void cleanBuffer();

	//----------------------------------related to option 1&2 -add new buyer\seller---------------// 
	buyers* createBuyer();
	user* createUser(int num);
	address_user* createAddress();
	buyerAndSeller *createBuyerSeller();
	void addUserToTradeSystem();// function adds user to users array in attributes of trade system
	
	//----------------------------------related to option 3 -add new Product---------------// 
	Product* createProduct();
	void addProductToSeller(); //function adds product to products array's seller
	bool findSellerInSystem(int & indexSellersArr);
	
	//----------------------------------related to option 4 -create a feedback---------------// 
	bool findBuyerInSystem(int &indexBuyerArr); // function finds in system the buyer who wants to give a feedback
	sellers *chooseSeller(int & indexBuyersArr); // function gives the name of the seller who will receive feedback
	bool initializeDate(date & feedbackDate); // date of given feedback
	void addFeedbackToASeller();
	//void insertFeedbackToSellerInSystem(char *tempSeller, Feedback &newFeedback); // function insert feedback to feedback array's seller
	
	//----------------------------------related to option 5 -create a wish list---------------// 
	void addToWishlist(); // function adds wish list object which contains product ans seller of the product to wish list array's buyer
	void checkValidIndex(int &sellerIndex, int& productIndex);
	//----------------------------------related to option 6 -add order---------------// 
	order* createNewOrder(int &indexBuyersArr);
	void checkValidChoosenItem(int & choosenItem, int countProductInWishList);
	void addOrderToBuyer(); // function adds order to orders array's buyer
	//----------------------------------related to option 7 payment---------------// 
	void payment(); // payment for last order he made

	//----------------------------------related to option 8 print buyers---------------// 
	void printBuyers();

	//----------------------------------related to option 9 print sellers---------------// 
	void printSellers();
	
	//----------------------------------related to option 10 (and 5) - print products---------------// 
	void printProductsByName();

private:
//----------------attributes: manager manage the trade system-----------------//
	trade_system system;
};
#endif