#include "Item.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

Item::Item(){}
Item::~Item(){}

double Item::getUnitPrice(){
	return unitPrice;
}

void Item::setUnitPrice(double unitPrice){
	this->unitPrice = unitPrice;
}

ItemSoldInPieces::ItemSoldInPieces(){}
ItemSoldInPieces::ItemSoldInPieces(char *name, double unitPrice, int numberOfPieces) {
	this->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';
	this->Item::setUnitPrice(unitPrice);
	this->numberOfPieces = numberOfPieces;
}

ItemSoldInPieces::~ItemSoldInPieces(){}

bool ItemSoldInPieces::equalsTo(ItemSoldInPieces item) {
	if (name == item.name && numberOfPieces == item.numberOfPieces
			&& getUnitPrice() == item.getUnitPrice())
		return true;
	return false;
}

char* ItemSoldInPieces::toString() {
	char *result = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(result, name);
	result[strlen(name)] = '\0';
	return result;
}

double ItemSoldInPieces::getItemPrice(){
	return getUnitPrice() * numberOfPieces;
}

ItemSoldInWeight::ItemSoldInWeight(){}
ItemSoldInWeight::ItemSoldInWeight(char *name, double unitPrice, double weight){
	this->name = (char*) malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(this->name, name);
	this->name[strlen(name)] = '\0';
	this->Item::setUnitPrice(unitPrice);
	this->weight = weight;
}

ItemSoldInWeight::~ItemSoldInWeight(){}

bool ItemSoldInWeight::equalsTo(ItemSoldInWeight item) {
	if (name == item.name && weight == item.weight
			&& getUnitPrice() == item.getUnitPrice())
		return true;
	return false;
}

char* ItemSoldInWeight::toString() {
	char *result = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(result, name);
	result[strlen(name)] = '\0';
	return result;
}

double ItemSoldInWeight::getItemPrice(){
	return getUnitPrice() * weight;
}


