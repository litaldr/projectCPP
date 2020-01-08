#ifndef __BUYERANDSELLER_H
#define __BUYERANDSELLER_H

#include "trade_system.h"


class buyerAndSeller: public seller, public buyer 
{
public:
	buyerAndSeller(const buyer &buyer, const seller &seller);
	buyerAndSeller(char *user_name, char *password, const address_user & address);
	virtual void toOs(ostream& os) const override;
};

#endif 