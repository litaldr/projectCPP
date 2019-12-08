#ifndef __TRADE_SYSTEM_H
#define __TRADE_SYSTEM_H

#include "buyers.h"
#include "sellers.h"


#pragma warning (disable: 4996)
class trade_system
{
public:
	trade_system() = default;
	trade_system(const char *name);
	trade_system(const trade_system & other);
	~trade_system(); // defualt destructor because feedback name allocated static

	bool setName(const char* n);
	char * getName()  const;

	int getCountBuyer();
	void setCountBuyer(int i);

	int getCountSeller();
	void setCountSeller(int j);

	void addBuyer(buyers& buyer);
	bool addSeller(sellers &seller);
	bool compreName(char *comperdName);

	buyers ** reallocbuyers(buyers **oldBuyersArr, int size);
	sellers ** reallocSellers(sellers **oldSellersArr, int size);

	buyers** getBuyersArr();
	sellers** getSellersArr();

	/*מתודות להוסיף:
	3. הדפסת פרטי כל הקונים (לולאה שרצה על מערך הקונים ומדפיסה
	4. הדפסת פרטי כל המוכרים (לולאה שרצה על מערך המוכרים ומדפיסה*/
private:
	//attributes
	char *system_name;
	buyers** buyersArr;
	sellers** sellersArr;

	//index run over buyers and sellers arrays
	int count_buyers = 0, count_sellers = 0; //לחשוב לשנות למשתנים סטאטיים

};

#endif