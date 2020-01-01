#include "buyerAndSeller.h"



buyerAndSeller::buyerAndSeller(const buyers &buyer, const sellers &seller) : user(buyer.getName(), buyer.getPassword(), buyer.getAddress()), buyers(buyer),
sellers(seller) { }

buyerAndSeller::buyerAndSeller(char *user_name, char *password, const address_user & address) : user(user_name, password, address), 
buyers(user_name, password, address), sellers(user_name, password, address)
{
	
}
buyerAndSeller::~buyerAndSeller()
{

}
