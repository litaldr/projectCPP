
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

buyers::buyers(const buyers &other) : address(other.address), WishListArr(other.WishListArr), ordersArr(other.ordersArr) //copy c'tor
{
	this->user_name = strdup(other.user_name);
	this->password = strdup(other.password);
	this->CountOrders = other.CountOrders;
	this->CountProductInWishList = other.CountProductInWishList;

}


buyers::~buyers() //destructor
{
	// does we need those delete? we allocate string in static way
	delete[]WishListArr;
	delete[]ordersArr;
}


bool buyers::setName(const char* n) 
{	/*
	if (user_name != NULL)
	delete[] user_name;
	*/
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
{
	/*
	if (password != NULL)
	delete[] password;
	*/
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
{
	return user_name;
}
address_user buyers::getAddress()  const
{
	return address;
}
int buyers::getCountProductInWishList() const
{
	return CountProductInWishList;
}
void  buyers::setCountProductInWishList(int n)
{
	this->CountProductInWishList = n;
}
wishList **buyers::getWishListArr() const
{
	return WishListArr;
}
void buyers::addProductToWishlist(Product *newProduct)
{
	int i = CountProductInWishList - 1;
	if (CountProductInWishList == 0)
		this->WishListArr = new wishList*;//if it is the first buyer
	else
	{
		WishListArr = reallocWishList(WishListArr, i + 1);//if it isn't the first buyer
	}
	i++;
	WishListArr[i] = new wishList(newProduct);// c'tor product only
}
wishList ** buyers::reallocWishList(wishList **oldWishListArr, int size)
{
	wishList **newWishListArr = new wishList*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newWishListArr[i] = oldWishListArr[i];
		//delete[]oldProductArr[i]
	}
	delete[]oldWishListArr;
	return newWishListArr;
}

//order functions
void buyers::addOrderToOrdersArr(order *newOrder,double totalPrice)
{
	int i = getCountOrders() - 1;
	if (getCountOrders() == 0)
		this->ordersArr = new order*;//if it is the first buyer
	else
	{
		ordersArr = reallocOrdersArr(ordersArr, i + 1);//if it isn't the first buyer
	}
	i++;
	ordersArr[i] = new order(*newOrder);// c'tor product only 
	ordersArr[i]->setTotalPrice(totalPrice);
}
order ** buyers::reallocOrdersArr(order **oldOrdersArr, int size)
{
	order **newOrdersArr = new order*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newOrdersArr[i] = oldOrdersArr[i];
		//delete[]oldProductArr[i]
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

void buyers::showWishList() const
{
	int productIndex;
	for (productIndex = 0; productIndex < CountProductInWishList; productIndex++)
	{
		cout << "ProductNumber in wish list is: " << productIndex+1 << endl;
	    getWishListArr()[productIndex]->getProduct()->show();
		
	}
}
bool buyers::checkIfSellerExistsInAllOrders(const sellers *seller)
{// return true if the seller isn't exists the buyer order
	int i;
	for(i=0;i < getCountOrders(); i++)
	{
		if (!getOrdersArr()[i]->checkIfSellerExists(seller))
			// inside the "if" we will return false if the seller is exists the buyer order, so we will enter the "if" (operator"!")
			return false;
	}
	return true;
}
void buyers::showBuyerBasicDeatelis() const
{
	cout << "user name is: " << user_name << endl;
	cout << "user password is: " << password << endl;
	address.show();
}
void buyers::showBuyerorderByIndex(int index) const
{
	cout << "the products in order number" << index+1 << "are:" << endl;
	for (int i = 0; i < ordersArr[index]->getCountProductInProductArr(); i++)
	{
		ordersArr[index]->getProductArr()[i]->show();
	}
}
void buyers::deleteProductFromBuyerWishList(int OrderIndex) 
//this function will  delete the products that the buyer purchase from his wish list in the latest order
{
	int i,j,countNewSizeWishList= this->CountProductInWishList;
	for (i = 0; i < ordersArr[OrderIndex]->getCountProductInProductArr(); i++)
	{
		for (j = 0; j < this->CountProductInWishList; j++)
		{
			if (!(WishListArr[j]==NULL))
			{
				if (ordersArr[OrderIndex]->getProductArr()[i]->getItemSerialNumber() == WishListArr[j]->getProduct()->getItemSerialNumber())
				{
					WishListArr[j] = NULL;
					countNewSizeWishList--;
				}
			}
		}
	}
	if (countNewSizeWishList != 0)
	{//if countNewSizeWishList=0 it means that the buyer  purchase all of the product he had in his wish list
		j = 0;//initialize the index so we can use it for new wish list
		wishList** newWishList = new wishList*[countNewSizeWishList];
		for (i = 0; i < this->CountProductInWishList; i++)
		{
			if (WishListArr[i] != nullptr)
			{
				newWishList[j] = new wishList(WishListArr[i]->getProduct(), WishListArr[i]->getseller());
				j++;
			}

		}
		delete[]WishListArr;
		WishListArr = newWishList;
		this->CountProductInWishList=countNewSizeWishList;
	}
	else
	{//there is no product in the wish list
		delete[]WishListArr;
		this->CountProductInWishList=0;

	}
}
