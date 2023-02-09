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
}

class ItemSoldInPieces extends Item implements Visitable{
	int numberOfPieces;
	
	public ItemSoldInPieces() {}
	
	public ItemSoldInPieces(String name, Double unitPrice, int numberOfPieces) {
		this.name = name;
		this.setUnitPrice(unitPrice);
		this.numberOfPieces = numberOfPieces;
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
	
}

