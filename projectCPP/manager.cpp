#include "manager.h"

manager::manager() {}
manager::~manager() {} //destructor

void manager::run() // function run on using system
{
	init_system_name();
	int input;
	do // run over the user actions until he choose to exit
	{
		printMenu();
		input = getAction();
		doAction(&input);
	} while (input != EXIT);
	
}

void manager::init_system_name() //function to initialize the system name
{
	char system_name[MAX_NAME_SIZE] = { 0 };
	cout << "Hello, enter the name you would like to call to the system which contains maximum: " << (MAX_NAME_SIZE) << " characters please: " << endl;

	cin.getline(system_name, MAX_NAME_SIZE - 1); // cin name without a limited name size
	this->system.setName(system_name);
}

void manager::cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void manager::printMenu() //this function prints the menu system for the user
{
	cout << "--------------------------------------------------------------" << endl;
	cout << "Welcome, please let us know which action you would like to do:" << endl;
	cout << "For adding a buyer press 1" << endl;
	cout << "For adding a seller press 2" << endl;
	cout << "For adding an item for a seller press 3" << endl;
	cout << "For adding a feedback to a seller press 4" << endl;
	cout << "For adding an item to a buyer shopping cart press 5" << endl;
	cout << "To make an order to a buyer press 6" << endl;
	cout << "To pay for an order of a buyer press 7" << endl;
	cout << "To print all buyers details press 8" << endl;
	cout << "To print all sellers details press 9" << endl;
	cout << "To print all  identical name items press 10" << endl;
	cout << "To exit press 11" << endl;
	cout << "--------------------------------------------------------------" << endl;

}

int manager::getAction() // function give indicate which action the user is about to choose
{
	int input;
	cin >> input; // the input is in the buffer from the printManu function
	while (!((input <= 11) && (input >= 1))) //check input (action) validation
	{
		cout << "Please choose one of the fllowing action:" << endl;
		printMenu();
	
		cin >> input;// הכנסתי סתם אותיות והייתה בעיה, אנסה לפתור..
	}
	if ((input <= 10) && (input >= 1))
		return input;
	else if (input == 11) //input exit system
		return EXIT;
}
bool manager::userLogOut()
{
	bool choose;
	cout << "for log out of our system press 1 \n to take another action in the interactive shell press 0" << endl;
	cin >> choose;
	return choose;
}

void manager::doAction(int *num) // function do the wanted action 
{
	if (*num == 1)//if the user wants to add a buyer
	{
		addBuyerToTradeSystem();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 2) //if the user wants to add a seller
	{
		addSellerToTradeSystem();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 3)
	{
		addProductToSeller();
		if (userLogOut())
			*num = EXIT;
		else
			return; 
	}
	if (*num == 4)
	{
		addFeedbackToASeller();
		
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 5)
	{
		addToWishlist();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 6)
	{
		addOrderToBuyer();
		
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 7)
	{
		payment();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 8)
	{
		printBuyers();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 9)
	{//missing show() for feedback for the specific seller
		
		printSellers();
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 10)
	{
		printProductsByName();
		
		if (userLogOut())
			*num = EXIT;
		else
			return;
	}
	if (*num == 11)
	{
		cout << "logging out..... Goodbye :)" << endl;
		cin.get();// pause the console
		
	}

}

//----------------------------------related to option 1&2 -add new buyer\seller---------------// 

void manager::addBuyerToTradeSystem()
{
	buyers *buyer = createBuyer();
	while (!(system.addBuyer(*buyer)))
	{//we wont to make sure the buyer didn't enter a user name that is already in use
		cout << "the user name you entered is in use, please type a new name" << endl;
		cleanBuffer();// we will ask from him to change it to a new available name
		cin.getline(buyer->getName(), MAX_NAME_SIZE);
		while (!buyer->setName(buyer->getName()))
		{
			cout << "the user name you entered is not valid, please type a new name" << endl;
			cin.getline(buyer->getName(), MAX_NAME_SIZE);//receive a new user name from the user
		}
		cout << "your user name changed successfully" << endl;
	}
}

buyers* manager::createBuyer()
{
	char name[MAX_NAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };

	cout << "Please note that the system receives at most 20 charters" << endl;
	cout << "please enter new user name:" << endl;
	cleanBuffer();
	cin.getline(name, MAX_NAME_SIZE);

	cout << "please enter new user password:" << endl;
	cin.getline(password, MAX_PASSWORD_SIZE);

	address_user *address = createAddress();
	return new buyers(name, password, *address);

}

