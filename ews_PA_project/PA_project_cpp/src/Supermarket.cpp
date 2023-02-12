#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include "Item.h"
#include "Supermarket.h"
using namespace std;

Supermarket::Supermarket(vector<ItemSoldInPieces> supermarketItemSoldInPieces,
		vector<ItemSoldInWeight> supermarketItemSoldInWeight) {
	this->supermarketItemSoldInPieces = supermarketItemSoldInPieces;
	this->supermarketItemSoldInWeight = supermarketItemSoldInWeight;
}

void Supermarket::printItems() {
	printf("Prodotti venduti a pezzi:\n");
	for (int i = 0; i < supermarketItemSoldInPieces.size(); i++) {
		printf("%s\n", supermarketItemSoldInPieces[i].toString());
	}
	printf("Prodotti venduti a peso:\n");
	for (int i = 0; i < supermarketItemSoldInWeight.size(); i++) {
		printf("%s\n", supermarketItemSoldInWeight[i].toString());
	}
}

int main() {
	// creazione di vari item
	char det[] = "detersivo";
	char dent[] = "detersivo";
	char cb[] = "cestoBanane";
	char no[] = "noci";
	char me[] = "mele";
	ItemSoldInPieces detersivo(det, 2.32, 2);
	ItemSoldInPieces dentifricio(dent, 2.80, 3);
	ItemSoldInWeight cestoBanane(cb, 3.53, 0.5);
	ItemSoldInWeight noci(no, 8.90, 0.4);
	ItemSoldInWeight mele(me, 0.88, 0.8);
//	printf("%s\n", detersivo.toString());
//	printf("%s\n", dentifricio.toString());
//	printf("%s\n", cestoBanane.toString());
//	printf("%s\n", noci.toString());
//	printf("%s\n", mele.toString());

	vector<ItemSoldInPieces> supermarketItemSoldInPieces;
	supermarketItemSoldInPieces.push_back(detersivo);
	supermarketItemSoldInPieces.push_back(dentifricio);
	vector<ItemSoldInWeight> supermarketItemSoldInWeight;
	supermarketItemSoldInWeight.push_back(noci);
	supermarketItemSoldInWeight.push_back(mele);

	Supermarket conad(supermarketItemSoldInPieces, supermarketItemSoldInWeight);
//	conad.printItems();




	return 0;
}
