#include "manager.h"

manager::manager() {} //constructor
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

void manager::printMenu() // function prints the menu system for the user
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
		cout << "Please choose one of the following action:" << endl;
		printMenu();
	
		cin >> input;
	}
	if ((input <= 10) && (input >= 1))
		return input;
	else if (input == 11) //input exit system
		return EXIT;
}

bool manager::userLogOut() // function indicate if user wants to exit from  interactive shell
{
	bool choose;
	cout << "For log out of our system press 1 \n To take another action in the interactive shell press 0" << endl;
	cin >> choose;
	return choose;
}

void manager::doAction(int *num) // function do the wanted action 
{
	if (*num == 1)//if the user wants to add a buyer
	{
		addUserToTradeSystem();
		
		if (userLogOut())
			*num = EXIT;
		return;
	}
	
	if (*num == 4)
	{
		addProductToSeller();
		if (userLogOut())
			*num = EXIT;
		return; 
	}
	if (*num == 5)
	{
		addFeedbackToASeller();
		
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 6)
	{
		addToWishlist();
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 7)
	{
		addOrderToBuyer();
		
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 8)
	{
		payment();
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 9)
	{
		printBuyers();
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 10)
	{//missing show() for feedback for the specific seller- we decided it's not relevance
		
		printSellers();
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 11)
	{
		//print seller&buyer

		if (userLogOut())
			*num = EXIT;
		return;
	}

	if (*num == 12)
	{
		printProductsByName();
		
		if (userLogOut())
			*num = EXIT;
		return;
	}
	if (*num == 13)
	{
		cout << "Logging out..... Goodbye :)" << endl;
		cin.get();// pause the console
	}

}

//----------------------------------related to option 1&2 -add new buyer\seller---------------// 

address_user* manager::createAddress()
{
	char country[MAX_NAME_SIZE] = { 0 };
	char city[MAX_NAME_SIZE] = { 0 };
	char street[MAX_NAME_SIZE] = { 0 };
	int house_number;
	cout << "Please enter new user country:" << endl;
	cin.getline(country, MAX_NAME_SIZE);

	cout << "Please enter new user city:" << endl;
	cin.getline(city, MAX_NAME_SIZE);

	cout << "Please enter new user street:" << endl;
	cin.getline(street, MAX_NAME_SIZE);

	cout << "Please enter house number:" << endl;
	cin >> house_number;
	return new address_user(country, city, street, house_number);
}



void manager::addUserToTradeSystem()
{
	int type;
	cout << "type 1 to add buyer, type 2 to add seller, type 3 to add buyer which is also a seller:" << endl;
	cin >> type;
	user * newUser = createUser(type);
	while (!(system.addUser(*newUser)))
	{//we want to make sure the user didn't enter a user name that is already in use
		cout << "The user name you entered is in use, please type a new name" << endl;
		cleanBuffer();// we will ask from him to change it to a new available name
		cin.getline(newUser->getName(), MAX_NAME_SIZE);
		while (!newUser->setName(newUser->getName()))
		{
			cout << "The user name you entered is not valid, please type a new name" << endl;
			cin.getline(newUser->getName(), MAX_NAME_SIZE);//receive a new user name from the user
		}
		cout << "Your user name changed successfully" << endl;
	}
	switch (type)
	{
	case 1: system.setCountBuyers();
	case 2: system.setCountSellers();
	case 3: system.setCountBuyersSellers();

	default:
		break;
	}

}


user* manager::createUser(int num)
{
	char name[MAX_NAME_SIZE] = { 0 };
	char password[MAX_PASSWORD_SIZE] = { 0 };
	cout << "Please note that the system receives at most 20 charters" << endl;
	cout << "Please enter new user name:" << endl;
	cleanBuffer();
	cin.getline(name, MAX_NAME_SIZE);

	cout << "Please enter new user password:" << endl;
	cin.getline(password, MAX_PASSWORD_SIZE);

	address_user *address = createAddress();
	switch (num)
	{
	case 1:return new sellers(name, password, *address);
	case 2:return new buyers(name, password, *address);
	case 3:return new buyerAndSeller(name, password, *address);
	default: cout << "invalid option" << endl;
		break;
	}
}


