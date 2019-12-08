#ifndef __BUYERS_H
#define __BUYERS_H

#include "address_user.h"

class buyers
{

public:
	// define length valid for user details


	buyers() = delete; //constructor
	buyers(char *user_name, char *password, const address_user & address); //constructor
	buyers(const buyers &other);
	~buyers(); // defualt destructor because names strings are allocated static

    // set & get function
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getName()          const;
	char * getPassword()      const;
	address_user getAddress()      const;
private:
	//attributes
	char *user_name;
	char *password;
	address_user address;

	/*
	Product ***wishListArr; //���� �����: ������� �� ������� ������� �������� �� ������� ������
	Product ****buyProdustsArr // ���� ������ ������� ��wishlist ����� ����� ���� ������ �����
	purchase_user purchase; //������� �����\�����: ���� �� ����� �����, ���� ������ ���� ����� ���� ������ ����� ��"� ������ 
	purchase_user **purchase_userArr; // ���� ��������� ������ �� �����- ����� ��� ������� �����- ���� �� ���� ��������� ������ ������ ���� ���� ���� ����� ��� ���� ����
	*/
};


#endif

