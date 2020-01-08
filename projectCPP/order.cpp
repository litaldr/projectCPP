#include "order.h" 

order::order(double totalPrice) // constructor
{
	this->productArr = nullptr;
	this->sellersArr = nullptr;
	this->CountProductInProductArr = 0;
	this->CountSellersInSellersArr = 0;
	this->orderPayed = false;
	this->totalPrice = totalPrice;
}

order::order(const order & myOrder) //copy constructor 
{
	int sizeProducts = myOrder.CountProductInProductArr;
	this->productArr = new Product*[sizeProducts];
	for (int i = 0; i < sizeProducts; i++)
	{
		this->productArr[i] = new Product(*(myOrder.getProductArr()[i]));
	}
	int sizeSellers = myOrder.CountSellersInSellersArr;
	this->sellersArr = new seller*[sizeSellers];
	for (int i = 0; i < sizeSellers; i++)
	{
		this->sellersArr[i] = new seller(*(myOrder.getsellersArr()[i]));
	}

	this->totalPrice = myOrder.totalPrice;
	this->CountProductInProductArr = sizeProducts;
	this->CountSellersInSellersArr = sizeSellers;
}

order::~order() // destructor
{
	for (int i = 0; i < CountProductInProductArr; i++)
	{
		productArr[i]=nullptr;
	}
	delete[]productArr;
	for (int i = 0; i < CountSellersInSellersArr; i++)
	{
		sellersArr[i]=nullptr;
	}
	delete[]sellersArr;
}

//----------------------set & get functions------------------------------//

 Product** order::getProductArr()  const
{
	return productArr;
}

 seller ** order::getsellersArr() const
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

double order::getTotalPrice() const
{
	return totalPrice;
}

bool order::getOrderPayed()  const
{
	return orderPayed;
}

void  order::setCountProductInProductArr(int n) // set number of product to pay for
{
	this->CountProductInProductArr = n;
}

void  order::setCountSellersInSellersArr(int n) // set number of sellers which buyer will buy a product from
{
	this->CountSellersInSellersArr = n;
}

void order::setTotalPrice(double n) 
{
	this->totalPrice += n;
}

void  order::setOrderPayedTrue()
{
	this->orderPayed = true;
}

//----------------------adding order to buyer functions------------------------------//

void order::addProductToProductArr(Product &newProduct)// function add product to products array in order object of buyer
{
	int i = getCountProductInProductArr() - 1;
	if (getCountProductInProductArr() == 0) //if it is the first product
		this->productArr = new Product*;
	else
	{
		productArr = reallocProductArr(productArr, i + 1); //if it isn't the first product
	}
	i++;
	productArr[i] = new Product(newProduct);// constructor

	setCountProductInProductArr(i + 1); // increase counter of product in product array
}

 Product ** order::reallocProductArr(Product **oldProductArr, int size) // function increase product array by one for the new product buyer wants to buy
{
	Product **newProductArr = new Product*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newProductArr[i] = oldProductArr[i];
	}
	delete[]oldProductArr;
	return newProductArr;
}

void order::addSellerToSellersArr(seller &newSeller) // function add seller to sellers array in order object of buayer
{
	if (!checkIfSellerExists(&newSeller))
	{
		int i = getCountSellersInSellersArr() - 1;
		if (getCountSellersInSellersArr() == 0) //if it is the first seller
			this->sellersArr = new seller*;
		else
		{
			sellersArr = reallocsellersArr(sellersArr, i + 1);//if it isn't the first seller
		}
		i++;
		sellersArr[i] = new seller(newSeller);// constructor

		setCountSellersInSellersArr(i + 1); // increase counter of seller in sellers array
	}
}

seller ** order::reallocsellersArr(seller **oldsellersArr, int size) // function increase seller array by one, for the new seller that the buyer wants to buy from 
{
	seller **newSellersArr = new seller*[size + 1];
	for (int i = 0; i <= size; i++)
	{
		newSellersArr[i] = oldsellersArr[i];
	}
	delete[]oldsellersArr;
	return newSellersArr;
}

bool order::checkIfSellerExists(const seller *seller) // function checks that seller is adding only one time to sellers array of order to prevent duplicates
{
	int i;
	for (i = 0; i < CountSellersInSellersArr; i++)
	{
		if (!strcmp(seller->getName(), sellersArr[i]->getName()))//as long as the strings is not equal we will return true
			return true;// if we will get the same name it means we already have this seller in our order sellers arr 
	}
	return false;
}

void order::showSellersByCurrOrder() const // print sellers of specific order
{
	int i;
	cout << " This is the sellers that are associated to this order" << endl;
	for (i = 0; i < CountSellersInSellersArr; i++)
	{
		cout << "Seller number " << i + 1 <<" :"<< endl;
		cout << sellersArr[i]->getName() << endl;
	}
}

ostream & operator<<(ostream & os, const order & theOrder)
{
	for (int i = 0; i < theOrder.getCountProductInProductArr(); i++)
	{
		os << "product " <<i + 1 << ":"<< endl;
		os << *theOrder.getProductArr()[i] << endl;
	}
	os << "the total price is:" << theOrder.getTotalPrice() << endl;
	return os;
}
