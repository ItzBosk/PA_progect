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

	Cart(bool fidelityCard);
	~Cart();

	void addItemSoldInPieces(ItemSoldInPieces newItem);
	void addItemSoldInWeight(ItemSoldInWeight newItem);
	void removeItemSoldInPieces(ItemSoldInPieces itemToRemove);
	void removeItemSoldInWeight(ItemSoldInWeight itemToRemove);
	void printCart();
};

class Supermarket {
public:
	vector<ItemSoldInPieces> supermarketItemSoldInPieces;
	vector<ItemSoldInWeight> supermarketItemSoldInWeight;
	const double fidelityDiscount = 0.85;
	const double sundayDiscount = 0.9;

	Supermarket(vector<ItemSoldInPieces> supermarketItemSoldInPieces,
			vector<ItemSoldInWeight> supermarketItemSoldInWeight);

	double getBill(Cart cart);
	void printItems();
	void addItemSoldInPieces(ItemSoldInPieces newItem);
	void addItemSoldInWeight(ItemSoldInWeight newItem);
	void removeItemSoldInPieces(ItemSoldInPieces itemToRemove);
	void removeItemSoldInWeight(ItemSoldInWeight itemToRemove);
};


#endif /* SUPERMARKET_H_ */
