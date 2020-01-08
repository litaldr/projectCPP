#include "buyer.h"

buyer::buyer(char *user_name, char *password, const address_user & address) : user(user_name, password, address) //constructor
{	
	
	this->WishListArr = nullptr;
	this->ordersArr = nullptr;
	this->CountOrders = 0;
	this->CountProductInWishList = 0;
}
buyer::~buyer() //destructor
{
	if (CountProductInWishList)//if wish list is empty it means we didn't allocate it, so no need to delete it
	{
		for (int i = 0; i < CountProductInWishList; i++) // run over wish list array and free memory
		{
			delete WishListArr[i];
		}
		delete[]WishListArr;
	}
	for (int i = 0; i < CountOrders; i++) // run over orders array and free memory
	{
		delete ordersArr[i];
	}
	delete[]ordersArr;
}


//-----------------------------wish list functions---------------------------//

int buyer::getCountProductInWishList() const
{
	return CountProductInWishList;
}

void  buyer::addOneToWishListArr()
{
	this->CountProductInWishList+=1;
}

wishList **buyer::getWishListArr() const
{
	return WishListArr;
}

void buyer::addProductSellerToWishlist(Product *newProduct, sellers * newSeller) // function adds product ansd seller(=wish list object) to wish list array's buyer
{
	int i = CountProductInWishList - 1;
	if (CountProductInWishList == 0) //if it's the first wish list object for the buyer
		this->WishListArr = new wishList*;
	else
	{
		WishListArr = reallocWishList(WishListArr, i + 1); // incraese wish list array for one new wish list objet
	}
	i++;
	WishListArr[i] = new wishList(newProduct, newSeller);// constructor wish list objet- both attributs: product and selller
}

const wishList ** buyer::reallocWishList(wishList **oldWishListArr, int size) // function incraeses wish list array for one new wish list objet
{
	wishList **newWishListArr = new wishList*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newWishListArr[i] = oldWishListArr[i]; 
	}
	delete[]oldWishListArr; // free memory of old wish list array
	return newWishListArr;
}

void buyer::showWishList() const
{
	int productIndex;
	cout << "This is your current wish list:" << endl;
	for (productIndex = 0; productIndex < CountProductInWishList; productIndex++)
	{
		cout << "ProductNumber in wish list is: " << productIndex+1 << endl;
	    getWishListArr()[productIndex]->getProduct()->show();	
	}
}

void buyer::deleteProductFromBuyerWishList(int OrderIndex) //this function will  delete the products that the buyer purchase from his wish list in the latest order
{
	int i, j, countNewSizeWishList = this->CountProductInWishList;

	for (i = 0; i < ordersArr[OrderIndex]->getCountProductInProductArr(); i++) // run over products in specific order
	{
		for (j = 0; j < this->CountProductInWishList; j++) // run over wish list array to delete by replace pointing on products to pointing on NULL: because those products had been ordered
		{
			if (WishListArr[j] != NULL)
			{
				if (ordersArr[OrderIndex]->getProductArr()[i]->getItemSerialNumber() == WishListArr[j]->getProduct()->getItemSerialNumber()) // check product in wish list is identical to product in order's buyer
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
		delete[]WishListArr; // free memory of old wish list
		WishListArr = newWishList; // define the new wish list's buyer
		this->CountProductInWishList = countNewSizeWishList; // update the new counter of wish list object in wish lisr array
	}
	else
	{//there is no product in the wish list
		
		for (i = 0; i < this->CountProductInWishList; i++) // free memory of old wish list
			WishListArr[i] = NULL;
		delete[]WishListArr;
		this->CountProductInWishList = 0; // no product\ wish list object in wish list array 
	}
}

//-----------------------------order functions------------------------------//

int buyer::getCountOrders() const
{
	return CountOrders;
}

void buyer::addOneToCountOrders()
{
	this->CountOrders += 1;
}

order** buyer::getOrdersArr() const
{
	return ordersArr;
}

void buyer::addOrderToOrdersArr(order *newOrder) // function adds order object to orders array's buyer
{
	int i = getCountOrders() - 1;
	if (getCountOrders() == 0) //if it's the first order in the order array
		this->ordersArr = new order*;
	else
	{
		ordersArr = reallocOrdersArr(ordersArr, i + 1); // increase orders array for one new order object
	}
	i++;
	ordersArr[i] = new order(*newOrder);//order constructor 
}

const order ** buyer::reallocOrdersArr(order **oldOrdersArr, int size) // function increases orders array for one new order object
{
	order **newOrdersArr = new order*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newOrdersArr[i] = oldOrdersArr[i];
	}
	delete[]oldOrdersArr;  // free memory of old orders array
	return newOrdersArr;
}

void buyer::showBuyerorderByIndex(int index) const //print the products of order at index "i" in orders array 
{
	cout << "The products in order number " << index + 1 << " are:" << endl;
	for (int i = 0; i < ordersArr[index]->getCountProductInProductArr(); i++)
	{
		ordersArr[index]->getProductArr()[i]->show();
	}
}

void buyer::showAllSellersInBuyerorder() const //print the sellers of order at index "i" in orders array 
{
	int orderIndex;
	cout << "This is all of the sellers you bought from by the orders you have made:" << endl;
	for (orderIndex = 0; orderIndex < CountOrders; orderIndex++)
	{
		ordersArr[orderIndex]->showSellersByCurrOrder();
	}

}

bool buyer::checkIfSellerExistsInAllOrders(const sellers *seller) // function return false if the seller isn't exists in the buyer previous orders
{
	int i;
	for(i=0;i < getCountOrders(); i++)
	{
		if (getOrdersArr()[i]->checkIfSellerExists(seller))
			// the function "checkIfSellerExists" return true if the seller is exists in the index "i" buyer order
			return true;
	}
	return false;
}

