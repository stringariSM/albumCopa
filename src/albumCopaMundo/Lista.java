package albumCopaMundo;

public class Lista{
  private Nodo primNodo;
  private Nodo ultNodo;
  private String nome;
  private int num_elem=0;
	
  public Lista( String s ){     // Constroi o primeiro nodo da lista. Seta 
    nome = s;                   // os dados e faz com que o nodo nao aponte  
	primNodo = null;            // para nenhum outro nodo.
	ultNodo = null;
  }
	
  public Lista(){				// Constroi uma lista vazia com a palavra
    this( "Lista" );			// "Lista"
  }
	

  public void insereNoInicio( Nodo atual ){
//    Nodo atual;
    if( isEmpty() ){
//      atual = new Nodo( item );
   	  primNodo = atual;
   	  ultNodo = atual;
   	}
   	else{
//   	  atual = new Nodo( item );
   	  	
   	  primNodo.setAnt( atual );
   	  atual.setProx( primNodo );
   	  primNodo = atual;	
   	}
   	num_elem++;
  }

  public void insereNoFim( Nodo atual ){
//    Nodo atual;
   	if( isEmpty() ){
//   	  atual = new Nodo( item );
   	  primNodo = atual;
   	  ultNodo = atual;
   	}
   	else{
//   	  atual = new Nodo( item );
   	  	
   	  ultNodo.setProx( atual );
   	  atual.setAnt( ultNodo );
   	  ultNodo = atual;   	  	
   	}
   	num_elem++;
  }


  public String removeNoInicio()
	       throws EmptyListException{
	       	
    String itemRemovido;
	    
	if( isEmpty() )
	  throw new EmptyListException( nome );
	    	
	itemRemovido = primNodo.getNome(); // Recupera os dados
	    
	if( primNodo.equals( ultNodo )){ // Se s�o iguais, s� existe um nodo
	  primNodo = null;
	  ultNodo = null;
	}
	else{

	  Nodo temp = primNodo;
	  primNodo = primNodo.getProx();
	  primNodo.setAnt(null);
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
	     
	itemRemovido = ultNodo.getNome(); // Recupera os dados
	    
	if( primNodo.equals( ultNodo ) ){
	  primNodo = null;
	  ultNodo = null;
	}
	else{
	  Nodo atual = ultNodo;			// Procura o pen�ltimo nodo
	  atual = atual.getAnt();
	  ultNodo = atual;
	  
	  atual.setProx( null );
	  
	}
	num_elem--;
	return itemRemovido;
  }

//  public int removeNoMeio( int ind ){
//
//  	int item_Removido=0;
//  	Nodo temp;
//  	int i=0;
//
//  	if(ind >= num_elem)
//  	  item_Removido = this.removeNoFim();
//  	else
//  	  if( (ind <= 0) && (num_elem >= 1)) // Retirar o primeiro elemento
//  	    item_Removido = this.removeNoInicio();
//
//  	  else{
//        temp = primNodo;
//		// descobre a posi��o onde deve ser removido
//	    while( (i < ind) && (temp != null) ){
//	      temp = temp.getProx();
//		  i++;
//		}
//
//
//  	  	temp.getAnt().setProx( temp.getProx() );
//
//  	  	if(temp != ultNodo)
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
	return primNodo == null;
  }
	
  public void print(){
		
    if( isEmpty() ){
	  System.out.println(" A Lista "+ nome +" est� vazia" );
	  return;
    }
		
	System.out.println("A Lista "+ nome + " est� constitu�da por: ");
		
	Nodo atual = primNodo;
		
	while( atual != null ){
	  System.out.println( atual.getNome() );
	  atual = atual.getProx();
	}
  }
}