//----------------------------------related to option 4 -add new Product---------------// 

Product* manager::createProduct()
{
	char productName[MAX_NAME_SIZE] = { 0 };
	cout << "Please enter a name for the new product:" << endl;
	cleanBuffer();
	cin.getline(productName, MAX_NAME_SIZE);
	int categoryIndex;
	cout << "Which category is the product:" <<
		"Press 0 for Children product," <<
		"Press 1 for Electronics product," <<
		"Press 2 for Office product," <<
		"Press 3 for Clothing product" << endl;
	cin >> categoryIndex;
	while(!(categoryIndex<4&& categoryIndex>=0))
	{
		cout << "Please enter a valid category number:" << endl;
		cin >> categoryIndex;
	}
	double price;
	cout << "Please enter the price for the new product:" << endl;
	cin >> price;
	return new Product(productName, (Product::eCategory)categoryIndex, price);
}

bool manager::findSellerInSystem(int &indexUsersArr)
{
	char userName[MAX_NAME_SIZE] = { 0 };
	cout << "Please enter your user name:" << endl;
	cleanBuffer();
	cin.getline(userName, MAX_NAME_SIZE);
	for (indexUsersArr = 0; indexUsersArr < system.getCountUsers(); indexUsersArr++)
	{
		buyerAndSeller *temp1 = dynamic_cast<buyerAndSeller*>(system.getUsersArr()[indexUsersArr]);
		sellers *temp2 = dynamic_cast<sellers*>(system.getUsersArr()[indexUsersArr]);
		//temp1 & temp2 indicate if the user is either a seller or a buyer which is also a seller
			if (temp1)
			{
				if (strcmp(userName,temp1->getName()) == 0) // indicate user is find
					return true;
			}
			else if (temp2)
			{
				if (strcmp(userName, temp2->getName()) == 0) // indicate user is find
					return true;
			}
	}
	return false;
}

void manager::addProductToSeller()
{
	if (system.getCountBuyersSellers() == 0 ||system.getCountSellers() == 0) // case trying to add product while there is no sellers in the system yet
	{
		cout << "There is no seller yet in our system, please add seller first" << endl;
		return;
	}
	Product *newProduct = createProduct();
	int indexUsersArr = 0;//the location of the user which is as seller or buyer and seller
	if (findSellerInSystem(indexUsersArr)) // "findSellerInSystem" function returns true when finding the seller\buyer and seller for adding him a new product to products array
		//the value indexUsersArr returns by reference, להוסיף דגל שאומר אם קונה או קונה מוכר
	{
		buyerAndSeller *temp1 = dynamic_cast<buyerAndSeller*>(system.getUsersArr()[indexUsersArr]);
		sellers *temp2 = dynamic_cast<sellers*>(system.getUsersArr()[indexUsersArr]);
		if (temp1)
			temp1->addProduct(*newProduct);
		if (temp2)
			temp2->addProduct(*newProduct);
	}
	else // case seller is not fount in system
		cout << "The user name you typed is not exist in our system" << endl;
}

//----------------------------------related to option 5 -create a feedback---------------// 

