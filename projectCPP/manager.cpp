#include "manager.h"


void run() // function run on using system
{
	trade_system system;
	init_system_name(system); // call set system name function
	int input;
	do // run over the user actions until he choose to exit
	{
		printMenu();
		input = getAction();
		doAction(input, &system);
	} while (input != EXIT);
}

void init_system_name(trade_system &system) //function to initialize the system name
{
	char system_name[MAX_NAME_SIZE] = { 0 };
	cout << "Hello, enter your desire system name which contains maximum: " << (MAX_NAME_SIZE) << " characters please: " << endl;

	cin.getline(system_name, MAX_NAME_SIZE - 1); // cin name without a limited name size
	system.setName(system_name);
}

void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}

void printMenu() // function prints the menu system for the user
{
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
}

int getAction() // function give indicate which action the user is about to choose
{
	int input;
	cin >> input; // the input is in the buffer from the printManu function
	while (!((input <= 11) && (input >= 1))) //check input (action) validation
	{
		cout << "Please choose one of the fllowing action:" << endl;
		printMenu();
		cin >> input;
	}
	if ((input <= 10) && (input >= 1))
		return input;
	else if (input == 11) //input exit system
		return EXIT;
}


void doAction(int num, trade_system *system) // function do the wanted action 
{

	if (num == 1)//if the user wants to add a buyer
	{
		char name[MAX_NAME_SIZE] = { 0 };
		char password[MAX_PASSWORD_SIZE] = { 0 };
		char country[MAX_NAME_SIZE] = { 0 };
		char city[MAX_NAME_SIZE] = { 0 };
		char street[MAX_NAME_SIZE] = { 0 };
		int house_number;

		cout << "Please note that the system receives at most 20 charters" << endl;
		cout << "please enter new user name:" << endl;
		cleanBuffer();
		cin.getline(name, MAX_NAME_SIZE);

		cout << "please enter new user password:" << endl;
		cin.getline(password, MAX_PASSWORD_SIZE);

		cout << "please enter new user country:" << endl;
		cin.getline(country, MAX_NAME_SIZE);

		cout << "please enter new user city:" << endl;
		cin.getline(city, MAX_NAME_SIZE);

		cout << "please enter new user street:" << endl;
		cin.getline(street, MAX_NAME_SIZE);

		cout << "please enter house number:" << endl;
		cin >> house_number;

		address_user *address = new address_user(country, city, street, house_number);
		buyers *buyer = new buyers(name, password, *address);
		
		while (!(system->addBuyer(*buyer)))
		{
			cout << "the user name you entered is in use, please type a new name" << endl;
			cleanBuffer();
			cin.getline(name, MAX_NAME_SIZE);
			while (!buyer->setName(name))
			{
				cout << "the user name you entered is not valid, please type a new name" << endl;
				cin.getline(name, MAX_NAME_SIZE);
			}
			cout << "your user name changed successfully" << endl;
		}
		return;
	}


	if (num == 2) //if the user wants to add a seller
	{
		char name[MAX_NAME_SIZE] = { 0 };
		char password[MAX_PASSWORD_SIZE] = { 0 };
		char country[MAX_NAME_SIZE] = { 0 };
		char city[MAX_NAME_SIZE] = { 0 };
		char street[MAX_NAME_SIZE] = { 0 };
		int house_number;

		cout << "Please note that the system receives at most 20 charters" << endl;
		cout << "please enter new user name:" << endl;
		cleanBuffer();
		cin.getline(name, MAX_NAME_SIZE);

		cout << "please enter new user password:" << endl;
		cin.getline(password, MAX_PASSWORD_SIZE);

		cout << "please enter new user country:" << endl;
		cin.getline(country, MAX_NAME_SIZE);

		cout << "please enter new user city:" << endl;
		cin.getline(city, MAX_NAME_SIZE);

		cout << "please enter new user street:" << endl;
		cin.getline(street, MAX_NAME_SIZE);

		cout << "please enter house number:" << endl;
		cin >> house_number;

		address_user *address = new address_user(country, city, street, house_number);
		sellers *seller = new sellers(name, password, *address);
		while (!(system->addSeller(*seller)))
		{
			cout << "the user name you entered is in use, please type a new name" << endl;
			cleanBuffer();
			cin.getline(name, MAX_NAME_SIZE);
			while (!seller->setName(name))
			{
				cout << "the user name you entered is not valid, please type a new name " << endl;
				cin.getline(name, MAX_NAME_SIZE);
			}
			cout << "your user name changed successfully" << endl;
		}
		return;
	}
	if (num == 3)
	{
		cout << "Please note that the system receives at most 20 charters" << endl;
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
		Product *newProduct = new Product(productName, (Product::eCategory)categoryIndex, price);
		char userName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter your user name:" << endl;
		cleanBuffer();
		cin.getline(userName, MAX_NAME_SIZE);
		if (system->getCountSeller() == 0)
			cout << "there is no seller yet in our system" << endl;
		bool sellerNotFound=true;
		int indexSellersArr;
		bool flag=false; //indicate the adding product did not succeed - cause the seller name do not exist in our system
		for (indexSellersArr = 0; sellerNotFound &&indexSellersArr < system->getCountSeller(); indexSellersArr++)
		{
			if (strcmp(userName, system->getSellersArr()[indexSellersArr]->getName()) == 0)
			{
				system->getSellersArr()[indexSellersArr]->addProduct(*newProduct);
				flag = true;
				sellerNotFound = false;
			}
		}
		if(flag ==false)
			cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
		return;
	}

	if (num == 4)
	{
		char buyerName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter your user name:" << endl;
		int day, month, year;
		cleanBuffer();
		cin.getline(buyerName, MAX_NAME_SIZE);
		bool flag = false;
		char feedbackString[MAX_FEEDBACK_SIZE] = { 0 };
		date feedbackDate;
		bool BuyerNotFound = true;
		int indexBuyersArr;
		int orderIndex, numberOfOrdersPerBuyer, numberOfSellersPerOrder ,orderChoosen,sellerChoosen;
		for (indexBuyersArr = 0; BuyerNotFound && indexBuyersArr < system->getCountBuyer(); indexBuyersArr++)
		{
			if (strcmp(buyerName, system->getBuyersArr()[indexBuyersArr]->getName()) == 0)
			{
				BuyerNotFound = false;
				flag = true;
				numberOfOrdersPerBuyer = system->getBuyersArr()[indexBuyersArr]->getCountOrders();
				cout << "this is all of the sellers you bought from by the orders you have made:" << endl; 
				for (orderIndex = 0; orderIndex < numberOfOrdersPerBuyer; orderIndex++) 
				{
					cout << "order number:" << orderIndex + 1 << endl;
					system->getBuyersArr()[indexBuyersArr]->getOrdersArr()[orderIndex]->showSellersByCurrOrder();
				}
				cout << "to which one of them would you like to give feedback ? "<< endl; 
				cout << " enter the order number: and then the seller number" << endl;
				cin >> orderChoosen;
				while (!(orderChoosen <= numberOfOrdersPerBuyer))// check the order exists in orders arr for this buyer
				{
					cout << "the order number you entered is not exists, please enter a valid order number:" << endl;
					cin >> orderChoosen;//-1
				}
				cout << " enter the seller number: " << endl;
				cin >> sellerChoosen;
				numberOfSellersPerOrder = system->getBuyersArr()[indexBuyersArr]->getOrdersArr()[orderChoosen-1]->getCountSellersInSellersArr();
				while (!(sellerChoosen <= numberOfSellersPerOrder))//check seller exists in the order the user choose
				{
					cout << "the seller number you entered is not exists, please enter a valid seller number:" << endl;
					cin >> sellerChoosen;//-1
				}
				cout << "please enter your feedback for this seller: " << endl;
				cleanBuffer();
				cin.getline(feedbackString, MAX_FEEDBACK_SIZE);
				do
				{
					cout << "please enter a valid date: " << endl;
				} while (!initializeDate(feedbackDate, day, month, year));
				Feedback newFeedback(feedbackDate, system->getBuyersArr()[indexBuyersArr], feedbackString);
				system->getSellersArr()[sellerChoosen-1]->addFeedback(newFeedback);
			}
		}
		if (flag == false)
			cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
		return;
	}
	if (num == 5)
	{
		char buyerName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter your user name:" << endl;
		cleanBuffer();
		cin.getline(buyerName, MAX_NAME_SIZE);
		char productName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter which product you are looking for :" << endl;
		cin.getline(productName, MAX_NAME_SIZE);
		system->showProductWithIdenticalName(productName);
		char ch;
		int sellerIndex, productIndex, wishListIndex;
		Product *tempProduct;
		sellers *tempSellers;
		cout << "please enter the ProductNumber (as it written in screen) you wish to add to your wishlist:" << endl;
		cin >> sellerIndex >> ch >> productIndex;
		bool BuyerNotFound = true;
		int flag = false; 
		int indexBuyersArr;
		for (indexBuyersArr= 0; BuyerNotFound && indexBuyersArr < system->getCountBuyer(); indexBuyersArr++)
		{
			if (strcmp(buyerName, system->getBuyersArr()[indexBuyersArr]->getName()) == 0)
			{
				tempProduct = system->getSellersArr()[sellerIndex]->getProductArr()[productIndex];
				system->getBuyersArr()[indexBuyersArr]->addProductToWishlist(tempProduct);
				wishListIndex=system->getBuyersArr()[indexBuyersArr]->getCountProductInWishList();
				tempSellers = system->getSellersArr()[sellerIndex];
				system->getBuyersArr()[indexBuyersArr]->getWishListArr()[wishListIndex]->setSeller(tempSellers);
				flag = true;
				BuyerNotFound = false;
				system->getBuyersArr()[indexBuyersArr]->setCountProductInWishList(wishListIndex + 1);
			}
		}
		if (flag == false)
			cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
		return;
	}
	if (num == 6)
	{
		char buyerName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter your user name:" << endl;
		cleanBuffer();
		cin.getline(buyerName, MAX_NAME_SIZE);
		int flag = false;
		Product *tempProduct;//we will save a temporary product that we will insert to the products arr in a specific order
		sellers *tempSeller;//we will save a temporary seller that we will insert to the sellers arr in a specific order
		order *newOrder= new order;
		double countTotalPrice=0;
		double productPrice = 0;
		int choosenItems; 
		bool BuyerNotFound = true;
		int indexBuyersArr;
		int theLatestOrderForASpacificBuyer;//index the last order the buyer made
		for (indexBuyersArr = 0; BuyerNotFound && indexBuyersArr < system->getCountBuyer(); indexBuyersArr++)
		{			
			if (!strcmp(buyerName, system->getBuyersArr()[indexBuyersArr]->getName()) )
			{
				theLatestOrderForASpacificBuyer = system->getBuyersArr()[indexBuyersArr]->getCountOrders() - 1;//index the last order the buyer made
				if (theLatestOrderForASpacificBuyer==-1 || system->getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getOrderPayed())
				{// the check for theLatestOrderForASpacificBuyer to be -1 is for the first order the buyer will make 
					system->getBuyersArr()[indexBuyersArr]->showWishList();
					cout << "which product from your wish list would you like to buy? enter their numbers" << endl;
					cout << "when you finished please enter -1 " << endl;
					cin >> choosenItems;
					while (choosenItems != -1 && choosenItems <= system->getBuyersArr()[indexBuyersArr]->getCountProductInWishList())
					{
						tempProduct = system->getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct();//
						newOrder->addProductToProductArr(*tempProduct);//adding product to the current order product array
						productPrice = system->getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct()->getPrice();
						countTotalPrice = countTotalPrice + productPrice;
						tempSeller = system->getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getseller();
						if (system->getBuyersArr()[indexBuyersArr]->checkIfSellerExistsInAllOrders(tempSeller))//return true if the seller not exists in the buyer order
							newOrder->addSellerToSellersArr(*tempSeller);
						//otherwise, the seller is already exists in the buyer order
						cin >> choosenItems;
					}
					if (newOrder->getCountProductInProductArr() > 0)
					{//we want to update the order array for this buyer only if he did choose product for this order
						system->getBuyersArr()[indexBuyersArr]->addOrderToOrdersArr(newOrder, countTotalPrice);// adding a new order for the current buyer
						system->getBuyersArr()[indexBuyersArr]->addOneToCountOrders();
					}
					else
						cout << "you didn't add any product to the order" << endl;
				}
				else
				{
					cout << "please enter 7 in the interactive shell for paying on your last order, then you can make a new order as you wish :)" << endl;
					return;
				}
			flag = true;
			BuyerNotFound = false;
			}
		}
		if (flag == false)
			cout << "the user name you typed is not exist in our system, please type a new name or create a new user"  << endl;
		return;
	}
	if (num == 7)
	{
		char buyerName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter your user name:" << endl;
		cleanBuffer();
		cin.getline(buyerName, MAX_NAME_SIZE);
		int flag = false;
		int indexBuyersArr;
		int theLatestOrderForASpacificBuyer;
		double totalPriceForASpaCificOrder;
		bool approvepurchase;
		bool BuyerNotFound = true;
		for (indexBuyersArr = 0; BuyerNotFound && indexBuyersArr < system->getCountBuyer(); indexBuyersArr++)
		{
			if (!strcmp(buyerName, system->getBuyersArr()[indexBuyersArr]->getName()))
			{
				theLatestOrderForASpacificBuyer =system->getBuyersArr()[indexBuyersArr]->getCountOrders()-1;
				cout << "the items below are the last order you made: " << endl;
				system->getBuyersArr()[indexBuyersArr]->showBuyerorderByIndex(theLatestOrderForASpacificBuyer);
				totalPriceForASpaCificOrder = system->getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getTotalPrice();
				cout<<"the total price is:"<< totalPriceForASpaCificOrder << endl;
				cout << "press 1 to make the approve the purchase " << endl;
				cin >> approvepurchase;
				if (approvepurchase)
				{
					system->getBuyersArr()[indexBuyersArr]->deleteProductFromBuyerWishList(theLatestOrderForASpacificBuyer);//print the recipe and clean the cart
					system->getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->setOrderPayedTrue();
					cout << "purchase has done successfully " << endl;
				}
				else
					cout << "purchase canceled " << endl;
				BuyerNotFound = false;
				flag = true;
			}
		}
		if (flag == false)
			cout << "the user name you typed is not exist in our system, please type a new name or create a new user" << endl;
		return;
	}
	if (num == 8)
	{
		for (int i = 0; i < system->getCountBuyer(); i++)
		{
			cout << "This is Buyer " << i+1 << " of our system: " << endl;
			system->getBuyersArr()[i]->showBuyerBasicDeatelis();
			if (system->getBuyersArr()[i]->getWishListArr() != nullptr)
			{
				cout << "This are Products in his current wish list: " << endl;
				for (int j = 0; j < system->getBuyersArr()[i]->getCountProductInWishList(); j++)
					system->getBuyersArr()[i]->getWishListArr()[j]->getProduct()->show();
				cout << system->getBuyersArr()[i]->getName() << " has " << system->getBuyersArr()[i]->getCountProductInWishList() << " items in his wish list" << endl;
			}
			else
				cout << "the buyer wish list is Empty" << endl;
			if (system->getBuyersArr()[i]->getCountOrders() > 0)
			{
				for (int j = 0; j < system->getBuyersArr()[i]->getCountOrders(); j++)
				{//'j' is the index for the orders array
					cout << "This is the " << j+1 << " order in his orders history" << endl;
					for (int k = 0; k < system->getBuyersArr()[i]->getOrdersArr()[j]->getCountProductInProductArr(); k++)//'k' is the index of the product in the current order
						system->getBuyersArr()[i]->getOrdersArr()[j]->getProductArr()[k]->show();
				}
			}
			else
				cout << "the buyer orders history is Empty" << endl;	
			cout << "-----------------------------------------------" << endl;
		}
		return;
	}
	if (num == 9)
	{//missing show() for feedback for the specific seller
		for (int i = 0; i < system->getCountSeller(); i++)
		{
			cout << "This is Seller " << i+1 << " of our system: " << endl;
			system->getSellersArr()[i]->showSellerBasicDeatelis();
						
			if (system->getSellersArr()[i]->getProductArr() != nullptr)
			{
				cout << "This is his current Products list: " << endl;
				for (int j = 0; j < system->getSellersArr()[i]->getCountProduct(); j++)
				{
					system->getSellersArr()[i]->getProductArr()[j]->show();
				}
			}
			else
				cout << "the seller Products list is Empty" << endl;
			cout << "-----------------------------------------------" << endl;
		}
		return;
	}
	if (num == 10)
	{
		char productName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter which product you are looking for :" << endl;
		cleanBuffer();
		cin.getline(productName, MAX_NAME_SIZE);

		system->showProductWithIdenticalName(productName);
		return;
	}
	if (num == 11)
	{
		cout << "logging out..... Goodbye :)" << endl;
		return;
	}
	
}

bool initializeDate(date & feedbackDate, int &day,int& month,int &year)
{
	
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