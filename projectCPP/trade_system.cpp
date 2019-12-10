#include "trade_system.h"
//להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה



trade_system::trade_system(const char *name) //constructor
{
	this->system_name = new char[strlen(name) + 1];
	strcpy(this->system_name, name);

}

trade_system::~trade_system() //destructor
{
	// does we need those delete? we allocate string in static way
	delete[]system_name;
}


trade_system::trade_system(const trade_system & other)//copy c'tor
{
	this->system_name = strdup(other.system_name);
}

bool trade_system::setName(const char* n)  //check valid name
{
	
	if (system_name != NULL) // initialize the system name as nullptr 
		delete[] system_name;
		
	if (strlen(n) <= MAX_NAME_SIZE) // check valid length name
	{
		system_name = new char[strlen(n) + 1];
		strcpy(system_name, n);
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

char * trade_system::getName() const
{
	return system_name;
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

void trade_system::addBuyer(buyers& buyer)
{
	int i = getCountBuyer() - 1;
	if (getCountBuyer() == 0)
		buyersArr = new buyers*;//if it is the first buyer
	else
	{
		buyersArr = reallocbuyers(buyersArr, i + 1);//if it isn't the first buyer
	}
	i++;
	(buyersArr[i]) = new buyers(buyer);
	setCountBuyer(i + 1);
}

bool trade_system::addSeller(sellers& seller)
{
	int i = getCountSeller() - 1;
	if (trade_system::compreName(seller.getName()))// לא עובד, כי יש בעיה בקליטה של המחרוזות
	{
		if (getCountSeller() == 0)
			sellersArr = new sellers*;//if it is the first buyer
		else
		{
			sellersArr = reallocSellers(sellersArr, i + 1);//if it isn't the first buyer
		}
		i++;
		(sellersArr[i]) = new sellers(seller);
		setCountSeller(i + 1);
		return true;
	}
	return false;
}

buyers ** trade_system::reallocbuyers(buyers **oldBuyersArr, int size)
{
	buyers **newBuyersArr = new buyers*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newBuyersArr[i] = oldBuyersArr[i];
		//delete[]oldBuyersArr[i];
	}
	delete[]oldBuyersArr;
	return newBuyersArr;
}

sellers ** trade_system::reallocSellers(sellers **oldSellersArr, int size)
{
	sellers **newSellersArr = new sellers*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newSellersArr[i] = oldSellersArr[i];
		//delete[] oldSellersArr)[i]
	}
	delete[]oldSellersArr;
	return newSellersArr;
}

bool trade_system::compreName(char *comperdName) // יש בעיה לא מגיעים למוכר במקום ה- איי במערך
{
	for (int i = 0; i < count_sellers; i++)
	{
		if (strcmp((sellersArr[i]->getName()), comperdName) == 0) 
			return false;
	}
	return true;
	int j = 0;
}



/*
bool Tribe::addSurvivor(Survivor& newSurvivor)
{
if (m_currentNumOfSurvivors < m_maxSurvivors)
{
m_allSurvivors[m_currentNumOfSurvivors++] = &newSurvivor;
return true;
}
else
return false;
}
*/