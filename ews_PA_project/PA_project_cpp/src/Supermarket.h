#ifndef SUPERMARKET_H_
#define SUPERMARKET_H_
#include <vector>
#include "Item.h"
using namespace std;

class Cart{
public:
	vector<ItemSoldInPieces> cartItemsSoldInPieces;
	vector<ItemSoldInWeight> cartItemSoldInWeight;
	bool fidelityCard;

	Cart(bool fidalityCard);
	~Cart();

//	void addItem(T newItem);
//	void removeItem(T itemToRemove);
	void printCart();
};

class Supermarket {
public:
	vector<ItemSoldInPieces> supermarketItemSoldInPieces;
	vector<ItemSoldInWeight> supermarketItemSoldInWeight;
	const double fidelityDiscount = 0.85;

	Supermarket(vector<ItemSoldInPieces> supermarketItemSoldInPieces,
			vector<ItemSoldInWeight> supermarketItemSoldInWeight);

	static char* getBill(Cart cart);
	void printItems();
//	void removeItem(T itemToRemove);

};


#endif /* SUPERMARKET_H_ */
