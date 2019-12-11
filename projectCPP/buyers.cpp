#include "buyers.h"
//
//buyers::buyers(char *user_name, char *password, const address_user & address) //constructor
//	:address(address)
//{
//	this->user_name = new char[strlen(user_name) + 1];
//	strcpy(this->user_name, user_name);
//	this->user_name[strlen(user_name)] = '\0';
//
//	this->password = new char[strlen(password) + 1];
//	strcpy(this->password, password);
//	this->password[strlen(password)] = '\0';
//
//}
buyers::buyers(char *user_name, char *password, const address_user & address, wishList **WishListArr) :address(address)
{
	this->user_name = new char[strlen(user_name) + 1];
	strcpy(this->user_name, user_name);
	this->user_name[strlen(user_name)] = '\0';

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
	this->password[strlen(password)] = '\0';
	this->WishListArr = nullptr;
}
buyers::buyers(const buyers &other) : address(other.address)//copy c'tor
{
	this->user_name = strdup(other.user_name);
	this->password = strdup(other.password);
}


buyers::~buyers() //destructor
{
	// does we need those delete? we allocate string in static way
	delete[]WishListArr;
}


bool buyers::setName(const char* n) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	//משום שאנחנו מקצות בmanager שם משתמש בגודל 20, תמיד שנקבל מהמקלדת שם הוא יהיה לכל היותר באורך 20 גם אם המשתמש הכניס 100 תווים 
	/*
	if (user_name != NULL)
		delete[] user_name;
	*/
	if (strlen(n) <= MAX_NAME_SIZE) //valid name
	{
		user_name = new char[strlen(n)+1];
		strncpy(user_name,n,strlen(n));
		user_name[strlen(n)] = '\0';
	}
	
	else
		return false;

	return true;
}

bool buyers::setPassword(const char* p) //להוסיף דרישה לאתחול שם המערכת במאיין של הפרויקט- לזכור להתמודד עם הערך שחוזר מהפונקציה
{
	/*
	if (password != NULL)
		delete[] password;
		*/
	if ((strlen(p) >= MAX_PASSWORD_SIZE) && (strlen(p) <= MIN_PASSWORD_SIZE))// password in range 8-20
	{
		password = new char[strlen(p) + 1];
		strncpy(password, p,strlen(p));
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
	int i = getCountProductInWishList() - 1;
	if (getCountProductInWishList() == 0)
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
