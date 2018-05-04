package albumCopaMundo;

public class Nodo{
	private Nodo ant;
	private String nome;
	private String telefone;
	private ListaFigurinhas listaFigurinhas;
	private Nodo prox;
	
	Nodo(){  // Construtor que referencia o objeto obj
	  ant = null;
	  prox = null;
	}
	
	public Nodo getAnt(){
		return ant;
	}
	public void setAnt(Nodo ant){
		this.ant=ant;
	}
	public Nodo getProx(){
		return prox;
	}
	public void setProx(Nodo prox){
		this.prox=prox;
	}
	
	public String getNome(){
		return nome;
	}
	public void setNome(String dado){
		this.nome = dado;
	}

	public String getTelefone(){
		return telefone;
	}
	public void setTelefone(String dado){
		this.telefone = dado;
	}

	public ListaFigurinhas getListaFigurinhas(){
		return listaFigurinhas;
	}
	public void setListaFigurinhas(ListaFigurinhas dado){
		this.listaFigurinhas = dado;
	}
}