#ifndef ITEM_H_
#define ITEM_H_

class Item {
private:
	double unitPrice;
public:
	char* name;
	Item();
	virtual ~Item();

	virtual double getUnitPrice();
	virtual void setUnitPrice(double unitPrice) final;
	// compareTo ??
	// orderListByPrice ??
	virtual char* toString();
	virtual void deleteItem();
};

class ItemSoldInPieces : public Item{
private:
	Item giftItem;  // da inizializzare
public:
	using Item::name;
	int numberOfPieces;
	ItemSoldInPieces();
	ItemSoldInPieces(char* name, double unitPrice, int numberOfPieces);
	virtual ~ItemSoldInPieces();

	void addGiftItem();
	bool equalsTo(ItemSoldInPieces item);
	virtual char* toString();
};

class ItemSoldInWeight : public Item{
private:
	Item giftItem;  // da inizializzare
public:
	using Item::name;
	double weight;
	ItemSoldInWeight();
	ItemSoldInWeight(char* name, double unitPrice, double weight);
	virtual ~ItemSoldInWeight();

	bool equalsTo(ItemSoldInWeight item);
	virtual char* toString();
};


#endif /* ITEM_H_ */
