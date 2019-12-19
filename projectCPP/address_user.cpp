#include "address_user.h"

address_user::address_user(const char* country, const char* city, const char *street, int house_number) //constructor
{

	this->country = new char[strlen(country) + 1];
	strncpy(this->country, country, strlen(country));
	this->country[strlen(country)] = '\0';

	this->city = new char[strlen(city) + 1];
	strncpy(this->city, city, strlen(city));
	this->city[strlen(city)] = '\0';

	this->street = new char[strlen(street) + 1];
	strncpy(this->street, street, strlen(street));
	this->street[strlen(street)] = '\0';

	this->house_number= house_number;

}

address_user::address_user(const address_user& other)// copy c'tor
{
	this->country = strdup(other.country);
	this->city = strdup(other.city);
	this->street = strdup(other.street);
	this->house_number = other.house_number;
	
}

address_user::~address_user() //destructor
{
	delete[]country;
	delete[]city;
	delete[]street;
}

void address_user::show()  const
{
	cout << "user country is: " << country << endl;
	cout << "user city is: " << city << endl;
	cout << "user street is: " << street << endl;
	cout << "user house number is : " << house_number << endl;
	cout << "---------------------------------" << endl;
}

//-----------------------not in use----------------------///

bool address_user::setCountry(const char *c)
{
	bool indicate_len = true, indicate_letters = true;
	if (strlen(c) > MAX_NAME_SIZE) //case length is not valid
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		indicate_len = false;
	}
	if (!validString_name(c)) //case character is not valid
	{
		indicate_letters = false;
		cout << "The name must contains only letters or spaces." << endl;
	}
	if (indicate_len && indicate_letters) //case name is valid= set name
	{
		this->country = new char[strlen(c) + 1];
		strncpy(country, c, strlen(c));
		country[strlen(c)] = '\0';
		return true;
	}
	else
		return false;
}

bool address_user::setCity(const char *c)
{
	bool indicate_len = true, indicate_letters = true;
	if (strlen(c) >= MAX_NAME_SIZE) //case length is not valid
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		indicate_len = false;
	}
	if (!validString_name(c)) //case character is not valid
	{
		indicate_letters = false;
		cout << "The name must contains only letters or spaces." << endl;
	}
	if (indicate_len && indicate_letters) //case name is valid= set name
	{
		this->city = new char[strlen(c) + 1];
		strncpy(city, c,strlen(c));
		city[strlen(c)] = '\0'; 
		return true;
	}
	else
		return false;
}

bool address_user::validString_name(const char *c) //function indicate a valid input country and city name
{
	int i = 0; //index run over the string

	while (c[i] != '\0') //run over the string name
	{
		if (!((c[i] <= 'a'&&c[i] >= 'z') || (c[i] <= 'A'&&c[i] >= 'Z') || c[i] == ' ')) //case character is not valid
			return false;
		i++;
	}
	return true;
}

bool address_user::setStreet(const char *s)
{
	bool indicate_len = true, indicate_letters = true;
	if (strlen(s) > MAX_NAME_SIZE) //case length is not valid
	{
		cout << "The name must contain " << (MAX_NAME_SIZE - 1) << " letters or less." << endl;
		indicate_len = false;
	}
	if (!validString_street(s)) //case character is not valid
	{
		cout << "The name must contains only letters or spaces." << endl;
		indicate_letters = false;
	}
	if (indicate_len && indicate_letters) //case name is valid= set name
	{
		this->street = new char[strlen(s) + 1];
		strncpy(street, s,strlen(s));
		street[strlen(s)] = '\0';
		return true;
	}
	else
		return false;
}

bool address_user::validString_street(const char *s) //function indicate a valid input street name
{
	int i = 0; //index run over the string

	while (s[i] != '\0') //run over the string name
	{
		if (!((s[i] <= 'a'&&s[i] >= 'z') || (s[i] <= 'A'&&s[i] >= 'Z') || s[i] == ' ' || (s[i] >= '0' && s[i] <= '9'))) //case charcter is not valid
			return false;
		i++;
	}
	return true;
}

char * address_user::getCountry() const
{
	return country;
}

char * address_user::getCity() const
{
	return city;
}

char * address_user::getStreet() const
{
	return street;
}

int address_user::getHouse_number() const
{
	return house_number;
}

void address_user::setHouse_number(int n)
{
	this->house_number = n;
}

address_user::address_user(const address_user&& other)// move c'tor
{

	this->country = other.country;
	country = nullptr;
	this->city = other.city;
	city = nullptr;
	this->street = other.street;
	street = nullptr;
	this->house_number = other.house_number;
}
