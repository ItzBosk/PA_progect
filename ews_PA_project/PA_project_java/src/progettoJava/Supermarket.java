package progettoJava;

import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

class Cart {
	ArrayList<Item> cartItems;
	boolean fidelityCard;

	public Cart(boolean fidalityCard) {
		this.cartItems = new ArrayList<>();
		this.fidelityCard = fidalityCard;
	}
	
	// bounded generics + varargs
	public <T extends Item> void addItems(T...newItems) {
		for(T item : newItems)
			this.cartItems.add(item);
	}
	
	public <T extends Item> void removeItem(T itemToRemove) {
		this.cartItems.remove(itemToRemove);
		System.out.println(itemToRemove.name + " rimosso");
	}
	
	public void printCart() {
		System.out.println("Contenuto carrello:");
		Supermarket.printItems(this.cartItems);
	}
}

// final class -> non può essere estesa
final class ShoppingVisitor implements Visitor {
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

//class ShoppingVisitorDerived extends ShoppingVisitor{}   // non posso estendere

public class Supermarket {
	ArrayList<Item> supermarketItems;
	final static double fidelityDiscount = 0.85;   // final variable, non può essere cambiata
	// static variable, inizializzata solo ad inizio esecuzione, non legata al singolo oggetto
	
	// singleton (costruttore private, utile se costruzione oggetto onerosa)
	private Supermarket() {}
	private Supermarket(ArrayList<Item> suermarketItems) {
		this.supermarketItems = suermarketItems;
	}
	static private Supermarket supermarket = null;   // creo oggetto solo se richiesto esplicitamente

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
	
	// wildcard
	public static void printItems(List<? extends Item> itemsList) {
		for(int i = 0; i < itemsList.size(); i++)
			System.out.println(itemsList.get(i).toString());
	}
	
	public static <T> void printArrayItems(T[] itemsList) {
		System.out.println("Stampo prodotti nell'array:");
		for(int i = 0; i < itemsList.length; i++)
			System.out.println(itemsList[i].toString());
	}
	
	public <T extends Item> void removeItem(T itemToRemove) {
		this.supermarketItems.remove(itemToRemove);
		System.out.println(itemToRemove.name + " rimosso");
	}
	
	public static void main(String[] args) throws Throwable {
		// creazione di vari item
		ItemSoldInPieces detersivo = new ItemSoldInPieces("detersivo", 2.32, 2);
		ItemSoldInPieces dentifricio = new ItemSoldInPieces("dentifricio", 2.80, 3);
		ItemSoldInWeight cestoBanane = new ItemSoldInWeight("cesto banane", 3.53, 0.5);
		ItemSoldInWeight noci = new ItemSoldInWeight("noci", 8.90, 0.4);
		ItemSoldInWeight mele = new ItemSoldInWeight("mele", 0.88, 0.8);
//		System.out.println(detersivo.toString());
//		System.out.println(dentifricio.toString());
//		System.out.println(cestoBanane.toString());
//		System.out.println(noci.toString());

		// lista prodotti supermercato
		ArrayList<Item> supermarketItemsList = new ArrayList<>();
		supermarketItemsList.add(detersivo);
		supermarketItemsList.add(dentifricio);
		supermarketItemsList.add(cestoBanane);
		supermarketItemsList.add(noci);
		supermarketItemsList.add(mele);
		
//		printItems(supermarketItemsList);   // sfrutto wildcard
		
		// Supermarket supermarket = new Supermarket(); // non si può
		Supermarket supermarket = newSupermarket(supermarketItemsList); // creazione solo su richiesta		
//		supermarket.removeItem(mele);   // rimuovo prodotto dalla lista dei prodotti
//		printItems(supermarketItemsList); 
		
		List<ItemSoldInPieces> itemsSoldInPieces = new ArrayList<>();
		itemsSoldInPieces.add(detersivo);
		itemsSoldInPieces.add(dentifricio);
//		printItems(itemsSoldInPieces);
		
		List<ItemSoldInWeight> itemsSoldInWeight = new ArrayList<>();
		itemsSoldInWeight.add(cestoBanane);
		itemsSoldInWeight.add(noci);
//		printItems(itemsSoldInWeight);
		
		// array di prodotti riordinati
		Item[] itemsArray = new Item[3]; 
		itemsArray[0] = dentifricio;
		itemsArray[1] = noci;
		itemsArray[2] = detersivo;
//		printArrayItems(itemsArray);
		Item.orderListByPrice(itemsArray);
//		System.out.println("----------");
//		printArrayItems(itemsArray);
		
		Item[] itemsSoldInPiecesArray = new ItemSoldInPieces[2]; 
		itemsSoldInPiecesArray[0] = dentifricio;
		itemsSoldInPiecesArray[1] = detersivo;
//		printArrayItems(itemsSoldInPiecesArray);
		Item.orderListByPrice(itemsSoldInPiecesArray);
//		System.out.println("----------");
//		printArrayItems(itemsSoldInPiecesArray);
		
		Item[] itemsSoldInWeightArray = new ItemSoldInWeight[2]; 
		itemsSoldInWeightArray[0] = noci;
		itemsSoldInWeightArray[1] = cestoBanane;
//		printArrayItems(itemsSoldInWeightArray);
		Item.orderListByPrice(itemsSoldInWeightArray);
//		System.out.println("----------");
//		printArrayItems(itemsSoldInWeightArray);
		
		// nuovo carrello
		Cart cartFidelity = new Cart(true);
		Cart cartNotFidelity = new Cart(false);
		
		// rimepio carrello
		cartFidelity.addItems(detersivo);
		cartFidelity.addItems(cestoBanane);
		cartNotFidelity.addItems(detersivo, cestoBanane);   // varargs
		
		// stampo contenuto carrello
//		cartFidelity.printCart();
//		cartFidelity.removeItem(detersivo);
//		cartFidelity.printCart();
		
		// stampo conto carrello
//		System.out.println("cliente fedele: " + getBill(cartFidelity));
//		System.out.println("cliente non fedele: " + getBill(cartFidelity));
		
		// elimino prodotto
//		mele.deleteItem();
		
		// facade: aggiungo dentifricio in regalo con detersivo senza esporre giftItem
//		detersivo.addGiftItem(dentifricio);
//		System.out.println(detersivo.toString());
		
	}
}





