package progettoJava;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Date;

class Cart {
	ArrayList<Item> cartItems;
	boolean fidelityCard;

	public Cart(boolean fidalityCard) {
		this.cartItems = new ArrayList<>();
		this.fidelityCard = fidalityCard;
	}

	// bounded generics
	public <T extends Item> void addItem(T newItem) {
		this.cartItems.add(newItem);
	}
	
	// varargs
	public  <T extends Item> void addMultipleItems(T...newItems) {
		for(T item : newItems)
			this.cartItems.add(item);
	}
}

class ShoppingVisitor implements Visitor {
	final double sundayDiscount = 0.9;
	
	public static int getDayNumber() {
		Date date = new Date();
	    return date.getDay();
	}
	
	@Override
	public double visit(ItemSoldInPieces item) {
		if(getDayNumber() == 7)
			return sundayDiscount * item.numberOfPieces * item.getUnitPrice();
		return item.numberOfPieces * item.getUnitPrice();
	}

	@Override
	public double visit(ItemSoldInWeight item) {
		if(getDayNumber() == 7)
			return sundayDiscount * item.weight * item.getUnitPrice();
		return item.weight * item.getUnitPrice();
	}

}

public class Supermarket {
	ArrayList<Item> supermarketItems;
	final static double fidelityDiscount = 0.85;   // final variable, non può essere cambiata
	// static variable, inizializzata solo ad inizio esecuzione, non legata al singolo oggetto
	
	// singleton (costruttore private, utile se costruzione oggetto onerosa)
	private Supermarket() {}
	private Supermarket(ArrayList<Item> suermarketItems) {
		this.supermarketItems = suermarketItems;
	}
	// creo oggetto solo se richiesto esplicitamente
	static private Supermarket supermarket = null;

	static public Supermarket newSupermarket(ArrayList<Item> suermarketItems) {
		// return new Supermarket() non andrebbe bene perché restituirebbe ogni volta un
		// supermarket diverso
		if (supermarket == null)
			supermarket = new Supermarket(suermarketItems);
		return supermarket;
	}
	
	public static String getBill(Cart cart) {
		double result = 0;
		ShoppingVisitor shoppingVisitor = new ShoppingVisitor();
		for(Item item : cart.cartItems)
			result += item.accept(shoppingVisitor);
		if(cart.fidelityCard)
			result *= fidelityDiscount;
		DecimalFormat df = new DecimalFormat("0.00");
		return df.format(result);
	}

	public static void main(String[] args) {
		// creazione di vari item
		ItemSoldInPieces detersivo = new ItemSoldInPieces("detersivo", 2.30, 2);
		ItemSoldInWeight cestoBanane = new ItemSoldInWeight("cesto banane", 3.50, 0.5);

		// lista prodotti supermercato
		ArrayList<Item> supermarketItemsList = new ArrayList<>();
		supermarketItemsList.add(detersivo);
		supermarketItemsList.add(cestoBanane);

		// Supermarket supermarket = new Supermarket(); // non si può
		Supermarket supermarket = newSupermarket(supermarketItemsList); // creazione solo su richiesta
		
		// nuovo carrello
		Cart cartFidelity = new Cart(true);
		Cart cartNotFidelity = new Cart(false);
		
		// rimepio carrello
		cartFidelity.addItem(detersivo);
		cartFidelity.addItem(cestoBanane);
		
		cartNotFidelity.addItem(detersivo);
		cartNotFidelity.addItem(cestoBanane);
		
		System.out.println("cliente fedele: " + getBill(cartFidelity));
		System.out.println("cliente non fedele: " + getBill(cartFidelity));
		
		
	
	
	}
}





