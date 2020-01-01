#ifndef __BUYERANDSELLER_H
#define __BUYERANDSELLER_H

#include "trade_system.h"


class buyerAndSeller: public sellers, public buyers 
{
public:
	buyerAndSeller(const buyers &buyer, const sellers &seller);
	buyerAndSeller(char *user_name, char *password, const address_user & address);

	virtual ~buyerAndSeller();
};

#endif