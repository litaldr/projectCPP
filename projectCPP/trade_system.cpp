#include "trade_system.h"

int trade_system::count_buyers = 0; // init
int trade_system::count_sellers = 0; // init

trade_system::~trade_system() //destructor
{
	delete[]system_name;

	for (int i = 0; i < count_buyers; i++)
	{
		delete buyersArr[i];
	}
	delete[]buyersArr;
	for (int i = 0; i < count_sellers; i++)
	{
		delete sellersArr[i];
	}
	delete[]sellersArr;
}

//-----------------------not in use----------------------//
trade_system::trade_system(const char *name) //constructor
{
	this->system_name = new char[strlen(name) + 1];
	strncpy(this->system_name, name,strlen(name));
	this->system_name[strlen(system_name)] = '\0';
}

trade_system::trade_system(const trade_system & other)//copy constructor
{
	this->system_name = strdup(other.system_name);
}

//-------------------------------------------------------------//

//------------------------------set & get function-------------------------------//

bool trade_system::setName(const char* n)  //check valid name
{

	if (system_name != NULL) // initialize the system name as nullptr 
		delete[] system_name;

	if (strlen(n) <= MAX_NAME_SIZE) // check valid length name
	{
		system_name = new char[strlen(n) + 1];
		strncpy(system_name, n, strlen(n));
		system_name[strlen(n)] = '\0';
	}
	else
		return false;

	return true;
}

void trade_system::setCountBuyer(int i)
{
	count_buyers = i;
}

void trade_system::setCountSeller(int j)
{
	count_sellers = j;
}


int trade_system::getCountBuyer()
{
	return count_buyers;
}

int trade_system::getCountSeller()
{
	return count_sellers;
}

buyers** trade_system::getBuyersArr()
{
	return buyersArr;
}

sellers** trade_system::getSellersArr()
{
	return sellersArr;
}

//-----------------------not in use----------------------//
char * trade_system::getName() const
{
	return system_name;
}
//-----------------------not in use----------------------//

//------------------------------add buyers and sellers to system functions-------------------------------//

bool trade_system::addBuyer(buyers& buyer)
{
	int i = count_buyers - 1;
	if (trade_system::nameAvailable(buyer.getName(), false))// this function will return true if the name is not in use for other buyer
	{
		if (count_buyers == 0)//if it is the first buyer
			buyersArr = new buyers*;
		else
		{
			buyersArr = reallocbuyers(buyersArr, i + 1); //if it isn't the first buyer
		}
		i++;
		(buyersArr[i]) = new buyers(buyer);
		count_buyers =i + 1;
		return true;
	}
	return false;
}

bool trade_system::addSeller(sellers& seller)
{
	int i = count_sellers - 1;
	if (trade_system::nameAvailable(seller.getName(),true))// this function will return true if the name is not in use for other seller
	{
		if (count_sellers == 0) //if it is the first buyer
			sellersArr = new sellers*;
		else
		{
			sellersArr = reallocSellers(sellersArr, i + 1);//if it isn't the first buyer
		}
		i++;
		(sellersArr[i]) = new sellers(seller);
		count_sellers =i + 1;
		return true;
	}
	return false;
}

buyers ** trade_system::reallocbuyers(buyers **oldBuyersArr, int size) // function increase by one the buyers array for a new buyer
{
	buyers **newBuyersArr = new buyers*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newBuyersArr[i] = oldBuyersArr[i];
	}
	delete[]oldBuyersArr;
	return newBuyersArr;
}

sellers ** trade_system::reallocSellers(sellers **oldSellersArr, int size) // function increase by one the sellers array for a new seller
{
	sellers **newSellersArr = new sellers*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newSellersArr[i] = oldSellersArr[i];
	}
	delete[]oldSellersArr;
	return newSellersArr;
}

bool trade_system::nameAvailable(char *comperdName, bool flag) // function checks that all buyers and sellers in the system have different name
{
	if (flag)//if flag value is true we'll check if the user seller name is taken
	{
		for (int i = 0; i < count_sellers; i++)
		{
			if (strcmp((sellersArr[i]->getName()), comperdName) == 0)
				return false;
		}
		return true;
	}
	else//if flag value is false we'll check if the user seller name is taken
	{
		for (int i = 0; i < count_buyers; i++)
		{
			if (strcmp((buyersArr[i]->getName()), comperdName) == 0)// 
				return false;
		}
		return true;
	}

}

//------------------------------show products in the system functions-------------------------------//

void trade_system::showProductWithIdenticalName(const char *nameProduct) const
{
	int sellerIndex, productIndex;
	for (sellerIndex = 0; sellerIndex < count_sellers; sellerIndex++)
	{
		for (productIndex = 0; productIndex < sellersArr[sellerIndex]->getCountProduct(); productIndex++)
		{
			if ((strcmp(nameProduct, sellersArr[sellerIndex]->getProductArr()[productIndex]->getName())) == 0)
			{
				cout << "ProductNumber is: " << sellerIndex << "." << productIndex << endl;
				sellersArr[sellerIndex]->getProductArr()[productIndex]->show();
			}
		}
	}
}
