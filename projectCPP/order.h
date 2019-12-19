#ifndef  __ORDER_H
#define __ORDER_H

#include "sellers.h" // sellers include product

class order
{
public:

	order(double totalPrice=0);
	order(const order & myOrder);
	~order(); // destructor because arrays allocated dinamic


	// set & get functions
	Product** getProductArr()  const;
	sellers ** getsellersArr() const;

	int getCountProductInProductArr() const; // ����� �� ��' ������� ������
	int getCountSellersInSellersArr() const; // ����� �� ��' ������� ������

	void  setCountProductInProductArr(int n); // ����� �� ��' ������� ������
	void setCountSellersInSellersArr(int n); // ����� �� ��' ������� ������
	void setOrderPayedTrue();
	bool getOrderPayed()  const;
	void setTotalPrice(double n); // ����� �� ����� ����� �� ������
	double getTotalPrice();

public:
	void addProductToProductArr(Product &newProduct); // ����� ���� ����� ������� �� ������
	Product ** reallocProductArr(Product **oldProductArr, int size); // ����� ���� ������� ����� �����

	void addSellerToSellersArr(sellers &newSeller); // ����� ���� ����� ������� �� ������
	sellers ** reallocsellersArr(sellers **oldsellersArr, int size); // ����� ���� ������� ����� �����
	void showSellersByCurrOrder() const;
	bool checkIfSellerExists(const sellers *seller);
private:
	//attributes
	double totalPrice;
	Product** productArr;
	sellers **sellersArr;
	bool orderPayed;
	int CountProductInProductArr = 0; //������ ���� ���� ������� ������ ��� ������
	int CountSellersInSellersArr = 0; // ������ ���� ���� ������� ��� ���� ������ ������
};
#endif 