void  manager::addFeedbackToASeller()
{
	int indexUsersArr = 0;
	if (findBuyerInSystem(indexUsersArr)) // "findBuyerInSystem" function returns true when finding the buyer who demanded to write the feedback
	{
		char *tempSeller = chooseSeller(indexUsersArr); // "chooseSeller" function returns seller name to give for the feedback

		// enter feedback
		char feedbackString[MAX_FEEDBACK_SIZE] = { 0 };
		cout << "Please enter your feedback for this seller: " << endl;
		cleanBuffer();
		cin.getline(feedbackString, MAX_FEEDBACK_SIZE);

		// enter given feedback date
		date feedbackDate;
		do
		{
			cout << "Please enter a valid date: " << endl;
		} while (!initializeDate(feedbackDate)); // check valid date
		buyerAndSeller *temp1 = dynamic_cast<buyerAndSeller*>(system.getUsersArr()[indexUsersArr]);
		buyers *temp2 = dynamic_cast<buyers*>(system.getUsersArr()[indexUsersArr]);
		if (temp1)
		{
			Feedback newFeedback(feedbackDate, temp1, feedbackString); // constructor
			insertFeedbackToSellerInSystem(tempSeller, newFeedback); // add new feedback to feedback array of the seller

		}
		if (temp2)
		{
			Feedback newFeedback(feedbackDate, temp2, feedbackString); // constructor
			insertFeedbackToSellerInSystem(tempSeller, newFeedback); // add new feedback to feedback array of the seller

		}
	}
	else
		cout << "The user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

bool manager::findBuyerInSystem(int &indexUserArr)
{
	char userName[MAX_NAME_SIZE] = { 0 };
	cout << "Please enter your user name:" << endl;
	cleanBuffer();
	cin.getline(userName, MAX_NAME_SIZE);
	for (indexUserArr = 0; indexUserArr < system.getCountUsers(); indexUserArr++)
	{
		buyerAndSeller *temp1 = dynamic_cast<buyerAndSeller*>(system.getUsersArr()[indexUserArr]);
		buyers *temp2 = dynamic_cast<buyers*>(system.getUsersArr()[indexUserArr]);
		//temp1 & temp2 indicate if the user is either a seller or a buyer which is also a seller
		if (temp1)
		{
			if (strcmp(userName, temp1->getName()) == 0) // indicate user is find
			return true;
		}
		if (temp2)
		{
			if (strcmp(userName, temp2->getName()) == 0) // indicate user is find
				return true;
		}

	}
	return false;
}

char * manager::chooseSeller(int & indexUsersArr)
{
	int  numberOfOrdersPerBuyer, numberOfSellersPerOrder, orderChoosen, sellerChoosen;
	if (findBuyerInSystem(indexUsersArr)) // "findBuyerInSystem" function returns true if buyer is found in the system and his index in buyer array of system
	{// להוסיף דינמיק קאסט
		system.getUsersArr()[indexUsersArr]->showAllSellersInBuyerorder(); // show sellers that buyer had bought from
		numberOfOrdersPerBuyer = system.getUsersArr()[indexUsersArr]->getCountOrders(); // get counter orders of the buyer
		cout << "To which one of them would you like to give feedback ? " << endl;
		cout << "Enter the order number:" << endl;
		cin >> orderChoosen;
		while (!(orderChoosen <= numberOfOrdersPerBuyer))// check the order exists in orders arr for this buyer
		{
			cout << "The order number you entered is not exists, please enter a valid order number:" << endl;
			cin >> orderChoosen;
		}
		cout << "Enter the seller number: " << endl;
		cin >> sellerChoosen;
		numberOfSellersPerOrder = system.getUsersArr()[indexUsersArr]->getOrdersArr()[orderChoosen - 1]->getCountSellersInSellersArr(); // get counter sellers that the buyer bought from 
		while (!(sellerChoosen <= numberOfSellersPerOrder))//check seller exists in the order the user choose
		{
			cout << "The seller number you entered is not exists, please enter a valid seller number:" << endl;
			cin >> sellerChoosen;
		}
	}
	//return the seller name
	return system.getUsersArr()[indexUsersArr]->getOrdersArr()[orderChoosen - 1]->getsellersArr()[sellerChoosen - 1]->getName();
}

bool manager::initializeDate(date & feedbackDate)// use in option 4
{
	int day, month, year;
	cout << "Please enter the day number:" << endl;
	cin >> day;
	cout << "Please enter the month number:" << endl;
	cin >> month;
	cout << "Please enter the year number:" << endl;
	cin >> year;
	if (!feedbackDate.setDay(day)) // check validation
	{
		cout << "The day number isn't valid" << endl;
		return false;
	}
	if (!feedbackDate.setMonth(month)) // check validation
	{
		cout << "The month number isn't valid" << endl;
		return false;
	}
	if (!feedbackDate.setYear(year)) // check validation
	{
		cout << "The year number isn't valid" << endl;
		return false;
	}
	return true;
}

void manager::insertFeedbackToSellerInSystem(char *tempSeller, Feedback &newFeedback)
{
	bool sellerNotFound = true; // flag for the "for" loop
	for (int i = 0; sellerNotFound && i < system.getCountUsers(); i++)
	{
		buyerAndSeller *temp1 = dynamic_cast<buyerAndSeller*>(system.getUsersArr()[i]);
		sellers *temp2 = dynamic_cast<sellers*>(system.getUsersArr()[i]);
		//temp1 & temp2 indicate if the user is either a seller or a buyer which is also a seller
		if (temp1 || temp2)
		{
			if (!strcmp(system.getUsersArr()[i]->getName(), tempSeller)) // search the relevence seller to give feedback for
			{
				system.getUsersArr()[i]->addFeedback(newFeedback); // add feedback to feedback array's seller
				sellerNotFound = false;
			}
		}

	}
}

//----------------------------------related to option 6 -create a wish list---------------// 

void manager::addToWishlist()
{
	int indexUsersArr = 0;
	if (findBuyerInSystem(indexUsersArr)) // "findBuyerInSystem" function returns true if buyer is found and his index in buyer array's system
	{
		int sellerIndex, productIndex;
		Product *tempProduct;
		sellers *tempSellers;
		printProductsByName(); // print all products that the buyer is interested in

		cout << "Please enter the Product number you wish to add to your wish list: \n(as it written in screen on the first line) " << endl;
		 
		checkValidIndex(sellerIndex,productIndex);
		// enter the product that the buyer choose to his wish list
		tempProduct = system.getSellersArr()[sellerIndex]->getProductArr()[productIndex];
		tempSellers = system.getSellersArr()[sellerIndex];
		system.getBuyersArr()[indexUsersArr]->addProductSellerToWishlist(tempProduct, tempSellers);
		system.getBuyersArr()[indexUsersArr]->addOneToWishListArr();
	}
	else
		cout << "The user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

void manager::checkValidIndex(int &sellerIndex, int& productIndex)
{
	char ch;
	bool flag = false;
	cin >> sellerIndex >> ch >> productIndex;
	while (!flag)
	{
		if ((sellerIndex < system.getCountSeller() && sellerIndex >= 0))//the seller exists
		{
			if (!(productIndex < system.getSellersArr()[sellerIndex]->getCountProduct() && productIndex >= 0))//the product isn't exists
			{
				cout << "The number you entered isn't valid. \nPlease enter the Product number you wish to add to your wish list: \n(as it written in screen on the first line) " << endl;
				cin >> sellerIndex >> ch >> productIndex;
			}
			else
				flag = true;//both seller product is exists
		}
		else
		{
			cout << "The number you entered isn't valid. \nPlease enter the Product number you wish to add to your wish list: \n(as it written in screen on the first line) " << endl;
			cin >> sellerIndex >> ch >> productIndex;
		}
	}
}

//----------------------------------related to option 7 -add order------------------------// 

order* manager::createNewOrder(int &indexBuyersArr)
{
	Product *tempProduct;//we will save a temporary product that we will insert to the products arr in a specific order
	sellers *tempSeller;//we will save a temporary seller that we will insert to the sellers arr in a specific order
	double productPrice = 0;
	int choosenItems;
	int countProductInWishList = system.getBuyersArr()[indexBuyersArr]->getCountProductInWishList();

	system.getBuyersArr()[indexBuyersArr]->showWishList(); // show the buyer wish list
	cout << "Which product from your wish list would you like to buy? enter their numbers" << endl;
	cout << "When you finished please enter -1 " << endl;
	cin >> choosenItems;

	order *newOrder = new order;
	while (choosenItems != -1 && (0 < choosenItems && choosenItems <= countProductInWishList)) // give the buyer the option to choose products
	{//the second check in the while loop line is for the first input the user types, must be a product that is exists in his wish list
		tempProduct = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct();
		newOrder->addProductToProductArr(*tempProduct);//adding product to the current order product array

		productPrice = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getProduct()->getPrice();
		newOrder->setTotalPrice(productPrice);

		tempSeller = system.getBuyersArr()[indexBuyersArr]->getWishListArr()[choosenItems - 1]->getseller();

		if (!system.getBuyersArr()[indexBuyersArr]->checkIfSellerExistsInAllOrders(tempSeller))//return true if the seller not exists in the buyer order
			newOrder->addSellerToSellersArr(*tempSeller);
		//otherwise, the seller is already exists in the buyer order
		cin >> choosenItems;

		checkValidChoosenItem(choosenItems, indexBuyersArr, countProductInWishList);
	}
	if (choosenItems == -1 && newOrder->getCountProductInProductArr()>0)
		cout << "You have finished your order!\nPlease enter 7 in the interactive shell for paying" << endl;
	return newOrder;
}

void manager::checkValidChoosenItem(int &choosenItem,int indexBuyersArr, int countProductInWishList)
{
	while (!(0 < choosenItem && choosenItem <= countProductInWishList)&& choosenItem!=-1)
	{
		cout << "The number you choose isn't in range of the number of product you have in your wish list. \nplease enter a new number:" << endl;
		cin >> choosenItem;
	}
}

void manager::addOrderToBuyer()
{
	int indexBuyersArr = 0;
	int theLatestOrderForASpacificBuyer;//index the last order the buyer made
	if (findBuyerInSystem(indexBuyersArr)) // "findBuyerInSystem" function returns true is buyer is found and his index in buyer array's system
	{
		theLatestOrderForASpacificBuyer = system.getBuyersArr()[indexBuyersArr]->getCountOrders() - 1;//index the last order the buyer made
		if (theLatestOrderForASpacificBuyer == -1 || system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getOrderPayed())
		{
		  // the check for theLatestOrderForASpacificBuyer to be -1 is for the first order the buyer will make 
		 // the check if(getOrderPayed() == true) is for giving confirming to make an order only if the buyer has paid for all his previous orders
			order *newOrder = createNewOrder(indexBuyersArr);
			if (newOrder->getCountProductInProductArr() > 0)
			{//we want to update the order array for this buyer only if he did choose product for this order
				system.getBuyersArr()[indexBuyersArr]->addOrderToOrdersArr(newOrder);// adding a new order for the current buyer
				system.getBuyersArr()[indexBuyersArr]->addOneToCountOrders(); // increasing counter by one for new order
			}
			else
				cout << "You didn't add any product to the order" << endl;
			delete newOrder;
		}
		else // case buyer didn't pay on his last order yet
		{
			cout << "Please enter 7 in the interactive shell for paying on your last order, then you can make a new order as you wish :)" << endl;
			return;
		}
	}
	else // case buyer name input isn't found in system
		cout << "The user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

//----------------------------------related to option 8 payment---------------// 

void manager::payment()
{
int indexBuyersArr = 0;
bool approvepurchase;

	if (findBuyerInSystem(indexBuyersArr)) // "findBuyerInSystem" function returns true is buyer is found and his index in buyer array's system
	{
		int theLatestOrderForASpacificBuyer = system.getBuyersArr()[indexBuyersArr]->getCountOrders() - 1; // last order to pay for now
		cout << "The items below are the last order you made: " << endl;
		system.getBuyersArr()[indexBuyersArr]->showBuyerorderByIndex(theLatestOrderForASpacificBuyer);
		
		double totalPriceForASpaCificOrder = system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->getTotalPrice(); // total price of last order
		cout << "The total price is: " << totalPriceForASpaCificOrder << " press 1 to make the approve the purchase"<< endl;
	
		cin >> approvepurchase;
		if (approvepurchase) // payment is done
		{
			system.getBuyersArr()[indexBuyersArr]->deleteProductFromBuyerWishList(theLatestOrderForASpacificBuyer); // clean wish list from product that has been payed
			system.getBuyersArr()[indexBuyersArr]->getOrdersArr()[theLatestOrderForASpacificBuyer]->setOrderPayedTrue(); // update field of payment that the last order payed so the buyer can make a new order if he want to
			cout << "Purchase has done successfully " << endl;
		}
		else // input 0 - buyer canceled the payment
			cout << "Purchase canceled " << endl;
	}
	else // case buyer isn't found in the system
		cout << "The user name you typed is not exist in our system, please type a new name or create a new user" << endl;
}

//----------------------------------related to option 9 print buyers---------------// 

void manager::printBuyers()
{
	for (int i = 0; i < system.getCountBuyer(); i++) // run on buyers array in system
	{
		//print basic details
		cout << "This is Buyer " << i + 1 << " of our system: " << endl;
		system.getBuyersArr()[i]->showUserBasicDeatelis();
		if (system.getBuyersArr()[i]->getWishListArr() != nullptr) // print his wish list
		{
			cout << "This are Products in his current wish list: " << endl;
			for (int j = 0; j < system.getBuyersArr()[i]->getCountProductInWishList(); j++)
				system.getBuyersArr()[i]->getWishListArr()[j]->getProduct()->show();
			cout << system.getBuyersArr()[i]->getName() << " has " << system.getBuyersArr()[i]->getCountProductInWishList() << " items in his wish list" << endl;
		}
		else
			cout << "The buyer wish list is Empty" << endl;
		if (system.getBuyersArr()[i]->getCountOrders() > 0) // print his orders
		{
			for (int j = 0; j < system.getBuyersArr()[i]->getCountOrders(); j++)
			{//'j' is the index for the orders array
				cout << "This is the " << j + 1 << " order in his orders history" << endl;
				for (int k = 0; k < system.getBuyersArr()[i]->getOrdersArr()[j]->getCountProductInProductArr(); k++)//'k' is the index of the product in the current order
					system.getBuyersArr()[i]->getOrdersArr()[j]->getProductArr()[k]->show();
			}
		}
		else
			cout << "The buyer orders history is Empty" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

//----------------------------------related to option 10 print sellers---------------// 

void manager::printSellers()
{
	for (int i = 0; i < system.getCountSeller(); i++)
	{
		// print basic details
		cout << "This is Seller " << i + 1 << " of our system: " << endl;
		system.getSellersArr()[i]->showUserBasicDeatelis();

		if (system.getSellersArr()[i]->getProductArr() != nullptr) // print his products
		{
			cout << "This is his current Products list: " << endl;
			for (int j = 0; j < system.getSellersArr()[i]->getCountProduct(); j++)
			{
				system.getSellersArr()[i]->getProductArr()[j]->show();
			}
		}
		else
			cout << "The seller Products list is Empty" << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

//----------------------------------related to option 11 print buyerSeller's---------------// 


//----------------------------------related to option 12 (and 5) - print products---------------// 

void manager::printProductsByName() // print all products in system by demanded name
{
	char productName[MAX_NAME_SIZE] = { 0 };
	cout << "Please enter which product you are looking for :" << endl;
	cin.getline(productName, MAX_NAME_SIZE);
	system.showProductWithIdenticalName(productName);
	
}