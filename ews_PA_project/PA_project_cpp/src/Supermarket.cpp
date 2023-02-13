#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include "Item.h"
#include "Supermarket.h"
#include <ctime>
using namespace std;

Cart::Cart(bool fidelityCard){
	vector<ItemSoldInWeight> cartItemsSoldInPieces;
	vector<ItemSoldInWeight> cartItemsSoldInWeight;
	this->fidelityCard = fidelityCard;
}

Cart::~Cart(){}

void Cart::addItemSoldInPieces(ItemSoldInPieces newItem){
	cartItemsSoldInPieces.push_back(newItem);
}

void Cart::addItemSoldInWeight(ItemSoldInWeight newItem){
	cartItemSoldInWeight.push_back(newItem);
}

void Cart::removeItemSoldInPieces(ItemSoldInPieces itemToRemove) {
	int position = 0;
	vector<ItemSoldInPieces>::iterator it;
	for (unsigned int i = 0; i < cartItemsSoldInPieces.size(); i++) {
		if (cartItemsSoldInPieces[i].equalsTo(itemToRemove)) {
			position = i;
			break;
		}
	}
	it = cartItemsSoldInPieces.begin() + position;
	cartItemsSoldInPieces.erase(it);
}

void Cart::removeItemSoldInWeight(ItemSoldInWeight itemToRemove) {
	int position = 0;
	vector<ItemSoldInWeight>::iterator it;
	for (unsigned int i = 0; i < cartItemSoldInWeight.size(); i++) {
		if (cartItemSoldInWeight[i].equalsTo(itemToRemove)) {
			position = i;
			break;
		}
	}
	it = cartItemSoldInWeight.begin() + position;
	cartItemSoldInWeight.erase(it);
}

void Cart::printCart() {
	printf("Prodotti nel carrello:\n");
	printf("venduti a pezzi:\n");
	for (unsigned int i = 0; i < cartItemsSoldInPieces.size(); i++) {
		printf("%s\n", cartItemsSoldInPieces[i].toString());
	}
	printf("venduti a peso:\n");
	for (unsigned int i = 0; i < cartItemSoldInWeight.size(); i++) {
		printf("%s\n", cartItemSoldInWeight[i].toString());
	}
}


Supermarket::Supermarket(vector<ItemSoldInPieces> supermarketItemSoldInPieces,
		vector<ItemSoldInWeight> supermarketItemSoldInWeight) {
	this->supermarketItemSoldInPieces = supermarketItemSoldInPieces;
	this->supermarketItemSoldInWeight = supermarketItemSoldInWeight;
}

void Supermarket::printItems() {
	printf("Prodotti venduti a pezzi:\n");
	for (unsigned int i = 0; i < supermarketItemSoldInPieces.size(); i++) {
		printf("%s\n", supermarketItemSoldInPieces[i].toString());
	}
	printf("Prodotti venduti a peso:\n");
	for (unsigned int i = 0; i < supermarketItemSoldInWeight.size(); i++) {
		printf("%s\n", supermarketItemSoldInWeight[i].toString());
	}
}

void Supermarket::addItemSoldInPieces(ItemSoldInPieces newItem){
	supermarketItemSoldInPieces.push_back(newItem);
}
void Supermarket::addItemSoldInWeight(ItemSoldInWeight newItem){
	supermarketItemSoldInWeight.push_back(newItem);
}

void Supermarket::removeItemSoldInPieces(ItemSoldInPieces itemToRemove) {
	int position = 0;
	vector<ItemSoldInPieces>::iterator it;
	for (unsigned int i = 0; i < supermarketItemSoldInPieces.size(); i++) {
		if(supermarketItemSoldInPieces[i].equalsTo(itemToRemove)){
			position = i;
			break;
		}
	}
	it = supermarketItemSoldInPieces.begin() + position;
	supermarketItemSoldInPieces.erase(it);
}

void Supermarket::removeItemSoldInWeight(ItemSoldInWeight itemToRemove) {
	int position = 0;
	vector<ItemSoldInWeight>::iterator it;
	for (unsigned int i = 0; i < supermarketItemSoldInWeight.size(); i++) {
		if(supermarketItemSoldInWeight[i].equalsTo(itemToRemove)){
			position = i;
			break;
		}
	}
	it = supermarketItemSoldInWeight.begin() + position;
	supermarketItemSoldInWeight.erase(it);
}

