package albumCopaMundo;

public class EmptyListException extends RuntimeException{
	
	public EmptyListException( String name ){
	
		super("A Lista"+ name +" est� vazia ");
	
	}
}