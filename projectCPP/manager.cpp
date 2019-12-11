#include "manager.h"


void run() // function run on using system
{
	trade_system system;
	init_system_name(system); // call set system name function
	int input;
	do // run over the user actions untill he choose to exit
	{
		printMenu();
		input = getAction();
		doAction(input, &system);
	} while (input != EXIT);
}

void init_system_name(trade_system &system) //function to initialize the system name
{
	char system_name[MAX_NAME_SIZE] = { 0 };
	cout << "Hello, enter your desire system name which contains maximum: " << (MAX_NAME_SIZE) << " charcters please: " << endl;

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
	// להוסיף - הוספת פידבק, הוספת מוצר
}

int getAction() // function give indicate which action the user is about to choose
{
	int input;
	cin >> input; // the input is in the buffer from the printManu function
	while (!((input <= 11) && (input >= 1))) //check input (action) validetion
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
void ** pointersArr(void * arr, int size)
{
	void ** pointersArr = new void*[size++];

	delete[]arr;
	return pointersArr;
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
		sellers *seller = new sellers(name, password, *address, NULL, NULL);

		while (!(system->addSeller(*seller)))
		{
			cout << "the user name you entered is in use, please type a new name" << endl;
			cleanBuffer();
			cin.getline(name, MAX_NAME_SIZE);
			while (!seller->setName(name))
			{
				cout << "the user name you entered is not valid, please type a new name" << endl;
				cin.getline(name, MAX_NAME_SIZE);
			}
			cout << "your user name changed successfully" << endl;
		}
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

		int indexSellersArr;
		int flag=false; //indicate the adding product did not succsseed - cause the seller name do not exist in our system
		for (indexSellersArr = 0; indexSellersArr < system->getCountSeller(); indexSellersArr++)
		{
			if (strcmp(userName, system->getSellersArr()[indexSellersArr]->getName()) == 0)
			{
				system->getSellersArr()[indexSellersArr]->addProduct(*newProduct);
				flag = true;
			}
		}

		if(flag ==false)
			cout << "the user name you typed is not exist in our system" << endl;
	}
/*
	if (num == 4)
	{
	}
	*/
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
		int sellerIndex, productIndex;
		cout << "please enter the ProductNumber (as it written in screen) you wish to add to your wishlist:" << endl;
		cin >> sellerIndex >> ch >> productIndex;
		
		int flag = false; 
		int indexBuyersArr;
		for (indexBuyersArr= 0; indexBuyersArr < system->getCountBuyer(); indexBuyersArr++)
		{
			if (strcmp(buyerName, system->getBuyersArr()[indexBuyersArr]->getName()) == 0)
			{
				system->getBuyersArr()[indexBuyersArr]->addProductToWishlist(*(system->getSellersArr()[sellerIndex]->getProductArr()[productIndex]));
				system->getBuyersArr()[indexBuyersArr]->getWishListArr()[system->getBuyersArr()[indexBuyersArr]->getCountProductInWishList()]->setSeller(*(system->getSellersArr()[sellerIndex]));
				flag = true;
			}
		}

		if (flag == false)
			cout << "the user name you typed is not exist in our system" << endl;


	}
	/*
	case 6: // מתודה ביצוע הזמנה עבור מחלקה של קונה
	break;
	case 7: // מתודת תשלום הזמנה עבור מחלקה של קונה
	break;
	case 8: // מתודה הדפסת פרטי הקונים עבור מחלקה של trade system
	break;
	case 9: // מתודה הדפסת פרטי המוכרים עבור מחלקה של trade system
	break;*/
	if (num == 10)
	{
		char productName[MAX_NAME_SIZE] = { 0 };
		cout << "please enter which product you are looking for :" << endl;
		cleanBuffer();
		cin.getline(productName, MAX_NAME_SIZE);

		system->showProductWithIdenticalName(productName);
	}
/*
	break;
	case 11:
	cout << "Goodbye :)" << endl;
	break;

	}
	*/
}
/*
char * reallocForString(char s[], int newSize)
{
char *newString = new char[newSize];
for (int i = 0; i < newSize-1; i++)
{
newString[i]=s[i];
}
delete[]s;
newString[newSize] = '\0';
return newString;
}*/