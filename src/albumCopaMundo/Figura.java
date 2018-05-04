package albumCopaMundo;

public class Figura{
	private Figura ant;
	private String numero;
	private String qtd;
	private Figura prox;

	Figura(){  // Construtor que referencia o objeto obj
	  ant = null;
	  prox = null;
	}
	
	public Figura getAnt(){
		return ant;
	}
	public void setAnt(Figura ant){
		this.ant=ant;
	}
	public Figura getProx(){
		return prox;
	}
	public void setProx(Figura prox){
		this.prox=prox;
	}
	
	public String getNumero(){
		return numero;
	}
	public void setNumero(String dado){
		this.numero = dado;
	}

	public String getQuantidade(){
		return qtd;
	}
	public void setQuantidade(String dado){
		this.qtd = dado;
	}
}