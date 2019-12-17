#include "order.h"

//order::order(Product ** productArr = NULL, sellers **sellersArr = NULL, double totalPrice = 0)
// {}//constructor 

order::order()
{
	this->productArr = nullptr;
	this->sellersArr = nullptr;
	this->CountProductInProductArr = 0;
	this->CountSellersInSellersArr = 0;
	this->orderPayed = false;
}


order::order(const order & myOrder) //copy c'tor 
{
	int size = myOrder.getCountProductInProductArr();
	this->productArr = new Product*[size];
	for (int i = 0; i < size; i++)
	{
		this->productArr[i] = new Product(*(myOrder.getProductArr()[i]));
	}
	size = myOrder.getCountSellersInSellersArr();
	this->sellersArr = new sellers*[size];
	for (int i = 0; i < size; i++)
	{
		this->sellersArr[i] = new sellers(*(myOrder.getsellersArr()[i]));
	}
	this->totalPrice = myOrder.totalPrice;
	this->CountProductInProductArr = myOrder.CountProductInProductArr;
	this->CountSellersInSellersArr = myOrder.CountSellersInSellersArr;
}
order::~order() // destructor because arrays allocated dinamic
{
	delete[]productArr;
	delete[]sellersArr;
}


Product** order::getProductArr()  const
{
	return productArr;
}
sellers ** order::getsellersArr() const
{
	return sellersArr;

}
int order::getCountProductInProductArr() const
{
	return CountProductInProductArr;
}
int order::getCountSellersInSellersArr() const
{
	return CountSellersInSellersArr;
}

void  order::setCountProductInProductArr(int n) // set number of product to pay for
{
	this->CountProductInProductArr = n;
}

void  order::setCountSellersInSellersArr(int n) // set number of sellers which buyer will buy a product from
{
	this->CountSellersInSellersArr = n;
}

void order::setTotalPrice(double n) //סכימה של מחירי כל המוצרים שבהזמנה
{
	this->totalPrice = n;
}
double order::getTotalPrice()
{
	return totalPrice;
}
void  order::setOrderPayedTrue()
{
	this->orderPayed = true;
}
bool order::getOrderPayed()  const
{
	return orderPayed;
}
void order::addProductToProductArr(Product &newProduct)//הוספת מוצר למערך המוצרים בהזמנה
{
	int i = getCountProductInProductArr() - 1;
	if (getCountProductInProductArr() == 0)
		this->productArr = new Product*;//if it is the first product
	else
	{
		productArr = reallocProductArr(productArr, i + 1);//if it isn't the first product
	}
	i++;
	productArr[i] = new Product(newProduct);// c'tor product only

	setCountProductInProductArr(i + 1);
}
Product ** order::reallocProductArr(Product **oldProductArr, int size) // הגדלת מערך המוצרים בהזמנה
{
	Product **newProductArr = new Product*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newProductArr[i] = oldProductArr[i];
		//delete[]oldProductArr[i]
	}
	delete[]oldProductArr;
	return newProductArr;
}

void order::addSellerToSellersArr(sellers &newSeller) // הוספת מוכר למערך המוכרים בהזמנה
{
	int i = getCountSellersInSellersArr() - 1;
	if (getCountSellersInSellersArr() == 0)
		this->sellersArr = new sellers*;//if it is the first seller
	else
	{
		sellersArr = reallocsellersArr(sellersArr, i + 1);//if it isn't the first seller
	}
	i++;
	sellersArr[i] = new sellers(newSeller);// c'tor seller only

	setCountSellersInSellersArr(i + 1);

}
sellers ** order::reallocsellersArr(sellers **oldsellersArr, int size) // הגדלת מערך המוכרים בהזמנה
{
	sellers **newSellersArr = new sellers*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newSellersArr[i] = oldsellersArr[i];
		//delete[]oldProductArr[i]
	}
	delete[]oldsellersArr;
	return newSellersArr;
}

bool order::checkIfSellerExists(const sellers *seller)
{
	int i;
	for (i = 0; i < CountSellersInSellersArr; i++)
	{
		if (!strcmp(seller->getName(), sellersArr[i]->getName()))//as long as the strings is not equal we will return true
			return false;// if we will get the same name it means we already have this seller in our order sellers arr. 
	}
	return true;
}
void order::showSellersByCurrOrder() const
{
	int i;
	cout << " this is the sellers that are associated to this order" << endl;
	for (i = 0; i < CountSellersInSellersArr; i++)
	{
		cout << "seller number " << i + 1 <<" :"<< endl;
		cout << sellersArr[i]->getName() << endl;
	}
}