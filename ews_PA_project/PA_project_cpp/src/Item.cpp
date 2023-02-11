#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Item::setUnitPrice(double unitPrice){
	this->unitPrice = unitPrice;
}

ItemSoldInPieces::ItemSoldInPieces (char* name,
		double unitPrice, int numberOfPieces){
	this->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy(this->name, name);
	this->setUnitPrice(unitPrice);
	this->numberOfPieces = numberOfPieces;
}

ItemSoldInWeight::ItemSoldInWeight (char* name,
		double unitPrice, double weight){
	this->name = (char*)malloc(sizeof(char) * strlen(name));
	strcpy(this->name, name);
	this->setUnitPrice(unitPrice);
	this->weight = weight;
}
