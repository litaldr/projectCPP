
#include "buyers.h"


buyers::buyers(char *user_name, char *password, const address_user & address) //constructor
	:address(address)
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name)] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password)] = '\0';
	this->WishListArr = nullptr;
	this->ordersArr = nullptr;
	this->CountOrders = 0;
	this->CountProductInWishList = 0;
}

buyers::~buyers() //destructor
{
	delete[]user_name;
	delete[]password;
	if (CountProductInWishList)//if wish list is empty it means we didn't allocate it, so no need to delete
	{
		for (int i = 0; i < CountProductInWishList; i++)
		{
			delete WishListArr[i];
		}
		delete[]WishListArr;
	}
	for (int i = 0; i < CountOrders; i++)
	{
		delete ordersArr[i];
	}
	delete[]ordersArr;
}

bool buyers::setName(const char* n) 
{//not in use yet
	if (strlen(n) <= MAX_NAME_SIZE) //valid name
	{
		user_name = new char[strlen(n) + 1];
		strncpy(user_name, n, strlen(n));
		user_name[strlen(n)] = '\0';
	}

	else
		return false;

	return true;
}

bool buyers::setPassword(const char* p) 
{//not in use yet
	
	if ((strlen(p) >= MAX_PASSWORD_SIZE) && (strlen(p) <= MIN_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strncpy(password, p, strlen(p));
		password[strlen(p)] = '\0';

	}
	else
		return false;

	return true;
}

char * buyers::getName() const
{
	return user_name;
}

char * buyers::getPassword() const
{//not in use yet
	return user_name;
}

address_user buyers::getAddress()  const
{//not in use yet
	return address;
}

void buyers::showBuyerBasicDeatelis() const
{
	cout << "user name is: " << user_name << endl;
	cout << "user password is: " << password << endl;
	address.show();
}

//-----------------------------wish list functions---------------------------//

int buyers::getCountProductInWishList() const
{
	return CountProductInWishList;
}

void  buyers::addOneToWishListArr()
{
	this->CountProductInWishList+=1;
}

wishList **buyers::getWishListArr() const
{
	return WishListArr;
}

void buyers::addProductToWishlist(Product *newProduct, sellers * newSeller)
{
	int i = CountProductInWishList - 1;
	if (CountProductInWishList == 0)
		this->WishListArr = new wishList*;//if it's the first wish list object for the buyer
	else
	{
		WishListArr = reallocWishList(WishListArr, i + 1);
	}
	i++;
	WishListArr[i] = new wishList(newProduct, newSeller);// constructor product only
}

wishList ** buyers::reallocWishList(wishList **oldWishListArr, int size)
{
	wishList **newWishListArr = new wishList*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newWishListArr[i] = oldWishListArr[i];
	}
	delete[]oldWishListArr;
	return newWishListArr;
}

void buyers::showWishList() const
{
	int productIndex;
	for (productIndex = 0; productIndex < CountProductInWishList; productIndex++)
	{
		cout << "ProductNumber in wish list is: " << productIndex+1 << endl;
	    getWishListArr()[productIndex]->getProduct()->show();
		
	}
}

void buyers::deleteProductFromBuyerWishList(int OrderIndex)
//this function will  delete the products that the buyer purchase from his wish list in the latest order
{
	int i, j, countNewSizeWishList = this->CountProductInWishList;
	for (i = 0; i < ordersArr[OrderIndex]->getCountProductInProductArr(); i++)
	{
		for (j = 0; j < this->CountProductInWishList; j++)
		{
			if (WishListArr[j] != NULL)
			{
				if (ordersArr[OrderIndex]->getProductArr()[i]->getItemSerialNumber() == WishListArr[j]->getProduct()->getItemSerialNumber())
				{
					WishListArr[j] = NULL;// changing the pointer, instead of a pointer to a wish list object, puts NULL 
					countNewSizeWishList--;//descended the amount of wish list objects in wish list array
				}
			}
		}
	}
	if (countNewSizeWishList != 0)// creating a new wish list without the products that had been paid 
	{//if countNewSizeWishList=0 it means that the buyer  purchase all of the product he had in his wish list
		j = 0;//initialize the index so we can use it for new wish list
		wishList** newWishList = new wishList*[countNewSizeWishList];
		for (i = 0; i < this->CountProductInWishList; i++)
		{
			if (WishListArr[i] != NULL)
			{
				newWishList[j] = new wishList(WishListArr[i]->getProduct(), WishListArr[i]->getseller());
				j++;
				WishListArr[i] = NULL;
			}
			
		}
		delete[]WishListArr;
		WishListArr = newWishList;
		this->CountProductInWishList = countNewSizeWishList;
	}
	else
	{//there is no product in the wish list
		
		for (i = 0; i < this->CountProductInWishList; i++)
			WishListArr[i] = NULL;
		delete[]WishListArr;
		this->CountProductInWishList = 0;

	}
}





//-----------------------------order functions---------------------------//
void buyers::addOrderToOrdersArr(order *newOrder)
{
	int i = getCountOrders() - 1;
	if (getCountOrders() == 0)
		this->ordersArr = new order*;//if it's the first order in the order array
	else
	{
		ordersArr = reallocOrdersArr(ordersArr, i + 1);
	}
	i++;
	ordersArr[i] = new order(*newOrder);// constructor product only 
}

order ** buyers::reallocOrdersArr(order **oldOrdersArr, int size)
{
	order **newOrdersArr = new order*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newOrdersArr[i] = oldOrdersArr[i];
	}
	delete[]oldOrdersArr;
	return newOrdersArr;
}

order** buyers::getOrdersArr() const
{
	return ordersArr;
}

int buyers::getCountOrders() const
{
	return CountOrders;
}

void buyers::addOneToCountOrders()
{
	this->CountOrders+=1;
}



bool buyers::checkIfSellerExistsInAllOrders(const sellers *seller)
{// return false if the seller isn't exists in the buyer previous orders
	int i;
	for(i=0;i < getCountOrders(); i++)
	{
		if (getOrdersArr()[i]->checkIfSellerExists(seller))
			// the function "checkIfSellerExists" return true if the seller is exists in the index "i" buyer order
			return true;
	}
	return false;
}

void buyers::showBuyerorderByIndex(int index) const //print the products of order at index "i" in order array 
{
	cout << "the products in order number" << index+1 << "are:" << endl;
	for (int i = 0; i < ordersArr[index]->getCountProductInProductArr(); i++)
	{
		ordersArr[index]->getProductArr()[i]->show();
	}
}
void buyers::showAllSellersInBuyerorder() const //print the products of order at index "i" in order array 
{
	int orderIndex;
	cout << "this is all of the sellers you bought from by the orders you have made:" << endl;
	for (orderIndex = 0; orderIndex < CountOrders; orderIndex++)
	{
		cout << "order number:" << orderIndex + 1 << endl;
		ordersArr[orderIndex]->showSellersByCurrOrder();
	}
	
}

