package progettoJava;

public abstract class Item implements Visitable, Comparable<Item>{
	String name;
	private Double unitPrice;
	
	public Double getUnitPrice() {
		return unitPrice;
	}

	// final method, non può essere fatto override
	final public void setUnitPrice(Double unitPrice) {
		this.unitPrice = unitPrice;
	}

	@Override
	public int compareTo(Item item) {
		return this.unitPrice.compareTo(item.unitPrice);
	}
	
	// superbinding
	public static <T extends Comparable<? super T>> void orderListByPrice(T[] itemsList) {
		for (int i = 0; i < itemsList.length; i++) {
			boolean flag = false;
			for (int j = 0; j < itemsList.length - 1; j++) {
				if (itemsList[j].compareTo(itemsList[j + 1]) > 0) {
					Object temp = itemsList[j];
					itemsList[j] = itemsList[j + 1];
					itemsList[j + 1] = (T) temp;      // cast esplicito
					flag = true;
				}
			}
			if (!flag)
				break;
		}
	}
	
	@Override
	public String toString() {
		return this.name + ", " + "prezzo/unità: " + this.unitPrice + "€";
	}
	
	public void deleteItem() throws Throwable {
		this.finalize();   // distruttore del garbage collectors
		System.out.println(this.name + " eliminato");
	}
}

class ItemSoldInPieces extends Item implements Visitable{
	int numberOfPieces;
	private Item giftItem = null;
	
	public ItemSoldInPieces() {}
	
	public ItemSoldInPieces(String name, Double unitPrice, int numberOfPieces) {
		this.name = name;
		this.setUnitPrice(unitPrice);
		this.numberOfPieces = numberOfPieces;
	}
	
	// facade
	public <T extends Item> void addGiftItem(T giftItem) {
		this.giftItem = giftItem;
		System.out.println(giftItem.name + " aggiunto in regalo con " + this.name);
	}
	
	@Override
	public Double accept(Visitor visitor) {
		return visitor.visit(this);
	}
	
	// overload
	public boolean equals(ItemSoldInPieces item) {
		if(this.name == item.name && this.numberOfPieces == item.numberOfPieces
				&& this.getUnitPrice() == item.getUnitPrice())
			return true;
		return false;
	}
	
	@Override  // uso di super
	public String toString() {
		return super.toString() + ", " + "pezzi: " + numberOfPieces 
				+ " con in regalo: " + giftItem.name;
	}
	
}

class  ItemSoldInWeight extends Item implements Visitable{
	Double weight;

	public ItemSoldInWeight() {}
	
	public ItemSoldInWeight(String name, Double unitPrice, Double weight) {
		this.name = name;
		this.setUnitPrice(unitPrice);
		this.weight = weight;
	}
	
	@Override
	public Double accept(Visitor visitor) {
		return visitor.visit(this);
	}
	
	// overload
	public boolean equals(ItemSoldInWeight item) {
		if(this.name == item.name && this.weight == item.weight
				&& this.getUnitPrice() == item.getUnitPrice())
			return true;
		return false;
	}
	
	@Override   // uso di super
	public String toString() {
		return super.toString() + ", " + "pezzi: " + this.weight;
	}
}

