#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include "Item.h"
#include "Supermarket.h"
#include <ctime> // bobodf
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
	if (sunday == 0) {
		for (unsigned int i = 0; i < cart.cartItemsSoldInPieces.size(); i++)
			result += cart.cartItemsSoldInPieces[i].getItemPrice() * sundayDiscount;
		for (unsigned int i = 0; i < cart.cartItemSoldInWeight.size(); i++)
			result += cart.cartItemSoldInWeight[i].getItemPrice() * sundayDiscount;
	}
	if(cart.fidelityCard)
		result *= fidelityDiscount;
	return result;
}


int main() {
	// creazione di vari item
	char det[] = "detersivo";
	char dent[] = "dentifricio";
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
//	conad.addItemSoldInPieces(dentifricio);
//	conad.removeItemSoldInPieces(dentifricio);
//	conad.printItems();

	// nuovo carrello
	Cart cartFidelity (true);
	Cart cartNotFidelity (false);

	// rimepio carrelli
	cartFidelity.addItemSoldInPieces(detersivo);
	cartFidelity.addItemSoldInWeight(cestoBanane);
	cartNotFidelity.addItemSoldInPieces(detersivo);
	cartNotFidelity.addItemSoldInWeight(cestoBanane);

	// stampo contenuto carrello
//	cartFidelity.printCart();
//	printf("-------------- rimuovo detersivo --------------\n");
//	cartFidelity.removeItemSoldInPieces(detersivo);
//	cartFidelity.printCart();

	// stampo conto carrello
//	printf("cliente fedele: %f\n", conad.getBill(cartFidelity));
//	printf("cliente non fedele: %f\n", conad.getBill(cartNotFidelity));

	// elimino prodotto
	delete[] &mele;


	return 0;
}



