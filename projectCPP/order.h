#ifndef  __ORDER_H
#define __ORDER_H

#include "sellers.h" // sellers include product

class order
{
public:

	order();// we don't allowed to create a new product without the details in the constructor below 
	order(const order & myOrder);
	~order(); // destructor because arrays allocated dinamic


	// set & get functions
	Product** getProductArr()  const;
	sellers ** getsellersArr() const;

	int getCountProductInProductArr() const; // ����� �� ��' ������� ������
	int getCountSellersInSellersArr() const; // ����� �� ��' ������� ������

	void  setCountProductInProductArr(int n); // ����� �� ��' ������� ������
	void setCountSellersInSellersArr(int n); // ����� �� ��' ������� ������

	void setTotalPrice(double n); // ����� �� ����� ����� �� ������
	double getTotalPrice();

public:
	void addProductToProductArr(Product &newProduct); // ����� ���� ����� ������� �� ������
	Product ** reallocProductArr(Product **oldProductArr, int size); // ����� ���� ������� ����� �����

	void addSellerToSellersArr(sellers &newSeller); // ����� ���� ����� ������� �� ������
	sellers ** reallocsellersArr(sellers **oldsellersArr, int size); // ����� ���� ������� ����� �����

	bool checkIfSellerExists(const sellers *seller);
private:
	//attributes
	double totalPrice;
	Product** productArr;
	sellers **sellersArr;

	int CountProductInProductArr = 0; //������ ���� ���� ������� ������ ��� ������
	int CountSellersInSellersArr = 0; // ������ ���� ���� ������� ��� ���� ������ ������




};
#endif 