address_user* manager::createAddress()
{
	char country[MAX_NAME_SIZE] = { 0 };
	char city[MAX_NAME_SIZE] = { 0 };
	char street[MAX_NAME_SIZE] = { 0 };
	int house_number;
	cout << "please enter new user country:" << endl;
	cin.getline(country, MAX_NAME_SIZE);

	cout << "please enter new user city:" << endl;
	cin.getline(city, MAX_NAME_SIZE);

	cout << "please enter new user street:" << endl;
	cin.getline(street, MAX_NAME_SIZE);

	cout << "please enter house number:" << endl;
	cin >> house_number;
	return new address_user(country, city, street, house_number);
}

void  manager::addSellerToTradeSystem()
{
	sellers *seller = createSeller();
	while (!(system.addSeller(*seller)))
	{
		cout << "the user name you entered is in use, please type a new name" << endl;
		cleanBuffer();
		cin.getline(seller->getName(), MAX_NAME_SIZE);
		while (!seller->setName(seller->getName()))
		{
			cout << "the user name you entered is not valid, please type a new name " << endl;
			cin.getline(seller->getName(), MAX_NAME_SIZE);
		}
		cout << "your user name changed successfully" << endl;
	}

}

sellers* manager::createSeller()
{
	char name[MAX_NAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	cout << "Please note that the system receives at most 20 charters" << endl;
	cout << "please enter new user name:" << endl;
	cleanBuffer();
	cin.getline(name, MAX_NAME_SIZE);

	cout << "please enter new user password:" << endl;
	cin.getline(password, MAX_PASSWORD_SIZE);

	address_user *address = createAddress();
	return new sellers(name, password, *address);
}

//----------------------------------related to option 3 -add new Product---------------// 

void manager::addProductToSeller()
{
	if (system.getCountSeller() == 0)
	{
		cout << "there is no seller yet in our system, please add seller first" << endl;
		return;
	}
	Product *newProduct = createProduct();
	int indexSellersArr = 0;
	if (findSellerInSystem(indexSellersArr))
		system.getSellersArr()[indexSellersArr]->addProduct(*newProduct);
	else
		cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;

	
}
Product* manager::createProduct()
{
	char productName[MAX_NAME_SIZE] = { 0 };
	cout << "please enter a name for the new product:" << endl;
	cleanBuffer();
	cin.getline(productName, MAX_NAME_SIZE);
	int categoryIndex;
	cout << "which category is the product:" <<
		"press 0 for Children product," <<
		"press 1 for Electronics product," <<
		"press 2 for Office product," <<
		"press 3 for Clothing product" << endl;
	cin >> categoryIndex;
	double price;
	cout << "please enter the price for the new product:" << endl;
	cin >> price;
	return new Product(productName, (Product::eCategory)categoryIndex, price);
}
bool manager::findSellerInSystem(int &indexSellersArr)
{
	char userName[MAX_NAME_SIZE] = { 0 };
	cout << "please enter your user name:" << endl;
	cleanBuffer();
	cin.getline(userName, MAX_NAME_SIZE);
	for (indexSellersArr = 0; indexSellersArr < system.getCountSeller(); indexSellersArr++)
	{
		if (strcmp(userName, system.getSellersArr()[indexSellersArr]->getName()) == 0)
			return true;
	}
	return false;
	
}

//----------------------------------related to option 4 -create a feedback---------------// 
void  manager::addFeedbackToASeller()
{
	int indexBuyersArr = 0;
	if (findBuyerInSystem(indexBuyersArr))
	{
		char *tempSeller = chooseSeller(indexBuyersArr);

		char feedbackString[MAX_FEEDBACK_SIZE] = { 0 };
		cout << "please enter your feedback for this seller: " << endl;
		cleanBuffer();
		cin.getline(feedbackString, MAX_FEEDBACK_SIZE);

		date feedbackDate;
		do
		{
			cout << "please enter a valid date: " << endl;
		} while (!initializeDate(feedbackDate));
		
		Feedback newFeedback(feedbackDate, system.getBuyersArr()[indexBuyersArr], feedbackString);
		insertFeedbackToSellerInSystem(tempSeller, newFeedback);
	}
	else
		cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

bool manager::findBuyerInSystem(int &indexBuyerArr)
{
	char userName[MAX_NAME_SIZE] = { 0 };
	cout << "please enter your user name:" << endl;
	cleanBuffer();
	cin.getline(userName, MAX_NAME_SIZE);
	for (indexBuyerArr = 0;indexBuyerArr < system.getCountBuyer(); indexBuyerArr++)
	{
		if (strcmp(userName, system.getBuyersArr()[indexBuyerArr]->getName()) == 0)
			return true;
	}
	return false;
}

char * manager::chooseSeller(int & indexBuyersArr)
{
	int  numberOfOrdersPerBuyer, numberOfSellersPerOrder, orderChoosen, sellerChoosen;
	if (findBuyerInSystem(indexBuyersArr))
	{
		system.getBuyersArr()[indexBuyersArr]->showAllSellersInBuyerorder();
		numberOfOrdersPerBuyer = system.getBuyersArr()[indexBuyersArr]->getCountOrders();
		cout << "to which one of them would you like to give feedback ? " << endl;
		cout << "enter the order number:" << endl;
		cin >> orderChoosen;
		while (!(orderChoosen <= numberOfOrdersPerBuyer))// check the order exists in orders arr for this buyer
		{
			cout << "the order number you entered is not exists, please enter a valid order number:" << endl;
			cin >> orderChoosen;
		}
		cout << "enter the seller number: " << endl;
		cin >> sellerChoosen;
		numberOfSellersPerOrder = system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[orderChoosen - 1]->getCountSellersInSellersArr();
		while (!(sellerChoosen <= numberOfSellersPerOrder))//check seller exists in the order the user choose
		{
			cout << "the seller number you entered is not exists, please enter a valid seller number:" << endl;
			cin >> sellerChoosen;
		}
	}
	return system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[orderChoosen - 1]->getsellersArr()[sellerChoosen - 1]->getName();
}

bool manager::initializeDate(date & feedbackDate)// use in option 4
{
	int day, month, year;
	cout << "please enter the day number:" << endl;
	cin >> day;
	cout << "please enter the month number:" << endl;
	cin >> month;
	cout << "please enter the year number:" << endl;
	cin >> year;
	if (!feedbackDate.setDay(day))
	{
		cout << "the day number isn't valid" << endl;
		return false;
	}
	if (!feedbackDate.setMonth(month))
	{
		cout << "the month number isn't valid" << endl;
		return false;
	}
	if (!feedbackDate.setYear(year))
	{
		cout << "the year number isn't valid" << endl;
		return false;
	}
	return true;
}

void manager::insertFeedbackToSellerInSystem(char *tempSeller, Feedback &newFeedback)
{
	bool sellerNotFound = true;
	for (int i = 0; sellerNotFound && i < system.getCountSeller(); i++)
	{
		if (!strcmp(system.getSellersArr()[i]->getName(), tempSeller))
		{
			system.getSellersArr()[i]->addFeedback(newFeedback);
			sellerNotFound = false;
		}
	}
}

//----------------------------------related to option 5 -create a wish list---------------// 
void manager::addToWishlist()
{
	int indexBuyersArr = 0;
	if (findBuyerInSystem(indexBuyersArr))
	{
		
		char ch;
		int sellerIndex, productIndex;
		Product *tempProduct;
		sellers *tempSellers;
		printProductsByName();

		cout << "please enter the Product number you wish to add to your wish list: \n(as it written in screen on the first line) " << endl;
		
		cin >> sellerIndex >> ch >> productIndex;

		tempProduct = system.getSellersArr()[sellerIndex]->getProductArr()[productIndex];
		tempSellers = system.getSellersArr()[sellerIndex];
		system.getBuyersArr()[indexBuyersArr]->addProductToWishlist(tempProduct, tempSellers);
		system.getBuyersArr()[indexBuyersArr]->addOneToWishListArr();
	}
	else
		cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

//----------------------------------related to option 6 -add order------------------------// 


void manager::addOrderToBuyer()
{
	int indexBuyersArr = 0;
	int theLatestOrderForASpacificBuyer;//index the last order the buyer made
	if (findBuyerInSystem(indexBuyersArr))
	{
		theLatestOrderForASpacificBuyer = system.getBuyersArr()[indexBuyersArr]->getCountOrders() - 1;//index the last order the buyer made
		if (theLatestOrderForASpacificBuyer == -1 || system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getOrderPayed())
		{// the check for theLatestOrderForASpacificBuyer to be -1 is for the first order the buyer will make 
			order *newOrder = createNewOrder(indexBuyersArr);
			if (newOrder->getCountProductInProductArr() > 0)
			{//we want to update the order array for this buyer only if he did choose product for this order
				system.getBuyersArr()[indexBuyersArr]->addOrderToOrdersArr(newOrder);// adding a new order for the current buyer
				system.getBuyersArr()[indexBuyersArr]->addOneToCountOrders();
			}
			else
				cout << "you didn't add any product to the order" << endl;
			delete newOrder;
		}
		else
		{
			cout << "please enter 7 in the interactive shell for paying on your last order, then you can make a new order as you wish :)" << endl;
			return;
		}
	}
	else
		cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

order* manager::createNewOrder(int &indexBuyersArr)
{
	Product *tempProduct;//we will save a temporary product that we will insert to the products arr in a specific order
	sellers *tempSeller;//we will save a temporary seller that we will insert to the sellers arr in a specific order
	double productPrice = 0;
	int choosenItems;
	
	system.getBuyersArr()[indexBuyersArr]->showWishList();
	cout << "which product from your wish list would you like to buy? enter their numbers" << endl;
	cout << "when you finished please enter -1 " << endl;
	cin >> choosenItems;
	order *newOrder = new order;
	
	while (choosenItems != -1)
	{
		tempProduct = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct();//
		newOrder->addProductToProductArr(*tempProduct);//adding product to the current order product array
		productPrice = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct()->getPrice();
		newOrder->setTotalPrice(productPrice);
		tempSeller = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getseller();
		if (!system.getBuyersArr()[indexBuyersArr]->checkIfSellerExistsInAllOrders(tempSeller))//return true if the seller not exists in the buyer order
			newOrder->addSellerToSellersArr(*tempSeller);
		//otherwise, the seller is already exists in the buyer order
		cin >> choosenItems;
	}
	return newOrder;
}

//----------------------------------related to option 7 payment---------------// 

void manager::payment()
{
int indexBuyersArr = 0;
bool approvepurchase;

	if (findBuyerInSystem(indexBuyersArr))
	{
		int theLatestOrderForASpacificBuyer = system.getBuyersArr()[indexBuyersArr]->getCountOrders() - 1;
		cout << "the items below are the last order you made: " << endl;
		system.getBuyersArr()[indexBuyersArr]->showBuyerorderByIndex(theLatestOrderForASpacificBuyer);
		double totalPriceForASpaCificOrder = system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getTotalPrice();
		cout << "the total price is: " << totalPriceForASpaCificOrder << "press 1 to make the approve the purchase"<< endl;
	
		cin >> approvepurchase;
		if (approvepurchase)
		{
			system.getBuyersArr()[indexBuyersArr]->deleteProductFromBuyerWishList(theLatestOrderForASpacificBuyer);//print the recipe and clean the cart
			system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->setOrderPayedTrue();
			cout << "purchase has done successfully " << endl;
		}
		else
			cout << "purchase canceled " << endl;
	}
	else
		cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

//----------------------------------related to option 8 print buyers---------------// 

void manager::printBuyers()
{
	for (int i = 0; i < system.getCountBuyer(); i++)
	{
		cout << "This is Buyer " << i + 1 << " of our system: " << endl;
		system.getBuyersArr()[i]->showBuyerBasicDeatelis();
		if (system.getBuyersArr()[i]->getWishListArr() != nullptr)
		{
			cout << "This are Products in his current wish list: " << endl;
			for (int j = 0; j < system.getBuyersArr()[i]->getCountProductInWishList(); j++)
				system.getBuyersArr()[i]->getWishListArr()[j]->getProduct()->show();
			cout << system.getBuyersArr()[i]->getName() << " has " << system.getBuyersArr()[i]->getCountProductInWishList() << " items in his wish list" << endl;
		}
		else
			cout << "the buyer wish list is Empty" << endl;
		if (system.getBuyersArr()[i]->getCountOrders() > 0)
		{
			for (int j = 0; j < system.getBuyersArr()[i]->getCountOrders(); j++)
			{//'j' is the index for the orders array
				cout << "This is the " << j + 1 << " order in his orders history" << endl;
				for (int k = 0; k < system.getBuyersArr()[i]->getOrdersArr()[j]->getCountProductInProductArr(); k++)//'k' is the index of the product in the current order
					system.getBuyersArr()[i]->getOrdersArr()[j]->getProductArr()[k]->show();
			}
		}
		else
			cout << "the buyer orders history is Empty" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

//----------------------------------related to option 9 print sellers---------------// 
void manager::printSellers()
{
	for (int i = 0; i < system.getCountSeller(); i++)
	{
		cout << "This is Seller " << i + 1 << " of our system: " << endl;
		system.getSellersArr()[i]->showSellerBasicDeatelis();

		if (system.getSellersArr()[i]->getProductArr() != nullptr)
		{
			cout << "This is his current Products list: " << endl;
			for (int j = 0; j < system.getSellersArr()[i]->getCountProduct(); j++)
			{
				system.getSellersArr()[i]->getProductArr()[j]->show();
			}
		}
		else
			cout << "the seller Products list is Empty" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

//----------------------------------related to option 10 (and 5) - print products---------------// 

void manager::printProductsByName()
{
	char productName[MAX_NAME_SIZE] = { 0 };
	cout << "please enter which product you are looking for :" << endl;
	cin.getline(productName, MAX_NAME_SIZE);
	system.showProductWithIdenticalName(productName);
	
}