#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Item::getUnitPrice(){
	return unitPrice;
}

void Item::setUnitPrice(double unitPrice){
	this->unitPrice = unitPrice;
}

//ItemSoldInPieces::ItemSoldInPieces(){};

ItemSoldInPieces::ItemSoldInPieces(char *name, double unitPrice,
		int numberOfPieces) :
		numberOfPieces(numberOfPieces) {
	this->name = (char*) malloc(sizeof(char) * strlen(name));
	strcpy(this->name, name);
	this->Item::setUnitPrice(unitPrice);
	this->giftItem = NULL;
}

void ItemSoldInPieces::toString(){

	printf(ItemSoldInPieces::name + ", " + "prezzo/unità: " + Item::getUnitPrice + "€"
			+ + ", " + "pezzi: " + ItemSoldInPieces::numberOfPieces) ;
}

ItemSoldInWeight::ItemSoldInWeight(char *name, double unitPrice, double weight){
	this->name = (char*) malloc(sizeof(char) * strlen(name));
	strcpy(this->name, name);
	this->Item::setUnitPrice(unitPrice);
	this->weight = weight;
}

char* ItemSoldInWeight::toString(){
	return ItemSoldInWeight::name + ", " + "prezzo/unità: " + ItemSoldInWeight::unitPrice + "€"
			+ + ", " + "peso: " + ItemSoldInWeight::weight;
}


