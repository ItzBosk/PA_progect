#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_
#include <vector>
#include "Item.h"
using namespace std;

class Cart{
public:
	vector<Item> cartItems;
	bool fidelityCard;

	Cart(bool fidalityCard);
	~Cart();

//	void addItem(T newItem);
//	void removeItem(T itemToRemove);
	void printCart();
};

class Supermarket{
public:
	vector<Item> supermarketItems;
	static const double fidelityDiscount = 0.85;

	Supermarket(vector<Item> suermarketItems) {
			supermarketItems = suermarketItems;
	}

	static char* getBill(Cart cart);
	static void printItems(vector<Item> itemsList);
//	void removeItem(T itemToRemove);

};


#endif /* SUPERMARKET_H_ */
