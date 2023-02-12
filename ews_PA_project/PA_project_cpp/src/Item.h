#ifndef ITEM_H_
#define ITEM_H_

class Item{
private:
	double unitPrice;
public:
	char* name;
	Item();
	virtual ~Item();

	double getUnitPrice();
	void setUnitPrice(double unitPrice);
	virtual char* toString() = 0;  // pure virtual function -> Item abstract class
	virtual double getItemPrice() = 0;
};

class ItemSoldInPieces : public Item{
public:
	int numberOfPieces;
	ItemSoldInPieces();
	ItemSoldInPieces(char* name, double unitPrice, int numberOfPieces);
	~ItemSoldInPieces();

	bool equalsTo(ItemSoldInPieces item);
	char* toString();
	double getItemPrice();
};

class ItemSoldInWeight : public Item{
public:
	double weight;
	ItemSoldInWeight();
	ItemSoldInWeight(char* name, double unitPrice, double weight);
	~ItemSoldInWeight();

	bool equalsTo(ItemSoldInWeight item);
	char* toString();
	double getItemPrice();
};


#endif /* ITEM_H_ */
