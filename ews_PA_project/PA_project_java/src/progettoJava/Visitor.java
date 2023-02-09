package progettoJava;

public interface Visitor {
	double visit(ItemSoldInPieces item);
	double visit(ItemSoldInWeight item);
}
