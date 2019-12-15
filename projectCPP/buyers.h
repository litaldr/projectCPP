#ifndef __BUYERS_H
#define __BUYERS_H

#include "address_user.h"
#include "Product.h"
#include "wishList.h"
class buyers
{

public:
	// define length valid for user details


	buyers() = delete; //constructor
					   //buyers(char *user_name, char *password, const address_user & address); //constructor
	buyers(char *user_name, char *password, const address_user & address, wishList **wishListArr = nullptr); //constructor

	buyers(const buyers &other);
	~buyers(); // defualt destructor because names strings are allocated static

			   // set & get function
	bool setPassword(const char* p);
	bool setName(const char* n);
	char * getName()          const;
	char * getPassword()      const;
	address_user getAddress()      const;

	void addProductToWishlist(Product * newProduct);
	int getCountProductInWishList() const;
	wishList **getWishListArr() const;
	void  setCountProductInWishList(int n);
	wishList **reallocWishList(wishList **oldWishListArr, int size);

private:
	//attributes
	char *user_name;
	char *password;
	address_user address;


	wishList **WishListArr; //òâìú ÷ðéåú: îöáéòéí òì îöáéòéí ìîåöøéí îäîòøëéí ùì äîåëøéí áîòøëú
	int CountProductInWishList = 0;
	/*
	Product **buyProdustsArr // îòøê ùîöáéò ìîåöøéí îäwishlist àåúí ä÷åðä áàîú îúëååï ìøëåù àáì ääöáòä îúáöòú éùéøåú ìîåöø åìà ãøê wishlist
	purchase_user purchase; //àåáéé÷è äæîðä\øëéùä: îëéì àú äôøèé ä÷åðä, îòøê îåëøéí ùîäí ä÷åðä øåëù îåöøéí åîçéø ñä"ë ìøëéùä
	purchase_user **purchase_userArr; // îòøê äéñèåøééú äæîðåú ùì ä÷åðä- îöáéò ìëì äøëéùåú ùðòùå- îòøê æä ðåúï àéðãé÷öéä ìäåñôú äôéãá÷ òáåø îåëø ùàëï ä÷åðä ÷ðä îîðå îåöø
	*/
};


#endif


#endif

