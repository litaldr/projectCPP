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

	int getCountProductInProductArr() const; // מחזיר את מס' המוצרים בהזמנה
	int getCountSellersInSellersArr() const; // מחזיר את מס' המוכרים בהזמנה

	void  setCountProductInProductArr(int n); // מעדכן את מס' המוצרים בהזמנה
	void setCountSellersInSellersArr(int n); // מעדכן את מס' המוכרים בהזמנה

	void setTotalPrice(double n); // מעדכן את הסכום הסופי של ההזמנה
	double getTotalPrice();

public:
	void addProductToProductArr(Product &newProduct); // הוספת מוצר למערך המוצרים של ההזמנה
	Product ** reallocProductArr(Product **oldProductArr, int size); // הגדלת מערך המוצרים במידת הצורך

	void addSellerToSellersArr(sellers &newSeller); // הוספת מוכר למערך המוכרים של ההזמנה
	sellers ** reallocsellersArr(sellers **oldsellersArr, int size); // הגדלת מערך המוכרים במידת הצורך

	bool checkIfSellerExists(const sellers *seller);
private:
	//attributes
	double totalPrice;
	Product** productArr;
	sellers **sellersArr;

	int CountProductInProductArr = 0; //אינדקס עבור מספר המוצרים לרכישה שיש בהזמנה
	int CountSellersInSellersArr = 0; // אינדקס עבור מספר המוכרים שיש עבור ההזמנה שתתבצע




};
#endif 