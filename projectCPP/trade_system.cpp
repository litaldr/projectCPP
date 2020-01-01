#include "trade_system.h"

int trade_system::count_users = 0; // init

trade_system::~trade_system() //destructor
{
	delete[]system_name;

	for (int i = 0; i < count_users; i++)
	{
		delete usersArr[i];
	}
	delete[]usersArr;
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

	if (system_name != NULL) // initialize the system name as null-ptr 
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

void trade_system::setCountUsers(int i)
{
	count_users = i;
}

int trade_system::getCountUsers()
{
	return count_users;
}


user** trade_system::getUsersArr()
{
	return usersArr;
}


//-----------------------not in use----------------------//
char * trade_system::getName() const
{
	return system_name;
}

//------------------------------add users to system functions-------------------------------//

bool trade_system::addUser(user& newUser)
{
	int i = count_users - 1;
	if (nameAvailable(newUser.getName()))// this function will return true if the name is not in use for other buyer
	{
		if (count_users == 0)//if it is the first buyer
			usersArr = new user*;
		else
		{
			usersArr = reallocUsersArr(usersArr, i + 1); //if it isn't the first buyer
		}
		i++;
		(usersArr[i]) = new user(newUser);
		count_users =i + 1;
		return true;
	}
	return false;
}


user ** trade_system::reallocUsersArr(user **oldUsersArr, int size) // function increase by one the users array for a new user
{
	user **newUsersArr = new user*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newUsersArr[i] = oldUsersArr[i];
	}
	delete[]oldUsersArr;
	return newUsersArr;
}


bool trade_system::nameAvailable(char *comperdName) // function checks that all buyers and sellers in the system have different name
{
		for (int i = 0; i < count_users; i++)
		{
			if (strcmp((usersArr[i]->getName()), comperdName) == 0)
				return false;
		}
		return true;
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
