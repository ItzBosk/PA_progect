#ifndef ITEM_H_
#define ITEM_H_

class Item {
private:
	double unitPrice;
public:
	char* name;
	Item();
	virtual ~Item();

	double getUnitPrice();
	virtual void setUnitPrice(double unitPrice) final;
	// compareTo ??
	// orderListByPrice ??
	virtual void toString() = 0;  // pure virtual function -> Item abstract class
};

class ItemSoldInPieces : public Item{
private:
	ItemSoldInPieces* giftItem;
public:
	int numberOfPieces;
	ItemSoldInPieces();
	ItemSoldInPieces(char* name, double unitPrice, int numberOfPieces);
	~ItemSoldInPieces();

	void addGiftItem();
	bool equalsTo(ItemSoldInPieces item);
	void toString();
};

class ItemSoldInWeight : public Item{
public:
	double weight;
	ItemSoldInWeight();
	ItemSoldInWeight(char* name, double unitPrice, double weight);
	~ItemSoldInWeight();

	bool equalsTo(ItemSoldInWeight item);
	void toString();
};


#endif /* ITEM_H_ */