double Supermarket::getBill(Cart cart) {
	double result = 0;
	time_t now = time(0);  // ora corrente
	tm *localTime = localtime(&now);   // conversione a calendario
	int sunday = localTime->tm_wday;   // giorni passati dall'ultima domenica
	for (unsigned int i = 0; i < cart.cartItemsSoldInPieces.size(); i++)
		result += cart.cartItemsSoldInPieces[i].getItemPrice();
	for (unsigned int i = 0; i < cart.cartItemSoldInWeight.size(); i++)
		result += cart.cartItemSoldInWeight[i].getItemPrice();
	if (sunday == 0)
		result *= fidelityDiscount;
	if(cart.fidelityCard)
		result *= fidelityDiscount;
	return result;
}


int main() {
	// creazione di vari prodotti
	char det[] = "detersivo";
	char dent[] = "dentifricio";
	char db[] = "dopobarba";
	char cb[] = "cesto banane";
	char no[] = "noci";
	char me[] = "mele";
	ItemSoldInPieces detersivo(det, 2.32, 2);
	ItemSoldInPieces dentifricio(dent, 2.80, 3);
	ItemSoldInPieces dopoBarba(db, 5.00, 1);
	ItemSoldInWeight cestoBanane(cb, 3.53, 0.5);
	ItemSoldInWeight noci(no, 8.90, 0.4);
	ItemSoldInWeight mele(me, 0.88, 0.8);
	printf("\n---------------- Prodotti creati ----------------\n");
	printf("%s\n", detersivo.toString());
	printf("%s\n", dentifricio.toString());
	printf("%s\n", dopoBarba.toString());
	printf("%s\n", cestoBanane.toString());
	printf("%s\n", noci.toString());
	printf("%s\n", mele.toString());

	printf("---------------- Creo liste di prodotti ----------------\n");
	vector<ItemSoldInPieces> supermarketItemSoldInPieces;
	supermarketItemSoldInPieces.push_back(detersivo);
	supermarketItemSoldInPieces.push_back(dentifricio);
	vector<ItemSoldInWeight> supermarketItemSoldInWeight;
	supermarketItemSoldInWeight.push_back(noci);
	supermarketItemSoldInWeight.push_back(mele);

	printf("---------------- creo supermarket ----------------\n");
	Supermarket conad(supermarketItemSoldInPieces, supermarketItemSoldInWeight);
	printf("---------------- aggiungo dopobarba----------------\n");
	conad.addItemSoldInPieces(dopoBarba);
	conad.printItems();
	printf("\n---------------- rimuovo dopobarba ----------------\n");
	conad.removeItemSoldInPieces(dopoBarba);
	conad.printItems();

	printf("\n---------------- creo due carrelli, con e senza carta fedeltà ----------------\n");
	Cart cartFidelity (true);
	Cart cartNotFidelity (false);

	printf("---------------- riempio i due carrelli ----------------\n");
	cartFidelity.addItemSoldInPieces(detersivo);
	cartFidelity.addItemSoldInPieces(dentifricio);
	cartFidelity.addItemSoldInWeight(cestoBanane);
	cartFidelity.addItemSoldInWeight(noci);
	cartNotFidelity.addItemSoldInPieces(dentifricio);
	cartNotFidelity.addItemSoldInWeight(cestoBanane);
	cartNotFidelity.addItemSoldInWeight(noci);

	printf("---------------- stampo prodotti nel carrello ----------------\n");
	cartFidelity.printCart();
	printf("\n---------------- rimuovo detersivo ----------------\n");
	cartFidelity.removeItemSoldInPieces(detersivo);
	cartFidelity.printCart();

	printf("\n---------------- stampo conto carrelli ----------------\n");
	printf("cliente fedele: %.2f€\n", conad.getBill(cartFidelity));
	printf("cliente non fedele: %.2f€\n", conad.getBill(cartNotFidelity));


	return 0;
}



