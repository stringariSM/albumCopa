package albumCopaMundo;

public class ListaFigurinhas{
	private Figura primFigura;
	private Figura ultFigura;
	private String nome;
	private int num_elem=0;

	public ListaFigurinhas( String s ){     // Constroi o primeiro Figura da lista. Seta
		nome = s;                   // os dados e faz com que o Figura nao aponte
		primFigura = null;            // para nenhum outro Figura.
		ultFigura = null;
	}

	public ListaFigurinhas(){				// Constroi uma lista vazia com a palavra
		this( "ListaFigurinhas" );			// "Lista"
	}


	public void insereNoInicio( Figura atual ){
//    Figura atual;
		if( isEmpty() ){
//      atual = new Figura( item );
			primFigura = atual;
			ultFigura = atual;
		}
		else{
//   	  atual = new Figura( item );

			primFigura.setAnt( atual );
			atual.setProx( primFigura );
			primFigura = atual;
		}
		num_elem++;
	}

	public void insereNoFim( Figura atual ){
//    Figura atual;
		if( isEmpty() ){
//   	  atual = new Figura( item );
			primFigura = atual;
			ultFigura = atual;
		}
		else{
//   	  atual = new Figura( item );

			ultFigura.setProx( atual );
			atual.setAnt( ultFigura );
			ultFigura = atual;
		}
		num_elem++;
	}


	public String removeNoInicio()
			throws EmptyListException{

		String itemRemovido;

		if( isEmpty() )
			throw new EmptyListException( nome );

		itemRemovido = primFigura.getNumero(); // Recupera os dados

		if( primFigura.equals( ultFigura )){ // Se s�o iguais, s� existe um Figura
			primFigura = null;
			ultFigura = null;
		}
		else{

			Figura temp = primFigura;
			primFigura = primFigura.getProx();
			primFigura.setAnt(null);
			temp.setProx(null);
		}
		num_elem--;
		return itemRemovido;
	}

	public String removeNoFim()
			throws EmptyListException{

		String itemRemovido;

		if( isEmpty() )
			throw new EmptyListException( nome );

		itemRemovido = ultFigura.getNumero(); // Recupera os dados

		if( primFigura.equals( ultFigura ) ){
			primFigura = null;
			ultFigura = null;
		}
		else{
			Figura atual = ultFigura;			// Procura o pen�ltimo Figura
			atual = atual.getAnt();
			ultFigura = atual;

			atual.setProx( null );

		}
		num_elem--;
		return itemRemovido;
	}

//  public int removeNoMeio( int ind ){
//
//  	int item_Removido=0;
//  	Figura temp;
//  	int i=0;
//
//  	if(ind >= num_elem)
//  	  item_Removido = this.removeNoFim();
//  	else
//  	  if( (ind <= 0) && (num_elem >= 1)) // Retirar o primeiro elemento
//  	    item_Removido = this.removeNoInicio();
//
//  	  else{
//        temp = primFigura;
//		// descobre a posi��o onde deve ser removido
//	    while( (i < ind) && (temp != null) ){
//	      temp = temp.getProx();
//		  i++;
//		}
//
//
//  	  	temp.getAnt().setProx( temp.getProx() );
//
//  	  	if(temp != ultFigura)
//  	  	  temp.getProx().setAnt(temp.getAnt());
//  	  	else
//  	  	  temp.setProx(null);
//
//
//
//  	  }
//  	  num_elem--;
//  	  return item_Removido;
//  }


	public boolean isEmpty(){	// Testa se a lista est� vazia
		return primFigura == null;
	}

	public void print(){

		if( isEmpty() ){
			System.out.println(" A Lista "+ nome +" est� vazia" );
			return;
		}

		System.out.println("A Lista "+ nome + " est� constitu�da por: ");

		Figura atual = primFigura;

		while( atual != null ){
			System.out.println( atual.getNumero() );
			atual = atual.getProx();
		}
	}
}