#include "buyerAndSeller.h"



buyerAndSeller::buyerAndSeller(const buyer &buyer, const seller &seller) : user(buyer.getName(), buyer.getPassword(), buyer.getAddress()), buyer(buyer),
seller(seller) { }

buyerAndSeller::buyerAndSeller(char *user_name, char *password, const address_user & address) :
	user(user_name, password, address), buyer(user_name, password, address), seller(user_name, password, address) {}

